//
//  testC.c
//  ffmpegStudy
//
//  Created by 丰荣成 on 2021/4/16.
//

#include "testC.h"


void callCLog(){
    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL,AV_LOG_DEBUG,"===> enter ffmpeg <===");
    
    //音频采集
    //打开设备
    //打开设备返回值，<0失败。
    int ret;
    char errors[1024];
    AVFormatContext *fmt_ctx;
    //[[video device]:[audio device]]
    char * devicename =":0";
    //编码参数
    AVDictionary *options=NULL;
    //1. 注册设备
    avdevice_register_all();
    //2. 设置采集方式 avfoundation/dshow/alsa
    // mac 下是 avfoundation
    AVInputFormat* inputFormat = av_find_input_format("avfoundation");
    //3. 打开音频设备
    ret=avformat_open_input(&fmt_ctx,devicename , inputFormat, &options);
    if(ret<0){
        av_strerror(ret, errors, 1024);
        printf(stderr,"Failed to open audio device ,[%d]%s\n)",ret,errors);
    }
            
    //采集数据
    
    //输出到文件中
    
    
    
    
    
    return;
}
