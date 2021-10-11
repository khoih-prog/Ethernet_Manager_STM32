/****************************************************************************************************************************
  defines.h
  For W5x00, ENC28J60 and built-in LAN8742A Ethernet shields.

  Ethernet_Manager is a library for STM32F/L/H/G/WB/MP1 with Ethernet W5x00, ENC28J60 or built-in LAN8742A shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_STM32
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if ( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
       defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
       defined(STM32WB) || defined(STM32MP1) )
  #if defined(ETHERNET_USE_STM32)
    #undef ETHERNET_USE_STM32
  #endif
  #define ETHERNET_USE_STM32         true
  #define USE_DYNAMIC_PARAMETERS      true
#else
  #error This code is designed to run on STM32F/L/H/G/WB/MP1 platform! Please check your Tools->Board setting.  
#endif

// To suppress boolean warnings of old libraries
#define boolean   bool

/* Comment this out to disable prints and save space */
#define ETHERNET_MANAGER_STM32_DEBUG_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_           0
#define _ETHERNET_MANAGER_STM32_LOGLEVEL_       2

#define DRD_GENERIC_DEBUG                       true

// To override the default CS/SS pin. Don't use unless you know exactly which pin to use
// You can define here or customize for each board at same place with BOARD_TYPE
//#define USE_THIS_SS_PIN   22  //21  //5 //4 //2 //15
// Default pin 10 to SS/CS. To change according to your board, if necessary
#define USE_THIS_SS_PIN       10

// Only one if the following to be true
#define USE_BUILTIN_ETHERNET  true
#define USE_ETHERNET          false
#define USE_ETHERNET2         false
#define USE_ETHERNET3         false
#define USE_ETHERNET_LARGE    false
#define USE_ETHERNET_ENC      false
#define USE_UIP_ETHERNET      false
#define USE_CUSTOM_ETHERNET   false

#if defined(STM32F0)
  #warning STM32F0 board selected
  #define BOARD_TYPE  "STM32F0"
#elif defined(STM32F1)
  #warning STM32F1 board selected
  #define BOARD_TYPE  "STM32F1"
#elif defined(STM32F2)
  #warning STM32F2 board selected
  #define BOARD_TYPE  "STM32F2"
#elif defined(STM32F3)
  #warning STM32F3 board selected
  #define BOARD_TYPE  "STM32F3"
#elif defined(STM32F4)
  #warning STM32F4 board selected
  #define BOARD_TYPE  "STM32F4"
#elif defined(STM32F7)
  #warning STM32F7 board selected
  #define BOARD_TYPE  "STM32F7"
#elif defined(STM32L0)
  #warning STM32L0 board selected
  #define BOARD_TYPE  "STM32L0"
#elif defined(STM32L1)
  #warning STM32L1 board selected
  #define BOARD_TYPE  "STM32L1"
#elif defined(STM32L4)
  #warning STM32L4 board selected
  #define BOARD_TYPE  "STM32L4"
#elif defined(STM32H7)
  #warning STM32H7 board selected
  #define BOARD_TYPE  "STM32H7"
#elif defined(STM32G0)
  #warning STM32G0 board selected
  #define BOARD_TYPE  "STM32G0"
#elif defined(STM32G4)
  #warning STM32G4 board selected
  #define BOARD_TYPE  "STM32G4"
#elif defined(STM32WB)
  #warning STM32WB board selected
  #define BOARD_TYPE  "STM32WB"
#elif defined(STM32MP1)
  #warning STM32MP1 board selected
  #define BOARD_TYPE  "STM32MP1"
#else
  #warning STM32 unknown board selected
  #define BOARD_TYPE  "STM32 Unknown"
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

//////////////////////////////////////////

#define EEPROM_START   0

/////////////////////////////////////////////

// Add customs headers from v1.2.0
#define USING_CUSTOMS_STYLE                 true
#define USING_CUSTOMS_HEAD_ELEMENT          true
#define USING_CORS_FEATURE                  true

/////////////////////////////////////////////

// Config Timeout 120s (default 60s)
#define CONFIG_TIMEOUT                      120000L

#define USE_DYNAMIC_PARAMETERS              true

//////////////////////////////////////////

#include <Ethernet_Manager_STM32.h>

#ifndef SHIELD_TYPE
  #define SHIELD_TYPE     "Unknown Ethernet shield/library" 
#endif

#define W5100_CS        10
#define SDCARD_CS       4

#define ETHERNET_HOST_NAME   "STM32-Ethernet"

#endif      //defines_h
