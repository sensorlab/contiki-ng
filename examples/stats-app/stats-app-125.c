
#include "contiki.h"
#include <stdio.h> // For printf()
#include "arch/platform/vesna/dev/at86rf2xx/rf2xx.h"
#include "arch/platform/vesna/vesna-drivers/VESNALib/inc/vsntime.h" // For delay


#define APP_DURATION        (60*3)
#define CCNUM               (125)


PROCESS(continuous_transmission_test_mode_process, "CTTM process");
AUTOSTART_PROCESSES(&continuous_transmission_test_mode_process);


PROCESS_THREAD(continuous_transmission_test_mode_process, ev, data){

    static struct etimer timer;

    PROCESS_BEGIN();

/*
    printf("Set radio to: continuos transmission test mode.1 \n");
    rf2xx_CTTM_start(0x0d, CCNUM);

    vsnTime_delayS(APP_DURATION);

    rf2xx_CTTM_stop();
    printf("Stop continuos transmission test mode. \n");

vsnTime_delayS(1);

    printf("Set radio to: continuos transmission test mode.2 \n");
    rf2xx_CTTM_start(0x0b, CCNUM);

    vsnTime_delayS(APP_DURATION);

    rf2xx_CTTM_stop();
    printf("Stop continuos transmission test mode. \n");

vsnTime_delayS(1);

    printf("Set radio to: continuos transmission test mode. 3\n");
    rf2xx_CTTM_start(0x09, CCNUM);

    vsnTime_delayS(APP_DURATION);

    rf2xx_CTTM_stop();
    printf("Stop continuos transmission test mode. \n");

vsnTime_delayS(1);

    printf("Set radio to: continuos transmission test mode. 4\n");
    rf2xx_CTTM_start(0x2a, CCNUM);

    vsnTime_delayS(APP_DURATION);

    rf2xx_CTTM_stop();
    printf("Stop continuos transmission test mode. \n");


vsnTime_delayS(1);

    printf("Set radio to: continuos transmission test mode. 5\n");
    rf2xx_CTTM_start(0x28, CCNUM);

    vsnTime_delayS(APP_DURATION);

    rf2xx_CTTM_stop();
    printf("Stop continuos transmission test mode. \n");

vsnTime_delayS(1);

    printf("Set radio to: continuos transmission test mode.6 \n");
    rf2xx_CTTM_start(0xad, CCNUM);

    vsnTime_delayS(APP_DURATION);

    rf2xx_CTTM_stop();
    printf("Stop continuos transmission test mode. \n");

vsnTime_delayS(1);

    printf("Set radio to: continuos transmission test mode. 7\n");
    rf2xx_CTTM_start(0xab, CCNUM);

    vsnTime_delayS(APP_DURATION);

    rf2xx_CTTM_stop();
    printf("Stop continuos transmission test mode. \n");


vsnTime_delayS(1);

    printf("Set radio to: continuos transmission test mode.8 \n");
    rf2xx_CTTM_start(0xea, CCNUM);

    vsnTime_delayS(APP_DURATION);

    rf2xx_CTTM_stop();
    printf("Stop continuos transmission test mode. \n");

vsnTime_delayS(1);
*/
    printf("Set radio to: continuos transmission test mode. 9\n");
    rf2xx_CTTM_start(0xe8, CCNUM);

    vsnTime_delayS(APP_DURATION);

    rf2xx_CTTM_stop();
    printf("Stop continuos transmission test mode. \n");


    while(1){}

    /* Setup a periodic timer that expires after 10 seconds. */
    etimer_set(&timer, CLOCK_SECOND * 10);

    while(1) {

        printf("Main loop \n");

        /* Wait for the periodic timer to expire and then restart the timer. */
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
        etimer_reset(&timer);
    }

    PROCESS_END();
}