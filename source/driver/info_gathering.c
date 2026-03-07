#pragma once

#include <stdio.h>
#include "elevio.h"
#include "con_load.h"
#include "info_gathering.h"
#include "start_motor.h"
#include "start_sequence.h"
#include "stop_button.h"
#include "stop_routine.h"
#include "lights.h"

void check_stop_button(int *p_g_stop_button){
    *p_g_stop_button = elevio_stopButton();
}

void check_order_buttons(int *p_g_order_buttons){
    for(int i=0; i<12; i++){
        if(i==1 || i==9){
            continue;
        }
        int floor=((i/3));        //Heiltalsdivisjon
        int button_type= (i%3);
        if (*(p_g_order_buttons+i)==0){
            *(p_g_order_buttons+i)=elevio_callButton(floor, button_type);
        }
    }
}

void check_floor(int *p_g_floor, int *p_g_last_floor){
    *p_g_floor = (elevio_floorSensor());
    if(*p_g_floor!=-1){
        *p_g_last_floor = (elevio_floorSensor());
    }
}

void gather_info(int *p_g_stop_button, int *p_g_order_buttons, int *p_g_floor, int *p_g_last_floor){
    check_stop_button(p_g_stop_button);
    check_order_buttons(p_g_order_buttons);
    check_floor(p_g_floor, p_g_last_floor);
}