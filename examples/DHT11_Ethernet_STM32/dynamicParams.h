/****************************************************************************************************************************
  dynamicParams.h
  For W5x00, ENC28J60 and built-in LAN8742A Ethernet shields.

  Ethernet_Manager is a library for STM32F/L/H/G/WB/MP1 with Ethernet W5x00, ENC28J60 or built-in LAN8742A shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_STM32
  Licensed under MIT license
  Version: 1.0.1

  Version  Modified By   Date      Comments
  -------  -----------  ---------- -----------
  1.0.0     K Hoang     16/12/2020 Initial coding.
  1.0.1     K Hoang     29/12/2020 Suppress all possible compiler warnings
 *****************************************************************************************************************************/

#ifndef dynamicParams_h
#define dynamicParams_h

#include "defines.h"

#define USE_DYNAMIC_PARAMETERS      true

/////////////// Start dynamic Credentials ///////////////

//Defined in BlynkEthernet_WM.h, <BlynkEthernet_ESP8266_WM.h>, <BlynkEthernet_ESP32 or_WM.h>
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

  #define MAX_MQTT_SERVER_LEN      34
  char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "default-mqtt-server";
  
  #define MAX_MQTT_PORT_LEN        6
  char MQTT_Port   [MAX_MQTT_PORT_LEN + 1]  = "1883";
  
  #define MAX_MQTT_USERNAME_LEN      34
  char MQTT_UserName  [MAX_MQTT_USERNAME_LEN + 1]   = "default-mqtt-username";
  
  #define MAX_MQTT_PW_LEN        34
  char MQTT_PW   [MAX_MQTT_PW_LEN + 1]  = "default-mqtt-password";
  
  #define MAX_MQTT_SUBS_TOPIC_LEN      34
  char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN + 1]   = "default-mqtt-SubTopic";
  
  #define MAX_MQTT_PUB_TOPIC_LEN       34
  char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN + 1]  = "default-mqtt-PubTopic";
  
  MenuItem myMenuItems [] =
  {
    { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
    { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
    { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
    { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
    { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
    { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
  };
  
  uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

  MenuItem myMenuItems [] = {};
  
  uint16_t NUM_MENU_ITEMS = 0;
#endif

/////// // End dynamic Credentials ///////////

#endif      //dynamicParams_h
