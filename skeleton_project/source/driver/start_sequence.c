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


//initialisering
void start_sequence(int *floor_sensor){
    elevio_init();
    elevio_motorDirection(-1);
    while (*floor_sensor != 1){
        *floor_sensor = elevio_floorSensor();
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }
    elevio_motorDirection(0);
}
