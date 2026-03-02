#pragma once

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
        usleep(10000);
    }
    elevio_motorDirection(0);
}
