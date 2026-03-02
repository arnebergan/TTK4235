#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"



int main(){
    elevio_init();
    int g_stop_button= 0;
    int g_floor = elevio_floorSensor();
    int g_obstruction = 0;
    int g_order_buttons[12] = {0}; // Opp, Ned, Cab
    int g_queue[4]={0};
    int g_motor_direction = 0;
    int g_door_open = 0;
    int g_obstruction = 0;
    int g_direction_priority = 1;

    int *p_g_stop_button = &g_stop_button;
    int *p_g_floor = &g_floor;
    int *p_g_obstruction = &g_obstruction;
    int *p_g_order_buttons = &g_order_buttons;
    int *p_g_queue = &g_queue;
    int *p_g_motor_direction = &g_motor_direction;
    int *p_g_door_open = &g_door_open;
    int *p_g_obstruction = &g_obstruction;
    int *p_g_direction_priority = &g_direction_priority;
    start_sequence();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    elevio_motorDirection(DIRN_UP);

    while(1){
        int floor = elevio_floorSensor();

        if(floor == 0){
            elevio_motorDirection(DIRN_UP);
        }

        if(floor == N_FLOORS-1){
            elevio_motorDirection(DIRN_DOWN);
        }


        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
            }
        }

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
}
