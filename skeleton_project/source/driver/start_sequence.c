#pragma once

#include "start_sequence.h"
#include "elevio.h"
#include "con_load.h"

//initialisering
void start_sequence(int *floor_sensor){
    elevio_init();
    elevio_motorDirection(-1);
    while (*floor_sensor != 1){
        *floor_sensor = elevio_floorSensor();
        usleep(10000);
    }
    elevio_motorDirection(0);
}
