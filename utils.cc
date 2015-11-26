#include<unistd.h>
#include<sys/time.h>
#include<stdio.h>
#include<time.h>
#include "utils.h"

namespace ustc_beyond {
namespace tril {

std::string GetCurrentFormatTime() {
    struct timeval tv;
    char buf[64];

    gettimeofday(&tv,NULL);
    size_t off = strftime(buf,sizeof(buf),"%d %b %H:%M:%S.",localtime(&tv.tv_sec));
    snprintf(buf+off,sizeof(buf)-off,"%03d",(int)tv.tv_usec/1000);
    return std::string(buf);

}

uint64_t GetCurrentMilisec() {
    time_t sec;
    uint64_t msec;
    uint64_t current_msec_;
    struct timeval tv;

    gettimeofday(&tv, NULL);

    sec = tv.tv_sec;
    msec = tv.tv_usec / 1000;

    current_msec_ = sec * 1000 + msec;
    return current_msec_;
}

}
}


