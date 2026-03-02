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


void stop_button(int *p_g_stop_button, int *p_g_motordirection, int *p_g_door_open, int *p_g_order_buttons, int *p_g_floor){
    if (*p_g_stop_button){
        *p_g_motordirection=0;
        elevio_motorDirection(0);
        if(*p_g_floor != -1){    //Need to find out the value of p_g_floor when between floor, visstnok -1
            *p_g_door_open=1;
        }
        for(int i=0; i<12; i++){
            *(p_g_order_buttons+i)=0;
        }
        //Function update lights
        while(*p_g_stop_button){
            check_stop_button(p_g_stop_button);
            nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
        }
        *p_g_door_open=0;
    }
}