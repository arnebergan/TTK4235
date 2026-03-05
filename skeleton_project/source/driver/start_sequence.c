#pragma once

#include <time.h>

#include "elevio.h"
#include "con_load.h"

//initialisering
void start_sequence(int *p_g_floor){
    elevio_motorDirection(-1);
    while (*p_g_floor != 1){
        check_floor(p_g_floor);
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }
    elevio_motorDirection(0);
}
