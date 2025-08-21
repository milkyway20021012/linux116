#include <stdio.h>
#include <unistd.h>
int main(){
    int cnt = 9;
    while(cnt>=0){
        printf("%d\r",cnt);
        fflush(stdout);
        sleep(1);
        cnt--;
    }
    printf("\n");
    return 0;
}
