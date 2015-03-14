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
    printf("Emit initalized\n");

	while(1) {
        if(digitalRead(EMIT) == ON) {
            printf("Emit is on!\n");
        } else {
            printf("Emit is off.\n");
        }
        
        // just to put a delay in
        int i;
        for(i = 0; i < 100000000; i++);
        
        //sleep(500);            
	}

	return(0);
}
