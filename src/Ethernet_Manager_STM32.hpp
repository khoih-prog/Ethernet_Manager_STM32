/****************************************************************************************************************************
  Ethernet_Manager_STM32.hpp
  For W5x00, ENC28J60 and built-in LAN8742A Ethernet shields.
    
  Ethernet_Manager is a library for STM32F/L/H/G/WB/MP1 with Ethernet W5x00, ENC28J60 or built-in LAN8742A shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_STM32
  Licensed under MIT license
  
  Version: 1.3.2

  Version  Modified By   Date      Comments
  -------  -----------  ---------- -----------
  1.0.0     K Hoang     16/12/2020 Initial coding.
  1.0.1     K Hoang     29/12/2020 Suppress all possible compiler warnings
  1.2.0     K Hoang     23/02/2021 Optimize code and use better FlashStorage_STM32. Add customs HTML header feature. Fix bug.
  1.3.0     K Hoang     11/04/2021 Add support to LAN8720 using STM32F4 or STM32F7
  1.3.1     K Hoang     10/10/2021 Update `platform.ini` and `library.json`
  1.3.2     K Hoang     10/04/2022 Use Ethernet_Generic library as default.
 *****************************************************************************************************************************/


#pragma once

#ifndef ETHERNET_MANAGER_STM32_HPP
#define ETHERNET_MANAGER_STM32_HPP

///////////////////////////////////////////////////////////////

#if USE_BUILTIN_ETHERNET
  #include <LwIP.h>
  #include <STM32Ethernet.h>
  #include <EthernetClient.h>
  
  #if USING_LAN8720
    #define SHIELD_TYPE           "LAN8720 Ethernet & STM32Ethernet Library"
  #else
    #define SHIELD_TYPE           "LAN8742A Ethernet & STM32Ethernet Library"
  #endif
    
#elif USE_ETHERNET_GENERIC
  #include "Ethernet_Generic.hpp"
  #include <EthernetClient.h>
  
  #define SHIELD_TYPE           "W5x00 using Ethernet_Generic Library"
#elif USE_ETHERNET_ENC
  #include "EthernetENC.h"
  #include <EthernetClient.h>
  #define SHIELD_TYPE           "ENC28J60 using EthernetENC Library"
#elif USE_UIP_ETHERNET
  #include "UIPEthernet.h"
  #define SHIELD_TYPE           "ENC28J60 using UIPEthernet Library"
#elif USE_CUSTOM_ETHERNET
  //#include "Ethernet_XYZ.h"
  #include "EthernetLarge.h"
  #include <EthernetClient.h>
  
  #define SHIELD_TYPE           "Custom Ethernet using Ethernet_XYZ Library"
#else
  #ifdef USE_ETHERNET_GENERIC
    #undef USE_ETHERNET_GENERIC
  #endif
  #define USE_ETHERNET_GENERIC   true
  #include "Ethernet_Generic.hpp"
  #include <EthernetClient.h>

  #define SHIELD_TYPE           "W5x00 using default Ethernet_Generic Library"
#endif

///////////////////////////////////////////////////////////////

#if (_ETHERNET_MANAGER_STM32_LOGLEVEL_ > 2)
  #if USE_BUILTIN_ETHERNET 
    #if USING_LAN8720
      #warning Using LAN8720 Ethernet with STM32Ethernet library from EthernetWebServer_STM32
    #else
      #warning Using built-in LAN8742A Ethernet with STM32Ethernet library from EthernetWebServer_STM32
    #endif
      
  #elif USE_ETHERNET_GENERIC
    #warning Using Ethernet_Generic lib from Ethernet_Manager_STM32.h
  #elif USE_ETHERNET_ENC
    #warning Using EthernetENC lib from Ethernet_Manager_STM32.h
  #elif USE_UIP_ETHERNET
    #warning Using UIPEthernet lib from Ethernet_Manager.h
  #elif USE_CUSTOM_ETHERNET
    #warning Using Custom Ethernet library from Ethernet_Manager_STM32.h. You must include a library and initialize.
  #else
    #warning Using default Ethernet_Generic lib from Ethernet_Manager_STM32.h
  #endif
#endif  // (_ETHERNET_MANAGER_STM32_LOGLEVEL_ > 2)

#include <EthernetWebServer_STM32.hpp>

#endif    // ETHERNET_MANAGER_STM32_HPP
