#pragma once

#include "start_sequence.h"
#include "elevio.h"
#include "con_load.h"

void stop_routine(int *g_floor, int *g_motordirection, int *g_order_buttons, int *g_obstuction){
    if (*(g_order_buttons+(*g_floor*3-1)) || (*(g_order_buttons+(*g_floor*3-2))==*g_motordirection) || (*(g_order_buttons+(*g_floor*3-3))==-*g_motordirection)){
        *g_motordirection=0;
        elevio_motorDirection(0);
        elevio_doorOpenLamp(1);
        usleep(1000000); //pauses one second, not how its gonna be implemented
        while(*g_obstuction){
            usleep(10000);
        }
        for(int i=0; i<3; i++){  //Sets order buttons for current floor equal to 0
            *(g_order_buttons+(*g_floor*3-3)+i)=0;
        }
        elevio_doorOpenLamp(0);
    };
};
