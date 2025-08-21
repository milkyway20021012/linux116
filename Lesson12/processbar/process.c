#include "process.h"
#include <string.h>
#include <unistd.h>

#define SIZE 101
#define STYLE '='

// version1
//void Process(){
//    char buffer[NUM];
//    memset(buffer,'\0',sizeof(buffer));
//    const char* label = "|/-\\";
//    int len = strlen(label);
//    int cnt = 0;
//    while(cnt <= 100){
//        printf("[%-100s][%d%%][%c]\r",buffer,cnt,label[cnt%len]);
//        fflush(stdout);
//        buffer[cnt] = STYLE;
//        cnt++;
//        usleep(50000);
//    }
//    printf("\n");
//}


// version2
// refresh processbar on the basis of download progress

void Flushprocess(double total, double cur){
    if(cur > total){
        cur = total;
    }
    double rate = cur / total * 100; // 1024.0 512.0  512.0/1024.0 = 0.5 -> 50.0
    int cnt = (int)rate;
    char buf[SIZE];
    memset(buf,'\0',sizeof(buf));
    static const char* label = "|/-\\";
    static int index = 0;
    int len = strlen(label);
    int i = 0;
    for(;i<cnt;++i){
        buf[i] = STYLE;
    }
    // refresh
    
    printf("[%-100s][%.1lf%%][%c]\r",buf,rate,label[index++]);
    index %=  strlen(label);
    fflush(stdout);
    if(cur >= total){
        printf("\n");
    }


}
