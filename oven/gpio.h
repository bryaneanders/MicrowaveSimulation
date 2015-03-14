/* This file based on code by Kosuke Imamura
    at Eastern Washington University */

/* accessing shared memory */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/*   #include "gpio.h"  */

  static int const START_STOP = 16;
  static int const LIGHT = 17;
  static int const DOOR = 18;
  static int const PAD = 19;
  static int const EMIT = 20;
  static int const TIMER = 21;
  static int const TIMER_ON = 22;

  static int const ON = 1;
  static int const OFF = 0;

    key_t light_key, door_key, pad_key, emit_key, timer_key, timer_on_key, start_stop_key;
    int light_shmid, door_shmid, pad_shmid, emit_shmid, timer_shmid, timer_on_shmid, start_stop_shmid;

    int mode;
    unsigned int i;

    int *light_data, *door_data, *pad_data, *emit_data, *timer_data, *timer_on_data, *start_stop_data;

void wiringPiSetUpGpio()
{
    light_key = 0x10101aaa; //printf("light_key=%x\n", light_key);
    door_key = 0x10101aab; //printf("door_key=%x\n", door_key);
    pad_key = 0x10101aac; //printf("pad_key=%x\n", pad_key);
    emit_key = 0x10101aad; //printf("emit_key=%x\n", emit_key);
    timer_key = 0x10101aa0; //printf("timer_key=%x\n", timer_key);
    timer_on_key = 0x10101aaf; //printf("timer_on_key=%x\n", timer_on_key);
    start_stop_key = 0x10101ab0; //printf("start stop key=%x\n", start_stop_key);

  /* get shared variable (mem segment) */
    if ((light_shmid = shmget(light_key, sizeof(int) * 2, IPC_CREAT|0666 )) == -1) 
    {   perror(" light shmget error");
        exit(1);
    }
    
    if ((door_shmid = shmget(door_key, sizeof(int) * 2, IPC_CREAT|0666 )) == -1) 
    {   perror("door shmget error");
        exit(1);
    }
    if ((pad_shmid = shmget(pad_key, sizeof(int) * 2, IPC_CREAT|0666 )) == -1) 
    {   perror("pad shmget error");
        exit(1);
    }
    if ((emit_shmid = shmget(emit_key, sizeof(int) * 2, IPC_CREAT|0666 )) == -1) 
    {   perror("emit shmget error");
        exit(1);
    }
    if ((timer_shmid = shmget(timer_key, sizeof(int) * 2, IPC_CREAT|0666 )) == -1) 
    {   perror("timer shmget error");
        exit(1);
    }
    if ((start_stop_shmid = shmget(start_stop_key, sizeof(int) * 2, IPC_CREAT|0666 )) == -1) 
    {   perror("start stop shmget error");
        exit(1);
    }
    
    if ((timer_on_shmid = shmget(timer_on_key, sizeof(int) * 2, IPC_CREAT|0666 )) == -1) 
    {   perror("timer on shmget error");
        exit(1);
    }

    /* attach to shared memory */
    light_data = shmat(light_shmid, 0, 0);
    if( light_data == (int *)(-1) )
    { perror("light shmat error"); exit(1);
    }
   
    door_data = shmat(door_shmid, 0, 0);
    if( door_data == (int *)(-1) )
    { perror("door shmat error"); exit(1);
    }
    
    pad_data = shmat(pad_shmid, 0, 0);
    if( pad_data == (int *)(-1) )
    { perror("pad shmat error"); exit(1);
    }

    emit_data = shmat(emit_shmid, 0, 0);
    if( emit_data == (int *)(-1) )
    { perror("emit shmat error"); exit(1);
    }
   
    timer_data = shmat(timer_shmid, 0, 0);
    if( timer_data == (int *)(-1) )
    { perror("timer shmat error"); exit(1);
    }

    timer_on_data = shmat(timer_on_shmid, 0, 0);
    if( timer_on_data == (int *)(-1) )
    { perror("time on shmat error"); exit(1);
    }

    start_stop_data = shmat(start_stop_shmid, 0, 0);
    if( start_stop_data == (int *)(-1) )
    { perror("start stop shmat error"); exit(1);
    }

   //printf("gpio initialized.\n");
}

int digitalRead(int pin)
{
   if(pin==LIGHT) return *light_data;
   else if(pin==DOOR) return *door_data;
   else if(pin==PAD) return *pad_data;
   else if(pin==EMIT) return *emit_data;
   else if(pin==TIMER) return *timer_data;
   else if(pin==TIMER_ON) return *timer_on_data;
   else if(pin==START_STOP) return *start_stop_data;
    
   else {
        printf("error digitalRead, bad pin number: %d.\n", pin);
        return 0;
    }
}

void digitalWrite(int pin, int val)
{
   if(pin==LIGHT) {
       *light_data = val; 
       printf("digiwrite light = %d\n", val);
   }
   else if(pin==DOOR) {
       *door_data = val;
       printf("digiwrite door = %d\n", val);
   }
   else if(pin==PAD) {
       *pad_data = val;
       printf("digiwrite pad = %d\n", val);
   }
   else if(pin==EMIT) {
       *emit_data = val;
       printf("digiwrite emit = %d\n", val);
   }
   else if(pin==TIMER) { 
       *timer_data = val;
       printf("digiwrite timer = %d\n", val);
   }       
   else if(pin==TIMER_ON) {
       *timer_on_data = val;
       printf("digiwrite timer on = %d\n", val);
   }
   else if(pin==START_STOP) {
       *start_stop_data = val;
       printf("digiwrite start stop = %d\n", val);
   }
    
   else printf("error digitalWrite, bad pin number: %d.\n", pin);
}

void  pullUpDnControl (int pin, int pud)
{
    
}

