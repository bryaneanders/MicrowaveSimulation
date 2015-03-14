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
    printf("Light initalized\n");

	while(1) {
        if(digitalRead(LIGHT) == ON) {
            printf("Light is on!\n");
        } else {
            printf("Light is off.\n");
        }
    
        // just to put a delay in
        int i;
        for(i = 0; i < 100000000; i++);
    
      //  sleep(500);
	}

	return(0);
}

