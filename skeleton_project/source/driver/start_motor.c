#pragma once

#include "elevio.h"
#include "con_load.h"
#include "info_gathering.h"
#include "start_motor.h"
#include "start_sequence.h"
#include "stop_button.h"
#include "stop_routine.h"

//Can make 2 functions check over and check under, if that improves readability

void drive_elevator(int *p_g_direction_piority, int *p_g_order_buttons, int *p_g_floor, int *g_motor_direction, int *p_g_motor_direction){
    if(*p_g_motor_direction==0){
        if (*p_g_direction_piority){                  //priority upwards
            for(int i=((*p_g_floor)*3); i<12; i++){
                if (*(p_g_order_buttons+i)){
                    elevio_motorDirection(1);
                    *p_g_motor_direction=1;
                    *p_g_direction_piority=1;
                    break;
                }
            }
            for(int i=((*p_g_floor)*3-4); i<-1; i--){ 
                if (*(p_g_order_buttons+i)){
                    elevio_motorDirection(0);
                    *p_g_motor_direction=0;
                    *p_g_direction_piority=0;
                    break;
                }
            }
        } else{                                         //priority downwards
            for(int i=((*p_g_floor)*3-4); i<-1; i--){
                if (*(p_g_order_buttons+i)){
                    elevio_motorDirection(0);
                    *p_g_motor_direction=0;
                    *p_g_direction_piority=0;
                    break;
                }
            }
            for(int i=((*p_g_floor)*3); i<12; i++){
                if (*(p_g_order_buttons+i)){
                    elevio_motorDirection(1);
                    *p_g_motor_direction=1;
                    *p_g_direction_piority=1;
                    break;
                }
            }
        }
    }
}