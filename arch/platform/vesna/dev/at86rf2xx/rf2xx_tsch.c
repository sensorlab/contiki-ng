#include "contiki.h"
#include "net/mac/tsch/tsch.h"

/*
const tsch_timeslot_timing_usec tsch_timeslot_timing_rf2xx_10000us_250kbps = {
   1800, // CCAOffset 
    128, // CCA 
   2120, // TxOffset 
  (2120 - (TSCH_CONF_RX_WAIT / 2)), // RxOffset 
    1000, // RxAckDelay      
   1800, // TxAckDelay (default: 1000)  
  TSCH_CONF_RX_WAIT, // RxWait 
   3600, // AckWait (default: 400)
    192, // RxTx 
   3000, // MaxAck (default: 2400)
   4256, // MaxTx 
  10000, // TimeslotLength 
};
*/


const tsch_timeslot_timing_usec tsch_timing_rf2xx_15ms = {
    1800,   // CCAOffset
    128,    // CCA

    3000,   // TxOffset
    (3000 - (TSCH_CONF_RX_WAIT / 2)), // RxOffset
    3000,   // RxAckDelay
    3800,   // TxAckDelay
    TSCH_CONF_RX_WAIT, // RxWait (PGT)
    2000,   // AckWait (AGT)
    2072,   // RxTx (Not used)
    2400,   // MaxAck (TxAck)
    4256,   // MaxTx (TxPacket)
    15000,  // TimeslotLength
};

