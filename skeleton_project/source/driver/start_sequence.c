#pragma once

#include "elevio.h"
#include "con_load.h"

elevio_init()
ButtonType Order_buttons[] = {BUTTON_HALL_DOWN, BUTTON_CAB, BUTTON_HALL_DOWN, BUTTON_HALL_UP,
     BUTTON_CAB, BUTTON_HALL_DOWN, BUTTON_HALL_UP, BUTTON_CAB, BUTTON_HALL_UP, BUTTON_CAB};

int current_floor = elevio_floorSensor()
elevio_motorDirection(-1)
while current_floor != 1
    current_floor = elevio_floorSensor()

elevio_motorDirection(0)