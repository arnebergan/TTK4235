void stop_button(int *p_g_stop_button, int *p_g_motordirection, int *p_g_door_open, int *p_g_order_buttons, int *p_g_floor){
    if (*p_g_stop_button){
        *p_g_motordirection=0;
        elevio_motorDirection(0);
        if(*p_g_floor){    //Need to find out the value of p_g_floor when between floor
            *p_g_door_open=1;
        }
        for(int i=0; i<12; i++){
            *(p_g_order_buttons+i)=0;
        }
        //Function update lights
        while(*p_g_stop_button){
            usleep(20000);
            //Function update stopbutton
        }
        *p_g_door_open=0;
    }
}