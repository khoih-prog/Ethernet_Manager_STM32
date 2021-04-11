/****************************************************************************************************************************
  AM2315_Ethernet_STM32.ino
  For W5x00, ENC28J60 and built-in LAN8742A Ethernet shields.

  Ethernet_Manager is a library for STM32F/L/H/G/WB/MP1 with Ethernet W5x00, ENC28J60 or built-in LAN8742A shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_STM32
  Licensed under MIT license
  Version: 1.3.0

  Version  Modified By   Date      Comments
  -------  -----------  ---------- -----------
  1.0.0     K Hoang     16/12/2020 Initial coding.
  1.0.1     K Hoang     29/12/2020 Suppress all possible compiler warnings
  1.2.0     K Hoang     23/02/2021 Optimize code and use better FlashStorage_STM32. Add customs HTML header feature. Fix bug.
  1.3.0     K Hoang     11/04/2021 Add support to LAN8720 using STM32F4 or STM32F7
 *****************************************************************************************************************************/
 
#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_AM2315.h>        // To install Adafruit AM2315 library

// Connect RED of the AM2315 sensor to 5.0V
// Connect BLACK to Ground
// Connect WHITE to i2c clock (SCL) - on '168/'328 Arduino Uno/Duemilanove/etc that's Analog 5
// Connect YELLOW to i2c data (SDA) - on '168/'328 Arduino Uno/Duemilanove/etc that's Analog 4

Adafruit_AM2315 AM2315;

#define AM2315_DEBUG     true

Ethernet_Manager ethernet_manager;

IPAddress localEthernetIP;

// Use to detect W5100 shield. The linkStatus() is not working with W5100, only W5200 and W5500
// To check if W5100 using Ethernet and EthernetLarge libraries
bool isW5500 = true;

#define READ_INTERVAL        30000L          //read AM2315 interval 30s

void ReadData()
{
  static float temperature, humidity;

  if (!AM2315.readTemperatureAndHumidity(&temperature, &humidity))
  {
#if AM2315_DEBUG
    Serial.println(F("\nFailed to read data from AM2315"));
#endif

    return;
  }

#if AM2315_DEBUG
  Serial.print(F("\nTemp *C: "));
  Serial.print(String(temperature, 1));
  Serial.print(F(", Humid %: "));
  Serial.println(String(humidity, 1));
#endif
}

void heartBeatPrint()
{
  static int num        = 1;
  static int linkStatus = 0;
  
  localEthernetIP = Ethernet.localIP();
  
#if (USE_ETHERNET2 || USE_ETHERNET3)
  // To modify Ethernet2 library
  linkStatus = Ethernet.link();
  ET_LOGINFO3(F("localEthernetIP = "), localEthernetIP, F(", linkStatus = "), (linkStatus == 1) ? F("LinkON") : F("LinkOFF") );
  
  if ( ( linkStatus == 1 ) && ((uint32_t) localEthernetIP != 0) )
#else

  // The linkStatus() is not working with W5100. Just using IP != 0.0.0.0
  // Better to use ping for W5100
  linkStatus = (int) Ethernet.linkStatus();
  ET_LOGINFO3(F("localEthernetIP = "), localEthernetIP, F(", linkStatus = "), (linkStatus == LinkON) ? F("LinkON") : F("LinkOFF") );
  
  if ( ( (linkStatus == LinkON) || !isW5500 ) && ((uint32_t) localEthernetIP != 0) )
#endif
  {
    Serial.print(F("H"));
  }
  else
    Serial.print(F("F"));

  if (num == 80)
  {
    Serial.println();
    num = 1;
  }
  else if (num++ % 10 == 0)
  {
    Serial.print(F(" "));
  }
}

void check_status()
{
  #define STATUS_CHECK_INTERVAL     60000L
  
  static unsigned long checkstatus_timeout = STATUS_CHECK_INTERVAL;
  static unsigned long readData_timeout    = READ_INTERVAL;

  // ReadData every READ_INTERVAL (30) seconds: we don't need to read frequently.
  if (millis() > readData_timeout)
  {
    ReadData();
    readData_timeout = millis() + READ_INTERVAL;
  }
  
  // Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to send updates frequently if there is no status change.
  if (millis() > checkstatus_timeout)
  {
    heartBeatPrint();
    checkstatus_timeout = millis() + STATUS_CHECK_INTERVAL;
  }
}

#if USING_CUSTOMS_STYLE
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";
#endif

