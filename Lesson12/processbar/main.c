#include "process.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
double total = 1024.0;
double speed = 1.0;


typedef void(*callback_t)(double,double);


double SpeedFloat(double start, double range){
    int int_range = (int)range;
    return start + rand()%int_range + (range - int_range);
}

void Download(double total, callback_t cb){
    srand(time(NULL));
    double cur = 0.0;
    while(1){
        if(cur > total){
            cur = total;
            cb(total,cur);
            break;
        }
        cb(total,cur);
        cur += SpeedFloat(speed,5.0);
        usleep(3000);
    }
}

//void Download(){
//    double cur = 0;
//    while(cur <= total){
//        Flushprocess(total,cur);
//        usleep(3000);
//        cur +=speed;
//    }
//
//}

int main(){

    //Process();
    printf("Download 20.0MB\n");
    Download(20.0,Flushprocess);
    printf("Download 100.0MB\n");
    Download(100.0,Flushprocess);
    printf("Download 20000.0MB\n");
    Download(20000.0,Flushprocess);

    return 0;
}
