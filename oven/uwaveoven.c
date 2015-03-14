/* Each class is run in a seperate window and uses shared memory to communicate
 *
 * Need to hook up all the GPIO stuff and learn to allocate shm memory
 * 
 * Can make a test routine to catch setups we don't want
 *
 *
 * ipcs command shows shared memory
 */



/*******************************/
/*   sim oven hardware         */
/*******************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "gpio.h"

int main() {
    wiringPiSetUpGpio();
    
    int microwaveOn = 0;
    int door, timer, start_stop;    
        
    while(1) {
        door = digitalRead(DOOR);
        timer = digitalRead(TIMER);
        start_stop = digitalRead(START_STOP);
                
        // run the microwave
        if(door == OFF && timer > 0 && start_stop == ON && !microwaveOn) 
        {
            digitalWrite(TIMER_ON, ON);
            digitalWrite(LIGHT, ON);
            digitalWrite(EMIT, ON);
            microwaveOn = 1;
            
            printf("Microwave on\n");
        } else if(microwaveOn && (door == ON || timer < 1 || start_stop == OFF)) {
            digitalWrite(TIMER_ON, OFF);
            digitalWrite(EMIT, OFF);
            microwaveOn = 0;
            
            printf("Microwave off\n");
        } else if( door == ON && !microwaveOn){
            digitalWrite(LIGHT, ON);
        } else if(digitalRead(DOOR) == OFF && !microwaveOn) {
            digitalWrite(LIGHT, OFF);
        }        
        
        // turn off the microwave when it runs out of running time
        if(start_stop == ON && timer < 1) {
            difitalSrite(START_STOP, OFF);
        }
        
        // just to put a delay in
        int i;
        for(i = 0; i < 100000000; i++);
        
       // sleep(500);
    }    
}


