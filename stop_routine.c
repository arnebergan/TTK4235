#pragma once

#include <time.h>


#include "elevio.h"
#include "con_load.h"
#include "info_gathering.h"
#include "start_motor.h"
#include "start_sequence.h"
#include "stop_button.h"
#include "stop_routine.h"
#include "lights.h"


void stop_routine(int *p_g_floor, int *p_g_motor_direction, int *p_g_order_buttons, int *p_g_obstruction){
    if(*p_g_floor!=-1){    
        if (*(p_g_order_buttons+(*p_g_floor*3)) || (*(p_g_order_buttons+(*p_g_floor*3+2))==*p_g_motor_direction) 
        || (*(p_g_order_buttons+(*p_g_floor*3+1))==-*p_g_motor_direction)){
            *p_g_motor_direction=0;
            elevio_motorDirection(0);
            elevio_doorOpenLamp(1);
            nanosleep(&(struct timespec){0, 1000*1000*1000}, NULL); //Pauses 1 second
            while(*p_g_obstruction){
                 nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
                //sjekk obstruction
            }
            for(int i=0; i<3; i++){  //Sets order buttons for current floor equal to 0
                *(p_g_order_buttons+(*p_g_floor*3-3)+i)=0;
            }
            elevio_doorOpenLamp(0);
        };
    };
};
