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
    printf("Panel initalized\n");
    
    int action = 0, timer_length = 0;

    while(1) {
    
        printf(" START button press  ..... -> 1\n");
         printf(" STOP  button press  ..... -> 2\n");
         printf(" TIMER seconds input  .... -> 3\n");

         scanf ("%d", &action);

         if( action == 1) {
            digitalWrite(START_STOP, ON); 
         } else if(action == 2) {
            digitalWrite(START_STOP, OFF);
         } else if(action == 3) {
           printf("Enter timer length: ");
           scanf("%d", &timer_length);
           
           if(timer_length < 1) {
                printf("Timer length must be at greater than zero\n");
                continue;
           }
           
           digitalWrite(TIMER, timer_length);          
           
           //for(i = 0; i < 100000000; i++); 
        }
    }
    return 0;
}
