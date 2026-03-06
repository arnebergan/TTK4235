#pragma once

#include "elevio.h"
#include "con_load.h"
#include "info_gathering.h"
#include "start_motor.h"
#include "start_sequence.h"
#include "stop_button.h"
#include "stop_routine.h"
#include "lights.h"


void stop_button_light(int *p_g_stop_button){
    elevio_stopLamp(*p_g_stop_button);
}

void order_button_lights(int *p_g_order_buttons){
    for(int i=0; i<12; i++){
        if(i==1 || i==9){
            continue;
        }
        int floor=((i/3));        //Heiltalsdivisjon
        int button_type= (i%3);
        elevio_buttonLamp(floor, button_type, *(p_g_order_buttons+i));
    }
}

void floor_light(int *p_g_floor){
    if(*p_g_floor!=-1){
        elevio_floorIndicator(*p_g_floor);
        }
    }

void set_lights(int *p_g_stop_button, int *p_g_order_buttons, int *p_g_floor){
    stop_button_light(p_g_stop_button);
    order_button_lights(p_g_order_buttons);
    floor_light(p_g_floor);
}