void setup()
{
  // Debug console
  Serial.begin(115200);
  while (!Serial);

  Serial.print(F("\nStart AM2315_Ethernet_STM32 on "));
  Serial.println(BOARD_NAME);
  Serial.print(F("Ethernet Shield type : "));
  Serial.println(SHIELD_TYPE);
  Serial.println(ETHERNET_MANAGER_STM32_VERSION);
  Serial.println(DOUBLERESETDETECTOR_GENERIC_VERSION);

  #if ( defined(USE_BUILTIN_ETHERNET) && USE_BUILTIN_ETHERNET )
    ET_LOGWARN(F("======== USE_BUILTIN_ETHERNET ========"));
  #elif ( defined(USE_UIP_ETHERNET) && USE_UIP_ETHERNET )
    ET_LOGWARN(F("======== USE_UIP_ETHERNET ========"));  
  #elif USE_NATIVE_ETHERNET
    ET_LOGWARN(F("======== USE_NATIVE_ETHERNET ========"));
  #elif USE_ETHERNET
    ET_LOGWARN(F("=========== USE_ETHERNET ==========="));
  #elif USE_ETHERNET2
    ET_LOGWARN(F("=========== USE_ETHERNET2 ==========="));
  #elif USE_ETHERNET3
    ET_LOGWARN(F("=========== USE_ETHERNET3 ==========="));
  #elif USE_ETHERNET_LARGE
    ET_LOGWARN(F("=========== USE_ETHERNET_LARGE ==========="));
  #elif USE_ETHERNET_ENC
    ET_LOGWARN(F("=========== USE_ETHERNET_ENC ==========="));  
  #else
    ET_LOGWARN(F("========================="));
  #endif
  
  ET_LOGWARN(F("Default SPI pinout:"));
  ET_LOGWARN1(F("MOSI:"), MOSI);
  ET_LOGWARN1(F("MISO:"), MISO);
  ET_LOGWARN1(F("SCK:"),  SCK);
  ET_LOGWARN1(F("SS:"),   SS);
  ET_LOGWARN(F("========================="));
  
  // unknown board, do nothing, use default SS = 10
  #ifndef USE_THIS_SS_PIN
    #define USE_THIS_SS_PIN   10    // For other boards
  #endif
  
  #if defined(BOARD_NAME)
    ET_LOGWARN3(F("Board :"), BOARD_NAME, F(", setCsPin:"), USE_THIS_SS_PIN);
  #else
    ET_LOGWARN1(F("Unknown board setCsPin:"), USE_THIS_SS_PIN);
  #endif

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card

  #if USE_ETHERNET_WRAPPER
  
    EthernetInit();
  
  #else
  
    // For other boards, to change if necessary
    #if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2  || USE_ETHERNET_ENC )
      // Must use library patch for Ethernet, Ethernet2, EthernetLarge libraries
    
      Ethernet.init (USE_THIS_SS_PIN);
    
    #elif USE_ETHERNET3
      // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
      #ifndef ETHERNET3_MAX_SOCK_NUM
        #define ETHERNET3_MAX_SOCK_NUM      4
      #endif
    
      Ethernet.setCsPin (USE_THIS_SS_PIN);
      Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
    
    #elif USE_CUSTOM_ETHERNET
    
      // You have to add initialization for your Custom Ethernet here
      // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
      Ethernet.init(USE_THIS_SS_PIN);
      
    #endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )
    
  #endif  //USE_ETHERNET_WRAPPER

#endif

  // Just info to know how to connect correctly
  ET_LOGWARN(F("========================="));
  ET_LOGWARN(F("Currently Used SPI pinout:"));
  ET_LOGWARN1(F("MOSI:"), MOSI);
  ET_LOGWARN1(F("MISO:"), MISO);
  ET_LOGWARN1(F("SCK:"), SCK);
  ET_LOGWARN1(F("SS:"), SS);
  
#if USE_ETHERNET3
  ET_LOGWARN1(F("SPI_CS:"), SPI_CS);
#endif
  ET_LOGWARN(F("========================="));
 
  //////////////////////////////////////////////
  
#if USING_CUSTOMS_STYLE
  ethernet_manager.setCustomsStyle(NewCustomsStyle);
#endif

#if USING_CUSTOMS_HEAD_ELEMENT
  ethernet_manager.setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
#endif

#if USING_CORS_FEATURE  
  ethernet_manager.setCORSHeader("Your Access-Control-Allow-Origin");
#endif

  ethernet_manager.begin();

  //////////////////////////////////////////////

  localEthernetIP = Ethernet.localIP();

#if (USE_ETHERNET2 || USE_ETHERNET3)
  // To modify Ethernet2 library
  if ( (uint32_t) localEthernetIP != 0 )
#else
  if ( (uint32_t) localEthernetIP != 0 )
#endif
  {
    Serial.print(F("Connected! IP address: "));
    Serial.println(localEthernetIP);
  }
  else
  {
    Serial.println(F("Ethernet not Connected! Please check."));
  }

  // Detect W5100 only in Ethernet and EthernetLarge libraries
#if ( USE_ETHERNET || USE_ETHERNET_LARGE)
  isW5500 = (Ethernet.hardwareStatus() == EthernetW5500);
  Serial.print(F("Ethernet type is "));
  Serial.println(isW5500 ? F("W5500") : F("W5100"));
#endif
}

#if (USE_DYNAMIC_PARAMETERS)
void displayCredentials()
{
  Serial.println(F("\nYour stored Credentials :"));

  for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.print(myMenuItems[i].displayName);
    Serial.print(" = ");
    Serial.println(myMenuItems[i].pdata);
  }
}

void displayCredentialsOnce()
{
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
    {
      if (!strlen(myMenuItems[i].pdata))
      {
        break;
      }

      if ( i == (NUM_MENU_ITEMS - 1) )
      {
        displayedCredentials = true;
        displayCredentials();
      }
    }
  }
}
#endif

void loop()
{
  ethernet_manager.run();
  
  check_status();

#if (USE_DYNAMIC_PARAMETERS)
  displayCredentialsOnce();
#endif  
}
