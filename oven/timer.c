/*******************************/
/*   Panel                     */
/*******************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "gpio.h"

int main()
{
    wiringPiSetUpGpio();
    printf("Timer initalized\n");
        
    int timer;
    
    while(1) {
        timer = digitalRead(TIMER);
        printf("timer is %d\n", timer);
        
        if(timer > 0 && digitalRead(TIMER_ON) == ON) {
            digitalWrite(TIMER, --timer);
        }
                
        // just to put a delay in
        int i;
        for(i = 0; i < 500000000; i++);
        
       // sleep(1000);
    }    
}
