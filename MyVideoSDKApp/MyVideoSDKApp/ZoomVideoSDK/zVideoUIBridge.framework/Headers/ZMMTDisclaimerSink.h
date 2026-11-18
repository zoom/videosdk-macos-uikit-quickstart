//
//  ZMMTDisclaimerSink.h
//  VideoUIBridge
//
//  Created by Carol Li on 2026/4/9.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMConfBaseSinkAdapter.h>
#import <zm_conf_universal_ui/disclaimer/zm_conf_uui_disclaimer_api.h>

class ZMMTDisclaimerSink : public NS_ZM_CONF_UNIVERSAL_UI::IUuiDisclaimerApiSink,
                           public NS_ZM_CONF_UNIVERSAL_UI::IUuiCustomDisclaimerApiSink {

public:
    ZMMTDisclaimerSink(ZMConfBaseSinkAdapter *adapter);
    virtual ~ZMMTDisclaimerSink();

public:
    // IUuiDisclaimerApiSink
    virtual NS_ZM_CONF_UNIVERSAL_UI::IUuiCustomDisclaimerApiSink* GetCustomDisclaimerSink() override { return this; }

    // IUuiCustomDisclaimerApiSink
    virtual void ShowConsolidatedCustomDisclaimer() override;
    virtual void UpdateConsolidatedCustomDisclaimer(const NS_ZM_CONF_UNIVERSAL_UI::UuiConsolidatedDisclaimerUpdateParam& param) override;
    virtual void CloseConsolidatedCustomDisclaimer() override;
    virtual void ShowConsolidatedDisclaimerCenterAndTop() override;
    virtual void GetConsolidatedDisclaimerPosParam(NS_ZM_CONF_UNIVERSAL_UI::UuiDisclaimerPosParam& param) override;
    virtual void LeaveMeeting() override;

private:
    ZMConfBaseSinkAdapter *_sinkAdapter;
};
