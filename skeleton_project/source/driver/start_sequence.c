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
void start_sequence(int *p_g_floor, int *p_g_last_floor){
    elevio_motorDirection(-1);
    while (*p_g_floor != 0){
        check_floor(p_g_floor, p_g_last_floor);
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }
    elevio_motorDirection(0);
}
