/****************************************************************************************************************************
  DHT11_Ethernet_STM32_LAN8720.ino
  For LAN8720, W5x00, ENC28J60 and built-in LAN8742A Ethernet shields.

  Ethernet_Manager is a library for STM32F/L/H/G/WB/MP1 with Ethernet W5x00, ENC28J60 or built-in LAN8742A shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_STM32
  Licensed under MIT license
 *****************************************************************************************************************************/

#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

#include <SPI.h>
#include <DHT.h>

#define DHT_PIN               5
#define DHT_TYPE              DHT11

DHT dht(DHT_PIN, DHT_TYPE);

#define READ_INTERVAL         30000L          //read DHT11 interval 30s

#define DHT11_DEBUG           true

Ethernet_Manager ethernet_manager;

IPAddress localEthernetIP;

// Use to detect W5100 shield. The linkStatus() is not working with W5100, only W5200 and W5500
// To check if W5100 using Ethernet and EthernetLarge libraries
bool isW5500 = true;

void readAndSendData()
{
  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

#if DHT11_DEBUG

  if (!isnan(temperature) && !isnan(humidity))
  {
    Serial.print(F("\nTemp *C: "));
    Serial.print(String(temperature, 1));
    Serial.print(F(", Humid %: "));
    Serial.println(String(humidity, 1));
  }
  else
  {
    Serial.println(F("\nFailed to read data from DHT11"));
  }

#else
  Serial.println(F("R"));
#endif
}

void heartBeatPrint()
{
  static int num        = 1;
  static int linkStatus = 0;

  localEthernetIP = Ethernet.localIP();

  // The linkStatus() is not working with W5100. Just using IP != 0.0.0.0
  // Better to use ping for W5100
  linkStatus = (int) Ethernet.linkStatus();
  ET_LOGINFO3(F("localEthernetIP = "), localEthernetIP, F(", linkStatus = "),
              (linkStatus == LinkON) ? F("LinkON") : F("LinkOFF") );

  if ( (uint32_t) localEthernetIP != 0 )
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

  // readAndSendData every READ_INTERVAL (30) seconds: we don't need to read frequently.
  if (millis() > readData_timeout)
  {
    readAndSendData();
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
  const char NewCustomsStyle[] /*PROGMEM*/ =
  "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
  button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";
#endif

void setup()
{
  // Debug console
  Serial.begin(115200);
  delay(2000);

  Serial.print(F("\nStart DHT11_Ethernet_STM32_LAN8720 on "));
  Serial.println(BOARD_NAME);
  Serial.print(F("Ethernet Shield type : "));
  Serial.println(SHIELD_TYPE);
  Serial.println(ETHERNET_MANAGER_STM32_VERSION);
  Serial.println(DOUBLERESETDETECTOR_GENERIC_VERSION);

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

  if ( (uint32_t) localEthernetIP != 0 )
  {
    Serial.print(F("Connected! IP address: "));
    Serial.println(localEthernetIP);
  }
  else
  {
    Serial.println(F("Ethernet not Connected! Please check."));
  }
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
