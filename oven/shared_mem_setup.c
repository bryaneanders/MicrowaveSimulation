/* This file based on code by Kosuke Imamura
    at Eastern Washington University */

/* accessing shared memory */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
    key_t light_key, door_key, pad_key, emit_key, timer_key, timer_on_key, start_stop_key;
    int light_shmid, door_shmid, pad_shmid, emit_shmid, timer_shmid, timer_on_shmid, start_stop_shmid;
    int *light_data, *door_data, *pad_data, *emit_data, *timer_data, *timer_on_data, *start_stop_data;
    
    light_key = 0x10101aaa; printf("light_key=%x\n", light_key);
    door_key = 0x10101aab; printf("door_key=%x\n", door_key);
    pad_key = 0x10101aac; printf("pad_key=%x\n", pad_key);
    emit_key = 0x10101aad; printf("emit_key=%x\n", emit_key);
    timer_key = 0x10101aa0; printf("timer_key=%x\n", timer_key);
    timer_on_key = 0x10101aaf; printf("timer_on_key=%x\n", timer_on_key);
    start_stop_key = 0x010101ab0; printf("start_stop_key=%x\n", start_stop_key);

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
    if ((timer_on_shmid = shmget(timer_on_key, sizeof(int) * 2, IPC_CREAT|0666 )) == -1) 
    {   perror("timer on shmget error");
        exit(1);
    }
    if ((start_stop_shmid = shmget(start_stop_key, sizeof(int) * 2, IPC_CREAT|0666 )) == -1) 
    {   perror("start stop shmget error");
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
    
    start_stop_data = shmat(start_stop_shmid, 0, 0);
    if( start_stop_data == (int *)(-1) )
    { perror("start stop shmat error"); exit(1);
    }
    
    timer_on_data = shmat(timer_on_shmid, 0, 0);
    if( timer_on_data == (int *)(-1) )
    { perror("timer on shmat error"); exit(1);
    }


   /* detach shared memory for good */
   
    if (shmdt(light_data) == -1) 
    {    perror("light shmdt error"); exit(1);
    }
    
    if (shmdt(door_data) == -1) 
    {    perror("door shmdt error"); exit(1);
    }
    
    if (shmdt(pad_data) == -1) 
    {    perror("pad shmdt error"); exit(1);
    }
    
    if (shmdt(emit_data) == -1) 
    {    perror("emit shmdt error"); exit(1);
    }
    
    if (shmdt(timer_data) == -1) 
    {    perror("timer shmdt error"); exit(1);
    } 
    if (shmdt(start_stop_data) == -1) 
    {    perror("start stop shmdt error"); exit(1);
    }
    if (shmdt(timer_on_data) == -1) 
    {    perror("timer on shmdt error"); exit(1);
    }

   return 0;
}

