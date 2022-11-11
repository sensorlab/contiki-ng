#include "contiki.h"
#include "net/mac/tsch/tsch.h"


const tsch_timeslot_timing_usec tsch_timeslot_timing_rf2xx_10000us_250kbps = {
   1000, // CCAOffset 
    128, // CCA 
   1620, // TxOffset 
  (1620 - (TSCH_CONF_RX_WAIT / 2)), // RxOffset (TSCH_CONF_RX_WAIT default = 2200)
   1500, // RxAckDelay      
   2000, // TxAckDelay (default: 1000)  
  TSCH_CONF_RX_WAIT, // RxWait 
   1000, // AckWait (default: 400)
    192, // RxTx (not used)
   2400, // MaxAck 
   4256, // MaxTx 
  10000, // TimeslotLength 
};

/**
 * \brief TSCH timing attributes and description. All timings are in usec.
 *
 * CCAOffset   -> time between the beginning of timeslot and start of CCA
 * CCA         -> duration of CCA (CCA is NOT ENABLED by default)
 * TxOffset    -> time between beginning of the timeslot and start of frame TX (end of SFD)
 * RxOffset    -> beginning of the timeslot to when the receiver shall be listening
 * RxAckDelay  -> end of frame to when the transmitter shall listen for ACK
 * TxAckDelay  -> end of frame to the start of ACK tx
 * RxWait      -> time to wait for start of frame (Guard time)
 * AckWait     -> min time to wait for start of an ACK frame
 * RxTx        -> receive-to-transmit switch time (NOT USED)
 * MaxAck      -> TX time to send a max length ACK
 * MaxTx       -> TX time to send the max length frame
 *
 * The TSCH timeslot structure is described in the IEEE 802.15.4-2015 standard,
 * in particular in the Figure 6-30.
 *
 * The default timeslot timing in the standard is a guard time of
 * 2200 us, a Tx offset of 2120 us and a Rx offset of 1120 us.
 * As a result, the listening device has a guard time not centered
 * on the expected Tx time. This is to be fixed in the next iteration
 * of the standard. This can be enabled with:
 * TxOffset: 2120
 * RxOffset: 1120
 * RxWait:   2200
 *
 * Instead, we align the Rx guard time on expected Tx time. The Rx
 * guard time is user-configurable with TSCH_CONF_RX_WAIT.
 * (TxOffset - (RxWait / 2)) instead
 *

const tsch_timeslot_timing_usec tsch_timeslot_timing_us_10000 = {
   1800, // CCAOffset 
    128, // CCA 
   2120, // TxOffset 
  (2120 - (TSCH_CONF_RX_WAIT / 2)), /* RxOffset 
    800, // RxAckDelay 
   1000, // TxAckDelay 
  TSCH_CONF_RX_WAIT, / RxWait 
    400, // AckWait 
    192, // RxTx 
   2400, // MaxAck 
   4256, // MaxTx 
  10000, // TimeslotLength 
};
*/