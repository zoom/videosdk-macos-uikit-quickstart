//
//  ZMMTDisclaimerStringSink.h
//  VideoUIBridge
//
//  Created by Carol Li on 2026/4/9.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMConfBaseSinkAdapter.h>
#import <zm_conf_universal_ui/zm_conf_uui_string_interface.h>

class ZMMTDisclaimerStringSink : public NS_ZM_CONF_UNIVERSAL_UI::IUuiStringApiSink {

public:
    ZMMTDisclaimerStringSink(ZMConfBaseSinkAdapter *adapter);
    virtual ~ZMMTDisclaimerStringSink();

public:
    virtual void GetString(NS_ZM_CONF_UNIVERSAL_UI::UuiStringId id, OUT CString& string) override;

private:
    ZMConfBaseSinkAdapter *_sinkAdapter;
};
