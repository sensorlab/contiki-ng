/* -----------------------------------------------------------------------------
 * SEND 0 data
 *
 * Root pings neighbour devices 
 * 
 * -----------------------------------------------------------------------------
*/

#include "contiki.h"
#include <stdio.h>
#include "dev/serial-line.h"

#include "contiki.h"
#include "net/routing/routing.h"
#include "net/netstack.h"
#include "net/ipv6/simple-udp.h"

#include "sys/log.h"
#define LOG_MODULE "App"
#define LOG_LEVEL LOG_LEVEL_INFO

#define WITH_SERVER_REPLY  1
#define UDP_CLIENT_PORT	8765
#define UDP_SERVER_PORT	5678

static struct simple_udp_connection udp_conn;


// Is device root of the DAG network
static uint8_t device_is_root = 0;


/*---------------------------------------------------------------------------*/

void STATS_parse_input_command(char *data);
void STATS_set_device_as_root(void);

/*---------------------------------------------------------------------------*/

PROCESS(serial_input_process, "Serial input command");
PROCESS(udp_server_process, "UDP server");

AUTOSTART_PROCESSES(&udp_server_process);




/*---------------------------------------------------------------------------*/
static void
udp_rx_callback(struct simple_udp_connection *c,
         const uip_ipaddr_t *sender_addr,
         uint16_t sender_port,
         const uip_ipaddr_t *receiver_addr,
         uint16_t receiver_port,
         const uint8_t *data,
         uint16_t datalen)
{
  //LOG_INFO("Received request '%.*s' from ", datalen, (char *) data);
  LOG_INFO("Received from");
  LOG_INFO_6ADDR(sender_addr);
  LOG_INFO_("\n");


  /* send back the same string to the client as an echo reply */
  //LOG_INFO("Sending response.\n");
  //simple_udp_sendto(&udp_conn, data, datalen, sender_addr);

}
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(udp_server_process, ev, data)
{
  PROCESS_BEGIN();

  /* Initialize DAG root */
  NETSTACK_ROUTING.root_start();

  /* Initialize UDP connection */
  simple_udp_register(&udp_conn, UDP_SERVER_PORT, NULL,
                      UDP_CLIENT_PORT, udp_rx_callback);

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/























/*---------------------------------------------------------------------------*/
PROCESS_THREAD(serial_input_process, ev, data)
{
    PROCESS_BEGIN();
    while(1){
      PROCESS_WAIT_EVENT_UNTIL((ev == serial_line_event_message) && (data != NULL));
      STATS_parse_input_command(data);
    }
    PROCESS_END();
}

void
STATS_parse_input_command(char *data)
{
    char cmd = data[0];
    switch(cmd){
      case '>':
        //process_start(&stats_process, NULL);
        break;
      
      case '*':
	  	device_is_root = 1;
        //STATS_set_device_as_root();
        break;
      
      case '=':
        //process_exit(&stats_process);
        //STATS_close_app();
        break;

    /*  case '!':
	  // Example usage (not tested yet): ! fe80::212:4b00:6:1234
		uip_ipaddr_t remote_addr;
		char *args;
		args = data[2];
		if(uiplib_ipaddrconv(args, &remote_addr) != 0){
        	process_start(&ping_process, &remote_addr);
		}
        break;
	*/

      //case 'reboot':
        //watchdog_reboot();
        //break;
    }
}


/*---------------------------------------------------------------------------*/
