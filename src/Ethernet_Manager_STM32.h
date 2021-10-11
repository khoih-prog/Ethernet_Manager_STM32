/****************************************************************************************************************************
  Ethernet_Manager_STM32.h
  For W5x00, ENC28J60 and built-in LAN8742A Ethernet shields.
    
  Ethernet_Manager is a library for STM32F/L/H/G/WB/MP1 with Ethernet W5x00, ENC28J60 or built-in LAN8742A shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_STM32
  Licensed under MIT license
  Version: 1.3.1

  Version  Modified By   Date      Comments
  -------  -----------  ---------- -----------
  1.0.0     K Hoang     16/12/2020 Initial coding.
  1.0.1     K Hoang     29/12/2020 Suppress all possible compiler warnings
  1.2.0     K Hoang     23/02/2021 Optimize code and use better FlashStorage_STM32. Add customs HTML header feature. Fix bug.
  1.3.0     K Hoang     11/04/2021 Add support to LAN8720 using STM32F4 or STM32F7
  1.3.1     K Hoang     10/10/2021 Update `platform.ini` and `library.json`
 *****************************************************************************************************************************/

#pragma once

#ifndef Ethernet_Manager_STM32
#define Ethernet_Manager_STM32

#define ETHERNET_MANAGER_STM32_VERSION      "Ethernet_Manager_STM32 v1.3.1"

#if ( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
       defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
       defined(STM32WB) || defined(STM32MP1) )
  #if defined(ETHERNET_USE_STM32)
    #undef ETHERNET_USE_STM32
  #endif
  #define ETHERNET_USE_STM32        true
#else   
 #error This code is designed to run on STM32F/L/H/G/WB/MP1 platform! Please check your Tools->Board setting.
#endif

#if ( USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE || USE_ETHERNET_ESP8266 || USE_ETHERNET_ENC || USE_BUILTIN_ETHERNET )
  #ifdef USE_CUSTOM_ETHERNET
    #undef USE_CUSTOM_ETHERNET
  #endif
  #define USE_CUSTOM_ETHERNET   false
#endif
    
#include "Ethernet_Manager_STM32_Debug.h"

//#if ( !defined(USE_UIP_ETHERNET) || !USE_UIP_ETHERNET )
       
  #if USE_BUILTIN_ETHERNET
    #include <LwIP.h>
    #include <STM32Ethernet.h>
    #include <EthernetClient.h>
    
    #if USING_LAN8720
      #warning Using LAN8720 Ethernet with STM32Ethernet library from EthernetWebServer_STM32
      #define SHIELD_TYPE           "LAN8720 Ethernet & STM32Ethernet Library"
    #else
      #warning Using built-in LAN8742A Ethernet with STM32Ethernet library from EthernetWebServer_STM32
      #define SHIELD_TYPE           "LAN8742A Ethernet & STM32Ethernet Library"
    #endif
      
  #elif USE_ETHERNET3
    #include "Ethernet3.h"
    #include <EthernetClient.h>
    #warning Using Ethernet3 lib from Ethernet_Manager_STM32.h
    #define SHIELD_TYPE           "W5x00 using Ethernet3 Library"
  #elif USE_ETHERNET2
    #include "Ethernet2.h"
    #include <EthernetClient.h>
    #warning Using Ethernet2 lib from Ethernet_Manager_STM32.h
    #define SHIELD_TYPE           "W5x00 using Ethernet2 Library"
  #elif USE_ETHERNET_LARGE
    #include "EthernetLarge.h"
    #include <EthernetClient.h>
    #warning Using EthernetLarge lib from Ethernet_Manager_STM32.h
    #define SHIELD_TYPE           "W5x00 using EthernetLarge Library"
  #elif USE_ETHERNET_ENC
    #include "EthernetENC.h"
    #include <EthernetClient.h>
    #warning Using EthernetENC lib from Ethernet_Manager_STM32.h
    #define SHIELD_TYPE           "ENC28J60 using EthernetENC Library"
  #elif USE_UIP_ETHERNET
    #include "UIPEthernet.h"
    #warning Using UIPEthernet lib from Ethernet_Manager.h
    #define SHIELD_TYPE           "ENC28J60 using UIPEthernet Library"
  #elif USE_CUSTOM_ETHERNET
    //#include "Ethernet_XYZ.h"
    #include "EthernetENC.h"
    #include <EthernetClient.h>
    #warning Using Custom Ethernet library from Ethernet_Manager_STM32.h. You must include a library and initialize.
    #define SHIELD_TYPE           "Custom Ethernet using Ethernet_XYZ Library"
  #else
    #ifdef USE_ETHERNET
      #undef USE_ETHERNET
    #endif
    #define USE_ETHERNET   true
    #include "Ethernet.h"
    #include <EthernetClient.h>
    #warning Using Ethernet lib from Ethernet_Manager.h
    #define SHIELD_TYPE           "W5x00 using Ethernet Library"
  #endif

#if !(USE_UIP_ETHERNET)
  //#include <EthernetClient.h>
#endif

#include <EthernetWebServer_STM32.h>

#include "Ethernet_Manager_STM32_Impl.h"


#endif    // Ethernet_Manager_STM32
