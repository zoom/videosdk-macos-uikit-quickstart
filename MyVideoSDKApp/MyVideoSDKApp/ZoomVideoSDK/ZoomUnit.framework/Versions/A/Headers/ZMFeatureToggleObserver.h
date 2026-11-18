//
//  ZMFeatureToggleObserver.h
//  ZoomUnit
//
//  Copyright © 2026 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

//How a -waitUntilReady request was resolved. The first three all mean "the value you are
//about to read is what the server sent"; only the last one means the data may be stale.
typedef NS_ENUM(NSInteger, ZMFeatureToggleReadyResult) {
    //The toggle already carried a server-pushed value when the request was made,
    //so nothing was waited for.
    ZMFeatureToggleReadyResultAlreadyReady = 0,
    //The sync finished while waiting and did push this toggle.
    ZMFeatureToggleReadyResultNotified,
    //The sync finished (or had already finished) but never pushed this toggle, so reading
    //it yields the local default rather than a server value. Waiting longer would not
    //help: nothing more is coming for this login.
    ZMFeatureToggleReadyResultSyncedButMissing,
    //maxWaitInterval elapsed without the sync completing.
    ZMFeatureToggleReadyResultTimedOut,
};

#ifdef __cplusplus
#include "cmmlib/CmmSettingTransfer.h"

//Resolves a completion once it is safe to read a given feature toggle.
//
//Feature-toggle data is pushed once per login: PT's web service stores the values and
//only then broadcasts MSG_FEATURE_TOGGLE_DATA_UPDATED / "featureToggleUpdateDone".
//A caller that starts observing after that broadcast would wait forever, so this class
//probes whether the value has already landed and registers an observer only when it
//has not -- and gives up after maxWaitInterval either way. The three outcomes are
//reported separately so callers can tell trustworthy data from a timeout.
//
//PT process only: readiness is probed through IPTAccountService, which owns the values
//in the PT process. Anywhere else the probe simply fails and requests resolve as
//ZMFeatureToggleReadyResultTimedOut.
//
//Threading: create, use and destroy this on the main thread. Completions are always
//delivered asynchronously on the main thread, however the request resolved.
//
//Destruction releases everything immediately: it unregisters the setting observer,
//cancels every scheduled timeout and drops the pending completions, so nothing is kept
//alive waiting for a timer that will never matter.
@class ZMFeatureToggleObserverCallbackTarget;
@class ZMFeatureToggleReadyRequest;

class ZMFeatureToggleObserver : public zstref::ISettingTransferObserver
{
public:
    //maxWaitInterval caps how long a request waits before it resolves as
    //ZMFeatureToggleReadyResultTimedOut. Negative values are clamped to 0.
    explicit ZMFeatureToggleObserver(NSTimeInterval maxWaitInterval);
    ~ZMFeatureToggleObserver();

    //toggleName and service together identify the toggle, matching
    //IPTAccountService::GetFeatureToggleValues (e.g. "enable_pt_whiteboard_cef" / "web").
    void waitUntilReady(const Cmm::CAString& toggleName,
                        const Cmm::CAString& service,
                        void (^completion)(ZMFeatureToggleReadyResult result));

    virtual CmmBool InterestedIn(zstref::MessageType message) override;
    virtual void OnTransferSettingUpdated(zpref::zPolicyScene scene, CmmUInt32 message_type, const Cmm::CAString& key) override;

    //Implementation details. Public only so the callback target can forward into them;
    //callers should not use these.
    void handleTimeout(ZMFeatureToggleReadyRequest* request);
    void handleSyncDone();

private:
    void registerObserverIfNeeded();
    void unregisterObserverIfNeeded();

    NSTimeInterval _maxWaitInterval;
    bool _syncDone;
    bool _registered;
    //Sole strong owner of the pending requests, so clearing it frees them immediately.
    //Each one remembers its own toggle, which is what lets the sync tell "pushed" from
    //"not pushed" per request rather than lumping them together.
    NSMutableArray<ZMFeatureToggleReadyRequest *> *_pendingRequests;
    //The ObjC receiver every delayed / main-thread callback is sent to, since a C++ class
    //cannot be one. Its back-pointer is cleared on destruction, so anything still queued
    //turns into a no-op.
    ZMFeatureToggleObserverCallbackTarget *_callbackTarget;
};

#endif //__cplusplus
