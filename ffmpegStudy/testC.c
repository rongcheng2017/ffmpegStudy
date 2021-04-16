//
//  testC.c
//  ffmpegStudy
//
//  Created by 丰荣成 on 2021/4/16.
//

#include "testC.h"


void rec_audio(){
    
    av_log_set_level(AV_LOG_DEBUG);
    //==== 音频采集 ====
    
    int ret=0;
    //接收错误信息
    char errors[1024]={0};
    //上下文
    AVFormatContext * fmt_ctx=NULL;
    //[[video device]:[audio device]]
    char * devicename =":0";
    //编码参数
    AVDictionary *options=NULL;
    
    //av_read_frame 返回0说明成功
    AVPacket pkt;
    av_init_packet(&pkt);
    int count=0;
    
    //一、打开设备
    //1. 注册设备
    avdevice_register_all();
    //2. 设置采集方式 avfoundation/dshow/alsa   mac 下是 avfoundation
    AVInputFormat* inputFormat = av_find_input_format("avfoundation");
    //3. 打开音频设备
    ret=avformat_open_input(&fmt_ctx,devicename,inputFormat, &options);
    //打开设备返回值，<0失败。
    if(ret<0){
        av_strerror(ret, errors, 1024);
        printf(stderr,"Failed to open audio device ,[%d]%s\n)",ret,errors);
        return;
    }
            
    //采集数据
    //二、读取音频数据
    while((ret=av_read_frame(fmt_ctx, &pkt) &&
           count++ <500)==0){
        av_log(NULL,AV_LOG_INFO,"pkt siz size %d\n",pkt.size);
        //释放
        av_packet_unref(&pkt);
    }

    //关闭 释放
    avformat_close_input(&fmt_ctx);
   
  
    av_log(NULL,AV_LOG_DEBUG,"===>  ffmpeg end <===");
    
    return;
}
