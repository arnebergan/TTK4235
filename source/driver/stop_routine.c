#pragma once

#include <time.h>
#include <stdio.h>


#include "elevio.h"
#include "con_load.h"
#include "info_gathering.h"
#include "start_motor.h"
#include "start_sequence.h"
#include "stop_button.h"
#include "stop_routine.h"
#include "lights.h"


void stop_routine(int *p_g_floor, int *p_g_motordirection, int *p_g_order_buttons, int *p_g_obstruction, int*p_g_stop_button, int *p_g_last_floor, int* p_g_motor_direction, int *p_g_door_open){
    if(*p_g_floor!=-1 & *p_g_motordirection!=0){
        int no_orders_further =1;
        if(*p_g_motordirection==1){
            for(int i=((*p_g_floor)*3+3); i<12; i++){
                if (*(p_g_order_buttons+i)){
                    no_orders_further=0;                   
                }
            }
        }
        if(*p_g_motordirection==-1){
            for(int i=((*p_g_floor)*3-1); i>-1; i--){ 
                if (*(p_g_order_buttons+i)){
                    no_orders_further=0;
                }
            }
        }
        if (*(p_g_order_buttons+(*p_g_floor*3+2)) || (*(p_g_order_buttons+(*p_g_floor*3))==*p_g_motordirection) || (*(p_g_order_buttons+(*p_g_floor*3+1))==-*p_g_motordirection) || no_orders_further){
            *p_g_motordirection=0;
            elevio_motorDirection(0);
            elevio_doorOpenLamp(1);
            time_t start_timer = time(NULL);
            while ((time(NULL)-start_timer)<3){
                gather_info(p_g_stop_button, p_g_order_buttons, p_g_floor, p_g_last_floor);
                set_lights(p_g_stop_button, p_g_order_buttons, p_g_floor);
                stop_button(p_g_stop_button, p_g_motor_direction, p_g_door_open, p_g_order_buttons, p_g_floor, p_g_last_floor, p_g_obstruction);
                if (*p_g_stop_button){
                start_timer = time(NULL);
                }
            }
 
 
            *p_g_obstruction=elevio_obstruction();
            if (*p_g_obstruction){
                time_t obstruction_timer = time(NULL);
                while ((time(NULL)-obstruction_timer)<3){
                    gather_info(p_g_stop_button, p_g_order_buttons, p_g_floor, p_g_last_floor);
                    set_lights(p_g_stop_button, p_g_order_buttons, p_g_floor);
                    stop_button(p_g_stop_button, p_g_motor_direction, p_g_door_open, p_g_order_buttons, p_g_floor, p_g_last_floor, p_g_obstruction);
                    *p_g_obstruction=elevio_obstruction();
                    if (*p_g_obstruction){
                        obstruction_timer = time(NULL);
                    }
                }
            }
            for(int i=0; i<3; i++){  //Sets order buttons for current floor equal to 0
                *(p_g_order_buttons+(*p_g_floor*3)+i)=0;
            }
            elevio_doorOpenLamp(0);
        };
    };
};


