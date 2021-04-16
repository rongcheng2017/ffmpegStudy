//
//  testC.c
//  ffmpegStudy
//
//  Created by 丰荣成 on 2021/4/16.
//

#include "testC.h"


void callCLog(){
    printf(" this is a log from c");
    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL,AV_LOG_DEBUG,"this is ffmpeg log");
    
    return;
}
