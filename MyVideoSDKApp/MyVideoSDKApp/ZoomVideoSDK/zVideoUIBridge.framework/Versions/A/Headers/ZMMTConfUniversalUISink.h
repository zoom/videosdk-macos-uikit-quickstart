//
//  ZMMTConfUniversalUISink.h
//  VideoUIBridge
//
//  Created by Davies Zhao on 2026/1/27.
//

#import <zVideoUIBridge/ZMConfBaseSinkAdapter.h>
#import <zm_conf_universal_ui/zm_conf_universal_ui_interface.h>

class ZMMTConfUniversalUISink : public NS_ZM_CONF_UNIVERSAL_UI::IZmConfUniversalUiSink {
    
public:
    ZMMTConfUniversalUISink(ZMConfBaseSinkAdapter *adapter);
    virtual ~ZMMTConfUniversalUISink();
    
public:
    virtual void OnModuleAfterCreated(NS_ZM_CONF_UNIVERSAL_UI::UuiModuleName module_name);
    virtual void OnModuleBeforeDestroyed(NS_ZM_CONF_UNIVERSAL_UI::UuiModuleName module_name);
    
private:
    ZMConfBaseSinkAdapter *_sinkAdapter;
};
