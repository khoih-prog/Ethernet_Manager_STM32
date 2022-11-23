/****************************************************************************************************************************
  dynamicParams.h
  For W5x00, ENC28J60 and built-in LAN8742A Ethernet shields.

  Ethernet_Manager is a library for STM32F/L/H/G/WB/MP1 with Ethernet W5x00, ENC28J60 or built-in LAN8742A shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_STM32
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef dynamicParams_h
#define dynamicParams_h

#include "defines.h"

// USE_DYNAMIC_PARAMETERS defined in defined.h

/////////////// Start dynamic Credentials ///////////////

//Defined in <Ethernet_Manager_STM32_Impl.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

#define MAX_MQTT_SERVER_LEN         48
char MQTT_SERVER  [MAX_MQTT_SERVER_LEN + 1]       = "default-mqtt-server";

#define MAX_MQTT_PORT_LEN        6
char MQTT_PORT   [MAX_MQTT_PORT_LEN + 1]          = "1883";

#define MAX_MQTT_USERNAME_LEN       34
char MQTT_USER  [MAX_MQTT_USERNAME_LEN + 1]       = "default-mqtt-username";

#define MAX_MQTT_PW_LEN             48
char MQTT_PASS   [MAX_MQTT_PW_LEN + 1]            = "default-mqtt-password";

#define MAX_MQTT_CLIENT_ID          48
char MQTT_CLIENT_ID  [MAX_MQTT_CLIENT_ID + 1]     = "default-mqtt-clientID";

MenuItem myMenuItems [] =
{
  { "mqtt", "MQTT Server",      MQTT_SERVER,      MAX_MQTT_SERVER_LEN },
  { "mqpt", "Port",             MQTT_PORT,        MAX_MQTT_PORT_LEN },
  { "user", "MQTT UserName",    MQTT_USER,        MAX_MQTT_USERNAME_LEN },
  { "mqpw", "MQTT PWD",         MQTT_PASS,        MAX_MQTT_PW_LEN },
  { "clid", "Client ID",        MQTT_CLIENT_ID,   MAX_MQTT_CLIENT_ID },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;
#endif

/////// // End dynamic Credentials ///////////

#endif      //dynamicParams_h
