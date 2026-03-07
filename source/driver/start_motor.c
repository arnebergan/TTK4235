#pragma once

#include "elevio.h"
#include "con_load.h"
#include "info_gathering.h"
#include "start_motor.h"
#include "start_sequence.h"
#include "stop_button.h"
#include "stop_routine.h"
#include "lights.h"


//Can make 2 functions check over and check under, if that improves readability

void drive_elevator(int *p_g_direction_priority, int *p_g_order_buttons, int *p_g_floor, int *p_g_motor_direction){
    if(*p_g_motor_direction==0 & *p_g_floor!=-1){    //need to fix start between floors
        if (*p_g_direction_priority){                  //priority upwards
            for(int i=((*p_g_floor)*3); i<12; i++){
                if (*(p_g_order_buttons+i)){
                    elevio_motorDirection(1);
                    *p_g_motor_direction=1;
                    *p_g_direction_priority=1;
                    break;
                }
            }
            for(int i=((*p_g_floor)*3); i>-1; i--){ 
                if (*(p_g_order_buttons+i)){
                    elevio_motorDirection(-1);
                    *p_g_motor_direction=-1;
                    *p_g_direction_priority=-1;
                    break;
                }
            }
        } else{                                         //priority downwards
            for(int i=((*p_g_floor)*3-1); i>-1; i--){
                if (*(p_g_order_buttons+i)){
                    elevio_motorDirection(-1);
                    *p_g_motor_direction=-1;
                    *p_g_direction_priority=-1;
                    break;
                }
            }
            for(int i=((*p_g_floor)*3-1); i<12; i++){
                if (*(p_g_order_buttons+i)){
                    elevio_motorDirection(1);
                    *p_g_motor_direction=1;
                    *p_g_direction_priority=1;
                    break;
                }
            }
        }
    }
}

void drive_after_stop(int *p_g_direction_priority, int *p_g_order_buttons, int *p_g_floor, int *p_g_motor_direction, int *p_g_last_floor){
    int floor =*p_g_last_floor+*p_g_direction_priority;
    int direction_offset= 0;
    if(*p_g_direction_priority==-1){
        direction_offset=3;
    }

    // if(floor<0){
    //     floor=0;
    // }
    // if(floor>3){
    //     floor=3;
    // }
    if(*p_g_motor_direction==0 & *p_g_floor==-1){   
        for(int i=0; i<(floor*3+direction_offset) ; i++){
            if (*(p_g_order_buttons+i)){
                    elevio_motorDirection(-1);
                    *p_g_motor_direction=-1;        //No direction priority to fix a stop after a stop before reaching a floor
                    break;
            }
        }
    }
    if(*p_g_motor_direction==0 & *p_g_floor==-1){
        for(int i=(floor*3+direction_offset); i<12 ; i++){
            if (*(p_g_order_buttons+i)){
                    elevio_motorDirection(1);
                    *p_g_motor_direction=1;
                    break;
            }
        } 
    }
}