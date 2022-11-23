/****************************************************************************************************************************
  Ethernet_Manager_STM32.h
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

#ifndef ETHERNET_MANAGER_STM32_H
#define ETHERNET_MANAGER_STM32_H

///////////////////////////////////////////////////////////////

#ifndef ETHERNET_MANAGER_STM32_VERSION
  #define ETHERNET_MANAGER_STM32_VERSION            "Ethernet_Manager_STM32 v1.3.2"

  #define ETHERNET_MANAGER_STM32_VERSION_MAJOR      1
  #define ETHERNET_MANAGER_STM32_VERSION_MINOR      3
  #define ETHERNET_MANAGER_STM32_VERSION_PATCH      2

  #define ETHERNET_MANAGER_STM32_VERSION_INT        1003002

#endif

///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////

#if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC || USE_BUILTIN_ETHERNET )
  #ifdef USE_CUSTOM_ETHERNET
    #undef USE_CUSTOM_ETHERNET
  #endif
  #define USE_CUSTOM_ETHERNET   false
#endif

///////////////////////////////////////////////////////////////

#if (USE_BUILTIN_ETHERNET  | USE_ETHERNET_ENC || USE_UIP_ETHERNET || USE_CUSTOM_ETHERNET)
  // Do nothing here
#elif USE_ETHERNET_GENERIC
  #include "Ethernet_Generic.h"

#else
  #ifdef USE_ETHERNET_GENERIC
    #undef USE_ETHERNET_GENERIC
  #endif
  #define USE_ETHERNET_GENERIC   true

  #include "Ethernet_Generic.h"
  //#include <EthernetClient.h>
#endif

///////////////////////////////////////////////////////////////

#include "Ethernet_Manager_STM32_Debug.h"

#include "Ethernet_Manager_STM32.hpp"

#include <EthernetWebServer_STM32.h>

#include "Ethernet_Manager_STM32_Impl.h"


#endif    // ETHERNET_MANAGER_STM32_H
