//
//  ZMPConfDataProtocol.h
//  ZCommonUI
//
//  Created by Justin Fang on 6/7/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "zoom_client_conf.h"
//#import "ZRBreakoutSessionInfo.h"


@protocol ZMPConfDataProtocol <NSObject>

//Zoom client interfaces:
typedef enum
{
    Evt_Conf_SubType_Font_Size_Changed,//ZOOM-20021
}EVENT_SUBTYPE_CONF;

typedef enum
{
    Evt_Meeting,
}EVENT_TYPE_CONF;

@end
