#pragma once

#include "elevio.h"
#include "con_load.h"

//initialisering
elevio_init()
int g_stop_buttoninit= 0;
int g_floor_sensorinit = elevio_floorSensor();
int g_obstructioninit = 0;
int g_order_buttons[12] = {0};

int *p_g_stop_buttons = &g_stop_buttoninit
int *p_g_floor_sensorinit = &g_floor_sensorinit
int *p_g_obstructioninit = &g_obstructioninit
int *g_order_buttons = &g_order_buttons



elevio_motorDirection(-1);
while current_floor != 1{
    current_floor = elevio_floorSensor()
}
elevio_motorDirection(0);



//Main program
while (1){
    info_gathering()
    if stop_button(){
        while
    }
}