//
//  testC.c
//  ffmpegStudy
//
//  Created by 丰荣成 on 2021/4/16.
//

#include "testC.h"


void callCLog(){
    
    
    //==== 音频采集 ====
    //一、打开设备
    
    int ret=0;
    //接收错误信息
    char errors[1024];
    //上下文
    AVFormatContext * fmt_ctx=NULL;
    //[[video device]:[audio device]]
    char * devicename =":0";
    //编码参数
    AVDictionary *options=NULL;
    
    
    //1. 注册设备
    avdevice_register_all();
    //2. 设置采集方式 avfoundation/dshow/alsa   mac 下是 avfoundation
    AVInputFormat* inputFormat = av_find_input_format("avfoundation");
    //3. 打开音频设备
    ret=avformat_open_input(&fmt_ctx,devicename,inputFormat, &options);
    //打开设备返回值，<0失败。
    if(ret<0){
        printf("failure");
        av_strerror(ret, errors, 1024);
        printf(stderr,"Failed to open audio device ,[%d]%s\n)",ret,errors);
        return;
    }
            
    //采集数据
    //二、读取音频数据

    //av_read_frame 返回0说明成功
    AVPacket pkt;
    av_init_packet(&pkt);
    int count=0;
    while((ret=av_read_frame(fmt_ctx, &pkt) &&
           count++ <500)==0){
        printf("pkt siz size %d\n",pkt.size);
        //释放
        av_packet_unref(&pkt);
    }

    //释放
    avformat_close_input(&fmt_ctx);
    
    //输出到文件中
    
    
    
    
    
    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL,AV_LOG_DEBUG,"===> enter ffmpeg <===");
    
    return;
}
