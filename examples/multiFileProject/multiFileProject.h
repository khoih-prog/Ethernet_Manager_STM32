/****************************************************************************************************************************
  multiFileProject.h
  For W5x00, ENC28J60 and built-in LAN8742A Ethernet shields.

  Ethernet_Manager is a library for STM32F/L/H/G/WB/MP1 with Ethernet W5x00, ENC28J60 or built-in LAN8742A shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_STM32
  Licensed under MIT license
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#pragma once

// Only one if the following to be true
#define USE_BUILTIN_ETHERNET  true
#define USE_ETHERNET_GENERIC  false
#define USE_ETHERNET_ENC      false
#define USE_UIP_ETHERNET      false
#define USE_CUSTOM_ETHERNET   false

// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include <Ethernet_Manager_STM32.hpp>         // https://github.com/khoih-prog/Ethernet_Manager_STM32
