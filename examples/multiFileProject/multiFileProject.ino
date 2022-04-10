/****************************************************************************************************************************
  multiFileProject.ino
  For W5x00, ENC28J60 and built-in LAN8742A Ethernet shields.

  Ethernet_Manager is a library for STM32F/L/H/G/WB/MP1 with Ethernet W5x00, ENC28J60 or built-in LAN8742A shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_STM32
  Licensed under MIT license
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#define ETHERNET_MANAGER_STM32_VERSION_MIN_TARGET      "Ethernet_Manager_STM32 v1.3.2"
#define ETHERNET_MANAGER_STM32_VERSION_MIN             1003002

#include "multiFileProject.h"

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include <Ethernet_Manager_STM32.h>         // https://github.com/khoih-prog/Ethernet_Manager_STM32

void setup() 
{
  Serial.begin(115200);
  while (!Serial);

  delay(500);
  
  Serial.println("\nStart multiFileProject");
  Serial.println(ETHERNET_MANAGER_STM32_VERSION);

#if defined(ETHERNET_MANAGER_STM32_VERSION_MIN)
  if (ETHERNET_MANAGER_STM32_VERSION_INT < ETHERNET_MANAGER_STM32_VERSION_MIN)
  {
    Serial.print("Warning. Must use this example on Version equal or later than : ");
    Serial.println(ETHERNET_MANAGER_STM32_VERSION_MIN_TARGET);
  }
#endif

  Serial.print("You're OK now");
}

void loop() 
{
  // put your main code here, to run repeatedly:
}
