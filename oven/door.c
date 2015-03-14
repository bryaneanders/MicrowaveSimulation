// door.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "gpio.h"

int main() {
    int action;
    
    wiringPiSetUpGpio();
    printf("Door initalized\n");
    
	// user action
	while(1) {
        printf(" Open door   ----> 1\n");
        printf(" Close door ---> 0\n");
        scanf("%d", &action);
        
		// door is open
		if(action == ON) {
            // open the door
            digitalWrite(DOOR, ON);
            printf("Opening the door\n");
		} else if(action == OFF) {
            // close the door
            digitalWrite(DOOR, OFF);
            printf("Closing the door\n");
        } else {
            printf("Invalid input");
        }
        
      // sleep(500);
	}

	return 0;
}
