## Ethernet_Manager_STM32 Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/Ethernet_Manager_STM32.svg?)](https://www.ardu-badge.com/Ethernet_Manager_STM32)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Ethernet_Manager_STM32.svg)](https://github.com/khoih-prog/Ethernet_Manager_STM32/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Ethernet_Manager_STM32/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Ethernet_Manager_STM32.svg)](http://github.com/khoih-prog/Ethernet_Manager_STM32/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>

---
---

## Table of Contents


* [Why do we need this Ethernet_Manager_STM32 library](#why-do-we-need-this-ethernet_manager_stm32-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
  * [Currently supported Ethernet shields/modules](#currently-supported-ethernet-shieldsmodules)
  * [Not supported boards](#not-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For STM32 boards to use LAN8720](#1-for-stm32-boards-to-use-lan8720)
  * [2. For STM32 boards to use Serial1](#2-for-stm32-boards-to-use-serial1)
* [Libraries' Patches](#libraries-patches)
  * [1. For application requiring 2K+ HTML page](#1-for-application-requiring-2k-html-page)
  * [2. For Ethernet library](#2-for-ethernet-library)
  * [3. For EthernetLarge library](#3-for-ethernetlarge-library)
  * [4. For Etherne2 library](#4-for-ethernet2-library)
  * [5. For Ethernet3 library](#5-for-ethernet3-library)
  * [6. For UIPEthernet library](#6-for-uipethernet-library)
* [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error) 
* [Configuration Notes](#configuration-notes)
  * [1. How to select which built-in Ethernet or shield to use](#1-how-to-select-which-built-in-ethernet-or-shield-to-use)
    * [Select **one and only one** Ethernet library to use as follows:](#select-one-and-only-one-ethernet-library-to-use-as-follows)
    * [To use built-in LAN8742A](#to-use-built-in-lan8742a)
    * [To use LAN8720](#to-use-lan8720)
    * [To use W5x00 Ethernet, for example using EthernetLarge library](#to-use-w5x00-ethernet-for-example-using-ethernetlarge-library)
    * [To use ENC28J60 Ethernet, using EthernetENC library (**NEW and Better**)](#to-use-enc28j60-ethernet-using-ethernetenc-library-new-and-better)
    * [To use ENC28J60 Ethernet, using UIPEthernet library](#to-use-enc28j60-ethernet-using-uipethernet-library)
  * [Important](#important)
  * [2. How to select another CS/SS pin to use](#2-how-to-select-another-csss-pin-to-use)
  * [3. How to increase W5x00 TX/RX buffer](#3-how-to-increase-w5x00-txrx-buffer)
* [How to use default Credentials and have them pre-loaded onto Config Portal](#how-to-use-default-credentials-and-have-them-pre-loaded-onto-config-portal)
* [How to use](#how-to-use)
  * [1. Basic usage](#1-basic-usage)
  * [2. Add custom parameters](#2-add-custom-parameters)
  * [3. Not using custom parameters](#3-not-using-custom-parameters)
  * [4. To open Config Portal](#4-to-open-config-portal)
  * [5. To use custom HTML Style](#5-to-use-custom-html-style)
  * [6. To use custom Head Elements](#6-to-use-custom-head-elements)
  * [7. To use CORS Header](#7-to-use-cors-header)
* [Important Notes for using Dynamic Parameters' ids](#important-notes-for-using-dynamic-parameters-ids)
* [HOWTO use STM32F4 with LAN8720](#howto-use-stm32f4-with-lan8720)
  * [1. Wiring](#1-wiring)
  * [2. HOWTO program using STLink V-2 or V-3](#2-howto-program-using-stlink-v-2-or-v-3)
  * [3. HOWTO use Serial Port for Debugging](#3-howto-use-serial-port-for-debugging)
* [Examples](#examples)
  * [ 1. AM2315_Ethernet_STM32](examples/AM2315_Ethernet_STM32)
  * [ 2. DHT11_Ethernet_STM32](examples/DHT11_Ethernet_STM32)
  * [ 3. Ethernet_STM32](examples/Ethernet_STM32)
  * [ 4. MQTT_ThingStream_Ethernet_STM32](examples/MQTT_ThingStream_Ethernet_STM32)
  * [ 5. AM2315_Ethernet_STM32_LAN8720](examples/AM2315_Ethernet_STM32_LAN8720)
  * [ 6. DHT11_Ethernet_STM32_LAN8720](examples/DHT11_Ethernet_STM32_LAN8720)
  * [ 7. Ethernet_STM32_LAN8720](examples/Ethernet_STM32_LAN8720)
  * [ 8. MQTT_ThingStream_Ethernet_STM32_LAN8720](examples/MQTT_ThingStream_Ethernet_STM32_LAN8720)
  * [ 9. multiFileProject](examples/multiFileProject) **New**
* [So, how it works?](#so-how-it-works)
* [Example MQTT_ThingStream_Ethernet_STM32](#example-mqtt_thingstream_ethernet_stm32)
  * [1. File MQTT_ThingStream_Ethernet_STM32.ino](#1-file-mqtt_thingstream_ethernet_stm32ino)
  * [2. File defines.h](#2-file-definesh) 
  * [3. File Credentials.h](#3-file-credentialsh) 
  * [4. File dynamicParams.h](#4-file-dynamicparamsh) 
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. Ethernet_STM32 on STM32F7 NUCLEO_F767ZI with LAN8742A Ethernet using STM32Ethernet Library](#1-ethernet_stm32-on-stm32f7-nucleo_f767zi-with-lan8742a-ethernet-using-stm32ethernet-library)
    * [1.1 Normal run](#11-normal-run)
    * [1.2. Restart after Config Portal](#12-restart-after-config-portal)
  * [2. Ethernet_STM32 on STM32F7 NUCLEO_F767ZI with W5500 Ethernet using Ethernet_Generic Library](#2-ethernet_stm32-on-stm32f7-nucleo_f767zi-with-w5500-ethernet-using-Ethernet_Generic-library)
    * [2.1 Normal run with TO_LOAD_DEFAULT_CONFIG_DATA = true](#21-normal-run-with-to_load_default_config_data--true)
    * [2.2. DRD detected](#22-drd-detected)
    * [2.3. Restart after Config Portal](#23-restart-after-config-portal)
  * [3. MQTT_ThingStream_Ethernet_STM32 on STM32F7 NUCLEO_F767ZI with ENC28J60 Ethernet using EthernetENC Library](#3-mqtt_thingstream_ethernet_stm32-on-stm32f7-nucleo_f767zi-with-enc28j60-ethernet-using-ethernetenc-library)
    * [3.1 Normal run without correct ThingStream MQTT Credentials](#31-normal-run-without-correct-thingstream-mqtt-credentials)
    * [3.2. Got correct ThingStream MQTT Credentials from Config Portal](#32-got-correct-thingstream-mqtt-credentials-from-config-portal)
  * [4. Ethernet_STM32 on STM32F7 NUCLEO_F767ZI with W5x00 Ethernet using Ethernet_Generic Library](#4-ethernet_stm32-on-stm32f7-nucleo_f767zi-with-w5x00-ethernet-using-Ethernet_Generic-library)
    * [4.1 Normal run](#41-normal-run)
  * [5. MQTT_ThingStream_Ethernet_STM32 on STM32F7 NUCLEO_F767ZI with LAN8742A Ethernet using STM32Ethernet Library](#5-mqtt_thingstream_ethernet_stm32-on-stm32f7-nucleo_f767zi-with-lan8742a-ethernet-using-stm32ethernet-library)
    * [5.1. Normal run without correct ThingStream MQTT Credentials](#51-normal-run-without-correct-thingstream-mqtt-credentials)
    * [5.2. Got correct ThingStream MQTT Credentials from Config Portal](#52-got-correct-thingstream-mqtt-credentials-from-config-portal)
  * [6. MQTT_ThingStream_Ethernet_STM32_LAN8720 on STM32F4 BLACK_F407VE with LAN8720 Ethernet using STM32Ethernet Library](#6-mqtt_thingstream_ethernet_stm32_lan8720-on-stm32f4-black_f407ve-with-lan8720-ethernet-using-stm32ethernet-library)
    * [6.1. Normal run without correct ThingStream MQTT Credentials](#61-normal-run-without-correct-thingstream-mqtt-credentials)
    * [6.2. Got correct ThingStream MQTT Credentials from Config Portal](#62-got-correct-thingstream-mqtt-credentials-from-config-portal) 
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [Ethernet_Manager_STM32 library](https://github.com/khoih-prog/Ethernet_Manager_STM32)

#### Features

- This is the new library, adding to the current WiFiManager/Ethernet_Manager sets of libraries. It's designed to help you eliminate `hardcoding` your Credentials in **STM32F/L/H/G/WB/MP1 boards using Ethernet shields (W5100, W5200, W5500, ENC28J60, LAN8720, built-in LAN8742A Ethernet)**. It's currently **not supporting SSL**. Will support soon.
- You can update Credentials any time you need to change via Configure Portal. Data are saved in configurable locations in EEPROM.
- **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
- Configurable **Config Portal Title** to be either BoardName or default undistinguishable names.
- Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device. Example [**MQTT_ThingStream_Ethernet_STM32**](examples/MQTT_ThingStream_Ethernet_STM32) will demonstrate how to use the dynamic parameters, entered via Config Portal, to connect to **ThingStream MQTT Server** at `mqtt.thingstream.io`.

New recent features:

- **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
- Configurable **Config Portal Title** to be either BoardName or default undistinguishable names.
- Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device

---

#### Currently supported Boards

1. **STM32 boards with built-in Ethernet LAN8742A** such as :

  - **Nucleo-144 (F429ZI, F767ZI)**
  - **Discovery (STM32F746G-DISCOVERY)**
  - **All STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash, with Built-in Ethernet**
  - See [EthernetWebServer_STM32 Support and Test Results](https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
  
2. **STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running W5x00 or ENC28J60 shields)**

- Nucleo-144
- Nucleo-64
- Discovery
- Generic STM32F0, STM32F1, STM32F2, STM32F3, STM32F4, STM32F7 (with 64+K Flash): x8 and up
- STM32L0, STM32L1, STM32L4
- STM32G0, STM32G4
- STM32H7
- STM32WB
- STM32MP1
- LoRa boards
- 3-D printer boards
- Generic Flight Controllers
- Midatronics boards

3. **STM32 boards using Ethernet LAN8720** such as :

  - **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
  - **Discovery (DISCO_F746NG)**
  - **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**
 
 ---
 
#### Currently Supported Ethernet shields/modules:

1. Built-in Ethernet LAN8742A using [`STM32Ethernet library`](https://github.com/stm32duino/STM32Ethernet)
2. W5x00 using [`Ethernet_Generic`](https://github.com/khoih-prog/Ethernet_Generic) library
3. ENC28J60 using [`EthernetENC`](https://github.com/jandrassy/EthernetENC) or [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
4. LAN8720 using [`STM32Ethernet`](https://github.com/stm32duino/STM32Ethernet) and [`LwIP`](https://github.com/stm32duino/LwIP) libraries.

#### Not supported boards

These boards are not supported:

- Some Nucleo-32 (small Flash/memory)
- Eval (no Serial, just need to redefine in sketch, library and UIPEthernet)
- Generic STM32F0 (small Flash/memory)
- Generic STM32F1 (with 64-K Flash): C6
- Generic STM32F3 : no HardwareSPI.h
- Electronics Speed Controllers (small Flash/memory)

---
---


## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Arduino Core for STM32 v2.3.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32 boards. [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest)
 3. [`EthernetWebServer_STM32 library v1.5.0+`](https://github.com/khoih-prog/EthernetWebServer_STM32). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32)
 4. [`FlashStorage_STM32 library v1.2.0+`](https://github.com/khoih-prog/FlashStorage_STM32) for STM32 boards other than STM32F1. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/FlashStorage_STM32.svg?)](https://www.ardu-badge.com/FlashStorage_STM32)
 5. [`FlashStorage_STM32F1 library v1.1.0+`](https://github.com/khoih-prog/FlashStorage_STM32F1) for STM32F1 boards with 64KB+ Flash (STM32F1C8, STM32F1CB, etc.). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/FlashStorage_STM32F1.svg?)](https://www.ardu-badge.com/FlashStorage_STM32F1)
 6. [`Functional-Vlpp library v1.0.2+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
 7. [`DoubleResetDetector_Generic library v1.8.1+`](https://github.com/khoih-prog/DoubleResetDetector_Generic). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/DoubleResetDetector_Generic.svg?)](https://www.ardu-badge.com/DoubleResetDetector_Generic).
 8. For LAN8720 or built-in LAN8742A Ethernet:
   - [`STM32Ethernet library v1.3.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32Ethernet.svg)](https://github.com/stm32duino/STM32Ethernet/releases/latest)
   - [`LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/LwIP.svg)](https://github.com/stm32duino/LwIP/releases/latest)
 9. For W5x00 Ethernet:
   - [`Ethernet_Generic library v2.7.1+`](https://github.com/khoih-prog/Ethernet_Generic) for W5100, W5200 and W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip.  [![GitHub release](https://img.shields.io/github/release/khoih-prog/Ethernet_Generic.svg)](https://github.com/khoih-prog/Ethernet_Generic/releases/latest)
10. For ENC28J60 Ethernet:
   - [`EthernetENC library v2.0.3+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**
   - [`UIPEthernet library v2.0.12+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/UIPEthernet/UIPEthernet.svg)](https://github.com/UIPEthernet/UIPEthernet/releases/latest)
   
---

### Installation

The suggested way to install is to:

#### Use Arduino Library Manager

The best way is to use `Arduino Library Manager`. Search for `Ethernet_Manager_STM32`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/Ethernet_Manager_STM32.svg?)](https://www.ardu-badge.com/Ethernet_Manager_STM32) for more detailed instructions.

### Manual Install

1. Navigate to [Ethernet_Manager_STM32](https://github.com/khoih-prog/Ethernet_Manager_STM32) page.
2. Download the latest release `Ethernet_Manager_STM32-main.zip`.
3. Extract the zip file to `Ethernet_Manager_STM32-main` directory 
4. Copy the whole `Ethernet_Manager_STM32-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**Ethernet_Manager_STM32** library](https://registry.platformio.org/libraries/khoih-prog/Ethernet_Manager_STM32) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/Ethernet_Manager_STM32/installation). Search for Ethernet_Manager_STM32 in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Packages' Patches

#### 1. For STM32 boards to use LAN8720

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.2.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.2.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 2.2.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
these files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h


#### 2. For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/2.3.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.3.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 2.3.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
these files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h`

---

### Libraries' Patches

#### 1. For application requiring 2K+ HTML page

If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

#### 2. For Ethernet library

To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

#### 3. For EthernetLarge library

To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)


#### 4. For Ethernet2 library

To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for the [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

#### 5. For Ethernet3 library

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

#### 6. For UIPEthernet library

***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
- [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)


---
---


### HOWTO Fix `Multiple Definitions` Linker Error

The current library implementation, using `xyz-Impl.h` instead of standard `xyz.cpp`, possibly creates certain `Multiple Definitions` Linker error in certain use cases.

You can use

```cpp
#include <Ethernet_Manager_STM32.hpp>               //https://github.com/khoih-prog/Ethernet_Manager_STM32
```

in many files. But be sure to use the following `#include <NTPClient_Generic.h>` **in just 1 `.h`, `.cpp` or `.ino` file**, which must **not be included in any other file**, to avoid `Multiple Definitions` Linker Error

```cpp
// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include <Ethernet_Manager_STM32.h>                //https://github.com/khoih-prog/Ethernet_Manager_STM32
```

Check [multiFileProject](examples/multiFileProject) for a demo how to avoid `multiple-definitions` linker error for multiple-file project


---
---

## Configuration Notes

### 1. How to select which built-in Ethernet or shield to use

#### Select **one and only one** Ethernet library to use as follows:

- Standard W5x00 Ethernet_Generic Library 

Standard W5x00 using Ethernet_Generic library is used by default, in the sketch, just be sure to comment out or leave these #defines to be false :

```cpp
// Only one if the following to be true
#define USE_BUILTIN_ETHERNET  false
#define USE_ETHERNET_GENERIC  false
#define USE_ETHERNET_ENC      false
#define USE_UIP_ETHERNET      false
#define USE_CUSTOM_ETHERNET   false
```

#### To use built-in LAN8742A

```cpp
// Only one if the following to be true
#define USE_BUILTIN_ETHERNET  true
#define USE_ETHERNET_GENERIC  false
#define USE_ETHERNET_ENC      false
#define USE_UIP_ETHERNET      false
#define USE_CUSTOM_ETHERNET   false
```

#### To use LAN8720

```cpp
#define USING_LAN8720         true

// Only one if the following to be true
#define USE_BUILTIN_ETHERNET  true
#define USE_ETHERNET_GENERIC  false
#define USE_ETHERNET_ENC      false
#define USE_UIP_ETHERNET      false
#define USE_CUSTOM_ETHERNET   false
```

#### To use W5x00 Ethernet, for example using Ethernet_Generic library

```cpp
// Only one if the following to be true
#define USE_BUILTIN_ETHERNET  true
#define USE_ETHERNET_GENERIC  false
#define USE_ETHERNET_ENC      false
#define USE_UIP_ETHERNET      false
#define USE_CUSTOM_ETHERNET   false
```

#### To use ENC28J60 Ethernet, using EthernetENC library (**NEW and Better**)

```cpp
// Only one if the following to be true
#define USE_BUILTIN_ETHERNET  false
#define USE_ETHERNET_GENERIC  false
#define USE_ETHERNET_ENC      true
#define USE_UIP_ETHERNET      false
#define USE_CUSTOM_ETHERNET   false
```

#### To use ENC28J60 Ethernet, using UIPEthernet library

```cpp
// Only one if the following to be true
#define USE_BUILTIN_ETHERNET  false
#define USE_ETHERNET_GENERIC  false
#define USE_ETHERNET_ENC      false
#define USE_UIP_ETHERNET      true
#define USE_CUSTOM_ETHERNET   false
```


- To use another Ethernet library
For example, Ethernet_XYZ library uses **Ethernet_XYZ.h**

```cpp
// Only one if the following to be true
#define USE_BUILTIN_ETHERNET  false
#define USE_ETHERNET_GENERIC  false
#define USE_ETHERNET_ENC      false
#define USE_UIP_ETHERNET      false
#define USE_CUSTOM_ETHERNET   true

....

#elif USE_CUSTOM_ETHERNET
  //#include "Ethernet_XYZ.h"
  #include "EthernetLarge.h"
  #warning Using Custom Ethernet library. You must include a library and initialize.
  #define SHIELD_TYPE           "Custom Ethernet & Ethernet_XYZ Library"
#else
  #define USE_ETHERNET_GENERIC          true
  #include "Ethernet_Generic.h"
  #warning Using Ethernet_Generic lib
  #define SHIELD_TYPE           "W5x00 & Ethernet_Generic Library"
#endif  
...

#include <Ethernet_Manager_STM32.h>
```

---

### Important:

- The **Ethernet_Shield_W5200, EtherCard, EtherSia  libraries are not supported**. Don't use unless you know how to modify those libraries.
- Requests to support for any future custom Ethernet library will be ignored. **Use at your own risk**.

---

#### 2. How to select another CS/SS pin to use

The default CS/SS pin is 10 for all boards.

If the default pin is not correct, the easiest way is to change is to select the CS/SS pin (e.g. 22) to use as follows:

```cpp
// To override the default CS/SS pin. Don't use unless you know exactly which pin to use
#define USE_THIS_SS_PIN   22
```

#### 3. How to increase W5x00 TX/RX buffer

- For **Ethernet_Generic** library only,  simply use as follows to have large buffer similar to EthernetLarge library

```cpp
#define ETHERNET_LARGE_BUFFERS
```

- For **Ethernet3** library only,  use as follows

```cpp
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
  #ifndef ETHERNET3_MAX_SOCK_NUM
    #define ETHERNET3_MAX_SOCK_NUM      4
  #endif
  
  Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
```

---


### How to use default Credentials and have them pre-loaded onto Config Portal

See this example and modify as necessary

1. To load [Default Credentials](examples/Ethernet_Generic/Credentials.h)
```
bool LOAD_DEFAULT_CONFIG_DATA = true;
```

2. To use system default to load "blank" when there is no valid Credentials

```cpp
bool LOAD_DEFAULT_CONFIG_DATA = false;
```

3. Example of [Default Credentials](examples/Ethernet_Generic/Credentials.h)

```cpp
/// Start Default Config Data //////////////////

/*
typedef struct Configuration
{
  char header         [16];
  char static_IP      [16];
  char board_name     [24];
  int  checkSum;
} Ethernet_Configuration;
*/

#define TO_LOAD_DEFAULT_CONFIG_DATA      true

#if TO_LOAD_DEFAULT_CONFIG_DATA

bool LOAD_DEFAULT_CONFIG_DATA = false;

Ethernet_Configuration defaultConfig =
{
  //char header[16], dummy, not used
#if USE_SSL
  "Eth_SSL",
#else
  "Eth_NonSSL",
#endif

  // char static_IP      [16];
  //"192.168.2.230",
  // Use dynamic DHCP IP
  "",
  //char board_name     [24];
  "STM32-Ethernet",
  // terminate the list
  //int  checkSum, dummy, not used
  0
  /////////// End Default Config Data /////////////
};

#else

bool LOAD_DEFAULT_CONFIG_DATA = false;

Ethernet_Configuration defaultConfig;

#endif    // TO_LOAD_DEFAULT_CONFIG_DATA

/////////// End Default Config Data /////////////
```

---
---

### How to use

#### 1. Basic usage

- Include in your sketch

```cpp
// Must be before #include <Ethernet_Manager.h>
#include <Ethernet_Manager.h>

Ethernet_Manager ethernet_manager;
```

#### 2. Add custom parameters

- To add custom parameters, just add

```cpp
#ifndef dynamicParams_h
#define dynamicParams_h

#include "defines.h"

// USE_DYNAMIC_PARAMETERS defined in defined.h

/////////////// Start dynamic Credentials ///////////////

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

```

#### 3. Not using custom parameters

- If you don't need to add dynamic parameters, use the following in sketch

```cpp
#define USE_DYNAMIC_PARAMETERS      false
```

#### 4. To open Config Portal

- When you want to open a config portal, just add

```cpp
ethernet_manager.begin();
```

#### 5. To use custom HTML Style

```cpp
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";

...

ethernet_manager.setCustomsStyle(NewCustomsStyle);
```

#### 6. To use custom Head Elements


```cpp
ethernet_manager.setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
```

#### 7. To use CORS Header

```cpp
ethernet_manager.setCORSHeader("Your Access-Control-Allow-Origin");
```

---
---

### Important Notes for using Dynamic Parameters' ids

1. These ids (such as "mqtt" in example) must be **unique**.

Please be noted that the following **reserved names are already used in library**:

```
"ip"    for Static IP Address
"nm"    for Board Name
```

---
---

### HOWTO use STM32F4 with LAN8720

#### 1. Wiring

This is the Wiring for STM32F4 (BLACK_F407VE, etc.) using LAN8720


|LAN8720 PHY|<--->|STM32F4|
|:-:|:-:|:-:|
|TX1|<--->|PB_13|
|TX_EN|<--->|PB_11|
|TX0|<--->|PB_12|
|RX0|<--->|PC_4|
|RX1|<--->|PC_5|
|nINT/RETCLK|<--->|PA_1|
|CRS|<--->|PA_7|
|MDIO|<--->|PA_2|
|MDC|<--->|PC_1|
|GND|<--->|GND|
|VCC|<--->|+3.3V|

---

#### 2. HOWTO program using STLink V-2 or V-3

Connect as follows. To program, use **STM32CubeProgrammer** or Arduino IDE with 

- **U(S)ART Support: "Enabled (generic Serial)"**
- **Upload Method : "STM32CubeProgrammer (SWD)"**


|STLink|<--->|STM32F4|
|:-:|:-:|:-:|
|SWCLK|<--->|SWCLK|
|SWDIO|<--->|SWDIO|
|RST|<--->|NRST|
|GND|<--->|GND|
|5v|<--->|5V|


<p align="center">
    <img src="https://github.com/khoih-prog/Ethernet_Manager_STM32/raw/main/pics/STM32F407VET6.png">
</p>

---

#### 3. HOWTO use Serial Port for Debugging

Connect FDTI (USB to Serial) as follows:

|FDTI|<--->|STM32F4|
|:-:|:-:|:-:|
|RX|<--->|TX=PA_9|
|TX|<--->|RX=PA_10|
|GND|<--->|GND|


---
---

### Examples

 1. [AM2315_Ethernet_STM32](examples/AM2315_Ethernet_STM32)
 2. [DHT11_Ethernet_STM32](examples/DHT11_Ethernet_STM32)
 3. [Ethernet_STM32](examples/Ethernet_STM32) 
 4. [MQTT_ThingStream_Ethernet_STM32](examples/MQTT_ThingStream_Ethernet_STM32)
 5. [AM2315_Ethernet_STM32_LAN8720](examples/AM2315_Ethernet_STM32_LAN8720)
 6. [DHT11_Ethernet_STM32_LAN8720](examples/DHT11_Ethernet_STM32_LAN8720)
 7. [Ethernet_STM32_LAN8720](examples/Ethernet_STM32_LAN8720) 
 8. [MQTT_ThingStream_Ethernet_STM32_LAN8720](examples/MQTT_ThingStream_Ethernet_STM32_LAN8720)
 9. [multiFileProject](examples/multiFileProject) **New**
 
 
---
---

## So, how it works?

If no valid config data are stored in EEPROM, it will switch to `Configuration Mode`. Connect to access point at the IP address displayed on Terminal or Router's DHCP server as in the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/Ethernet_Manager_STM32/raw/main/pics/ConfigPortal.png">
</p>

After you connected to, for example, `192.168.2.86`, the Browser will display the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/Ethernet_Manager_STM32/raw/main/pics/ConfigPortal_Filled.png">
</p>

Enter your credentials (Blynk Servers/Tokens and Port). If you prefer static IP, input it (for example `192.168.2.222`) in the corresponding field. Otherwise, just leave it `blank` or `nothing` to use auto IP assigned by DHCP server.

<p align="center">
    <img src="https://github.com/khoih-prog/Ethernet_Manager_STM32/raw/main/pics/ConfigPortal_ThingStream.png">
</p>

Then click `Save`. After the  board auto-restarted, you will see if it's connected to your Blynk server successfully as in  the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/Ethernet_Manager_STM32/raw/main/pics/Saved.png">
</p>

This `Ethernet_Manager_STM32.run()` is not a blocking call, so you can use it for critical functions requiring in loop(). 

In operation, if Ethernet or connection is lost, `Ethernet_Manager_STM32.run()` will try reconnecting automatically. Therefore, `Ethernet_Manager_STM32.run()` must be called in the `loop()` function.

```cpp
void loop()
{
  Ethernet_Manager_STM32.run();
  ...
}
```

---
---

### Example [MQTT_ThingStream_Ethernet_STM32](examples/MQTT_ThingStream_Ethernet_STM32)

#### 1. File [MQTT_ThingStream_Ethernet_STM32.ino](examples/MQTT_ThingStream_Ethernet_STM32/MQTT_ThingStream_Ethernet_STM32.ino)

https://github.com/khoih-prog/Ethernet_Manager_STM32/blob/34955150516bfc8ae418a554f9b879037b3e86f5/examples/MQTT_ThingStream_Ethernet_STM32/MQTT_ThingStream_Ethernet_STM32.ino#L12-L403


#### 2. File [defines.h](examples/MQTT_ThingStream_Ethernet_STM32/defines.h)


https://github.com/khoih-prog/Ethernet_Manager_STM32/blob/34955150516bfc8ae418a554f9b879037b3e86f5/examples/MQTT_ThingStream_Ethernet_STM32/defines.h#L12-L141



#### 3. File [Credentials.h](examples/MQTT_ThingStream_Ethernet_STM32/Credentials.h)

https://github.com/khoih-prog/Ethernet_Manager_STM32/blob/34955150516bfc8ae418a554f9b879037b3e86f5/examples/MQTT_ThingStream_Ethernet_STM32/Credentials.h#L12-L66


#### 4. File [dynamicParams.h](examples/MQTT_ThingStream_Ethernet_STM32/dynamicParams.h)

https://github.com/khoih-prog/Ethernet_Manager_STM32/blob/34955150516bfc8ae418a554f9b879037b3e86f5/examples/MQTT_ThingStream_Ethernet_STM32/dynamicParams.h#L12-L72


---
---

### Debug Terminal Output Samples

#### 1. Ethernet_STM32 on STM32F7 NUCLEO_F767ZI with LAN8742A Ethernet using STM32Ethernet Library

This is the terminal output of an STM32F7 Nucleo-144 NUCLEO_F767ZI board with LAN8742A Ethernet & STM32Ethernet Library, running [Ethernet_STM32](examples/Ethernet_STM32) example.

#### 1.1. Normal run

```cpp
Start Ethernet_STM32 on NUCLEO_F767ZI
Ethernet Shield type : LAN8742A Ethernet & STM32Ethernet Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] ======== USE_BUILTIN_ETHERNET ========

(Emulated-)EEPROM size = 16384, start = 0
[ETM] ======= Start Default Config Data =======
[ETM] Header=  , BoardName= 
[ETM] StaticIP= 
[ETM] Header= STM32 , BoardName= blank
[ETM] StaticIP= blank
[ETM] CCSum=0x 569 ,RCSum=0x 0
[ETM] Start connectEthernet using DHCP
[ETM] MAC:FE-9C-FB-DB-DD-BA
[ETM] Dynamic IP OK, connected
[ETM] IP: 192.168.2.242
[ETM] begin:Stay in CfgPortal: No CfgDat
Connected! IP address: 192.168.2.242
H
Your stored Credentials :
MQTT Server = blank
Port = blank
MQTT UserName = blank
MQTT PWD = blank
Subs Topics = blank
Pubs Topics = blank
HHHHHH[ETM] h:Updating EEPROM. Please wait for reset
[ETM] h:Rst
H
```


#### 1.2. Restart after Config Portal

```cpp
Start Ethernet_STM32 on NUCLEO_F767ZI
Ethernet Shield type : LAN8742A Ethernet & STM32Ethernet Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] ======== USE_BUILTIN_ETHERNET ========

(Emulated-)EEPROM size = 16384, start = 0
[ETM] ======= Start Default Config Data =======
[ETM] Header=  , BoardName= 
[ETM] StaticIP= 
[ETM] Header= STM32 , BoardName= STM32_ETM
[ETM] StaticIP= 192.168.2.241
[ETM] CCSum=0x 685 ,RCSum=0x 685
[ETM] Header= STM32 , BoardName= STM32_ETM
[ETM] StaticIP= 192.168.2.241
[ETM] Start connectEthernet using Static IP = 192.168.2.241
[ETM] MAC:FE-9F-F8-EF-ED-BA
[ETM] IP: 192.168.2.241
[ETM] begin:Ethernet Connected.
Connected! IP address: 192.168.2.241

Your stored Credentials :
MQTT Server = mqtt_server
Port = 1883
MQTT UserName = mqtt_user
MQTT PWD = mqtt_pass
Subs Topics = mqtt_sub
Pubs Topics = mqtt_pub
HHHHHHHHHH HHHHHHHHHH HHHHHH
```

---

#### 2. Ethernet_STM32 on STM32F7 NUCLEO_F767ZI with W5500 Ethernet using Ethernet_Generic Library

This is the terminal output of STM32F7 Nucleo-144 NUCLEO_F767ZI board with W5500 Ethernet shield using Ethernet_Generic Library, running [Ethernet_STM32](examples/Ethernet_STM32) example demonstrating **doubleResetDetect feature**.

#### 2.1. Normal run with TO_LOAD_DEFAULT_CONFIG_DATA = true

```cpp
Start Ethernet_STM32 on NUCLEO_F767ZI
Ethernet Shield type : W5x00 using Ethernet_Generic Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] =========================
[ETM] Default SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================
[ETM] Board :NUCLEO_F767ZI, setCsPin:10
[ETM] =========================
[ETM] Currently Used SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================

(Emulated-)EEPROM size = 16384, start = 0
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[ETM] ======= Start Default Config Data =======
[ETM] Header= Eth_NonSSL , BoardName= STM32-Ethernet
[ETM] StaticIP= 
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.222
[ETM] CCSum=0x 8ab ,RCSum=0x 8ab
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.222
[ETM] Start connectEthernet using Static IP = 192.168.2.222
[ETM] MAC:FE-98-FE-DE-D9-BA
```

#### 2.2. DRD detected


```cpp
Start Ethernet_STM32 on NUCLEO_F767ZI
Ethernet Shield type : W5x00 using Ethernet_Generic Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] =========================
[ETM] Default SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================
[ETM] Board :NUCLEO_F767ZI, setCsPin:10
[ETM] =========================
[ETM] Currently Used SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================

(Emulated-)EEPROM size = 16384, start = 0
Flag read = 0xd0d01234
doubleResetDetected
ClearFlag write = 0xd0d04321
[ETM] =====================
[ETM] DRD. Run ConfigPortal
[ETM] =====================
[ETM] ======= Start Default Config Data =======
[ETM] Header= Eth_NonSSL , BoardName= STM32-Ethernet
[ETM] StaticIP= 
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.222
[ETM] CCSum=0x 8ab ,RCSum=0x 8ab
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.222
[ETM] Start connectEthernet using Static IP = 192.168.2.222
[ETM] MAC:FE-9A-FD-D6-D9-BA

W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5500, SSIZE =4096
[ETM] IP: 192.168.2.222
[ETM] begin:Stay in CfgPortal: DRD
Connected! IP address: 192.168.2.222
Ethernet type is W5500

Your stored Credentials :
MQTT Server = mqtt_server
Port = 1883
MQTT UserName = mqtt_user
MQTT PWD = mqtt_pass
Subs Topics = mqtt_sub
Pubs Topics = mqtt_pub
H[ETM] h:Updating EEPROM. Please wait for reset
[ETM] h:Rst
H
```

#### 2.3. Restart after Config Portal

```cpp
Start Ethernet_STM32 on NUCLEO_F767ZI
Ethernet Shield type : W5x00 using Ethernet_Generic Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] =========================
[ETM] Default SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================
[ETM] Board :NUCLEO_F767ZI, setCsPin:10
[ETM] =========================
[ETM] Currently Used SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================

(Emulated-)EEPROM size = 16384, start = 0
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[ETM] ======= Start Default Config Data =======
[ETM] Header= Eth_NonSSL , BoardName= STM32-Ethernet
[ETM] StaticIP= 
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.222
[ETM] CCSum=0x 8ab ,RCSum=0x 8ab
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.222
[ETM] Start connectEthernet using Static IP = 192.168.2.222
[ETM] MAC:FE-98-FE-DE-DC-BA

W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5500, SSIZE =4096
[ETM] IP: 192.168.2.222
[ETM] begin:Ethernet Connected.
Connected! IP address: 192.168.2.222
Ethernet type is W5500

Your stored Credentials :
MQTT Server = mqtt_server
Port = 1883
MQTT UserName = mqtt_user
MQTT PWD = mqtt_pass
Subs Topics = mqtt_sub
Pubs Topics = mqtt_pub
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
HH
```

---

#### 3. MQTT_ThingStream_Ethernet_STM32 on STM32F7 NUCLEO_F767ZI with ENC28J60 Ethernet using EthernetENC Library

This is the terminal output of STM32F7 Nucleo-144 NUCLEO_F767ZI board with ENC28J60 using EthernetENC Library, running complex [MQTT_ThingStream_Ethernet_STM32](examples/MQTT_ThingStream_Ethernet_STM32) example to demonstrate how to use dynamic parameters, entered via Config Portal, to connect to [**ThingStream MQTT Server**](mqtt.thingstream.io).

#### 3.1. Normal run without correct ThingStream MQTT Credentials

```cpp
Start MQTT_ThingStream_Ethernet_STM32 on NUCLEO_F767ZI
Ethernet Shield type : ENC28J60 using EthernetENC Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] =========================
[ETM] Default SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================
[ETM] Board :NUCLEO_F767ZI, setCsPin:10
[ETM] =========================
[ETM] Currently Used SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================

(Emulated-)EEPROM size = 16384, start = 0
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[ETM] ======= Start Default Config Data =======
[ETM] Header= Eth_NonSSL , BoardName= STM32-Ethernet
[ETM] StaticIP= 
[ETM] Header= STM32 , BoardName= F767ZI_ThingStream
[ETM] StaticIP= 192.168.2.222
[ETM] CCSum=0x a38 ,RCSum=0x a38
[ETM] Invalid Stored Dynamic Data. Ignored
[ETM] Start connectEthernet using DHCP
[ETM] MAC:FE-9F-F8-DD-D8-8D
[ETM] Dynamic IP OK, connected
[ETM] IP: 192.168.2.74
[ETM] begin:Stay in CfgPortal: No CfgDat
Connected! IP address: 192.168.2.74
***************************************
esp32-sniffer/12345678/ble
***************************************
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
[ETM] h:Updating EEPROM. Please wait for reset
[ETM] h:Rst
```

#### 3.2. Got correct ThingStream MQTT Credentials from Config Portal

```cpp
Start MQTT_ThingStream_Ethernet_STM32 on NUCLEO_F767ZI
Ethernet Shield type : ENC28J60 using EthernetENC Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] =========================
[ETM] Default SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================
[ETM] Board :NUCLEO_F767ZI, setCsPin:10
[ETM] =========================
[ETM] Currently Used SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================

(Emulated-)EEPROM size = 16384, start = 0
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[ETM] ======= Start Default Config Data =======
[ETM] Header= Eth_NonSSL , BoardName= STM32-Ethernet
[ETM] StaticIP= 
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.222
[ETM] CCSum=0x 8ab ,RCSum=0x 8ab
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.222
[ETM] Start connectEthernet using Static IP = 192.168.2.222
[ETM] MAC:FE-99-FC-DA-DF-BA
[ETM] IP: 192.168.2.222
[ETM] begin:Ethernet Connected.
Connected! IP address: 192.168.2.222
***************************************
esp32-sniffer/12345678/ble
***************************************
Attempting MQTT connection to mqtt.thingstream.io
...connected
Published connection message successfully!
Subscribed to: esp32-sniffer/12345678/ble

Your stored Credentials :
MQTT Server = mqtt.thingstream.io
Port = 1883
MQTT UserName = *******
MQTT PWD = *******
Client ID = *********
HStop doubleResetDetecting
ClearFlag write = 0xd0d04321
MQTT Message Send : esp32-sniffer/12345678/ble => Hello from MQTT_ThingStream on NUCLEO_F767ZI with ENC28J60 using EthernetENC Library
HMQTT Message receive [esp32-sniffer/12345678/ble] Hello from MQTT_ThingStream on NUCLEO_F767ZI with ENC28J60 using EthernetENC Library
HHHH

```

---

#### 4. Ethernet_STM32 on STM32F7 NUCLEO_F767ZI with W5x00 Ethernet using Ethernet_Generic Library

This is the terminal output of STM32F7 Nucleo-144 NUCLEO_F767ZI board with W5x00 using Ethernet_Generic Library, running [Ethernet_STM32](examples/Ethernet_STM32) example to demonstrate the link status operation.

#### 4.1. Normal run 

```cpp
Start Ethernet_STM32 on NUCLEO_F767ZI
Ethernet Shield type : W5x00 using Ethernet_Generic Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] =========================
[ETM] Default SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================
[ETM] Board :NUCLEO_F767ZI, setCsPin:10
[ETM] =========================
[ETM] Currently Used SPI pinout:
[ETM] MOSI:11
[ETM] MISO:12
[ETM] SCK:13
[ETM] SS:10
[ETM] =========================

(Emulated-)EEPROM size = 16384, start = 0
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[ETM] ======= Start Default Config Data =======
[ETM] Header= Eth_NonSSL , BoardName= STM32-Ethernet
[ETM] StaticIP= 
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.222
[ETM] CCSum=0x 8ab ,RCSum=0x 8ab
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.222
[ETM] Start connectEthernet using Static IP = 192.168.2.222
[ETM] MAC:FE-98-FF-D6-D9-BA

W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5500, SSIZE =8192
[ETM] IP: 192.168.2.222
[ETM] begin:Ethernet Connected.
Connected! IP address: 192.168.2.222
Ethernet type is W5500

Your stored Credentials :
MQTT Server = mqtt_server
Port = 1883
MQTT UserName = mqtt_user
MQTT PWD = mqtt_pass
Subs Topics = mqtt_sub
Pubs Topics = mqtt_pub
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
HHFFHHH    **<==== Check connection report by removing Ethernet Cable**
```

---

#### 5. MQTT_ThingStream_Ethernet_STM32 on STM32F7 NUCLEO_F767ZI with LAN8742A Ethernet using STM32Ethernet Library

This is the terminal output of STM32F7 Nucleo-144 NUCLEO_F767ZI board with LAN8742A using STM32Ethernet Library, running complex [MQTT_ThingStream_Ethernet_STM32](examples/MQTT_ThingStream_Ethernet_STM32) example to demonstrate how to use dynamic parameters, entered via Config Portal, to connect to [**ThingStream MQTT Server**](mqtt.thingstream.io).

#### 5.1. Normal run without correct ThingStream MQTT Credentials

```cpp
Start MQTT_ThingStream_Ethernet_STM32 on NUCLEO_F767ZI
Ethernet Shield type : LAN8742A Ethernet & STM32Ethernet Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] ======== USE_BUILTIN_ETHERNET ========

(Emulated-)EEPROM size = 16384, start = 0
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[ETM] ======= Start Default Config Data =======
[ETM] Header= Eth_NonSSL , BoardName= STM32-Ethernet
[ETM] StaticIP= 
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.188
[ETM] CCSum=0x 8b6 ,RCSum=0x 8b6
[ETM] Invalid Stored Dynamic Data. Ignored
[ETM] Start connectEthernet using DHCP
[ETM] MAC:FE-9A-F4-DC-DE-88
[ETM] Dynamic IP OK, connected
[ETM] IP: 192.168.2.69
[ETM] begin:Stay in CfgPortal: No CfgDat
Connected! IP address: 192.168.2.69
***************************************
esp32-sniffer/12345678/ble
***************************************
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
[ETM] h:Updating EEPROM. Please wait for reset
[ETM] h:Rst
```

#### 5.2. Got correct ThingStream MQTT Credentials from Config Portal

```cpp
Start MQTT_ThingStream_Ethernet_STM32 on NUCLEO_F767ZI
Ethernet Shield type : LAN8742A Ethernet & STM32Ethernet Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] ======== USE_BUILTIN_ETHERNET ========

(Emulated-)EEPROM size = 16384, start = 0
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[ETM] ======= Start Default Config Data =======
[ETM] Header= Eth_NonSSL , BoardName= STM32-Ethernet
[ETM] StaticIP= 
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.188
[ETM] CCSum=0x 8b6 ,RCSum=0x 8b6
[ETM] Header= STM32 , BoardName= STM32-Ethernet
[ETM] StaticIP= 192.168.2.188
[ETM] Start connectEthernet using Static IP = 192.168.2.188
[ETM] MAC:FE-99-FF-DF-DB-BA
[ETM] IP: 192.168.2.188
[ETM] begin:Ethernet Connected.
Connected! IP address: 192.168.2.188
***************************************
esp32-sniffer/12345678/ble
***************************************
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
Attempting MQTT connection to mqtt.thingstream.io
...connected
Published connection message successfully!
Subscribed to: esp32-sniffer/12345678/ble
H
Your stored Credentials :
MQTT Server = mqtt.thingstream.io
Port = 1883
MQTT UserName = mqtt_user_name
MQTT PWD = mqtt_password
Client ID = mqtt_clientID

MQTT Message Send : esp32-sniffer/12345678/ble => Hello from MQTT_ThingStream on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library

MQTT Message receive [esp32-sniffer/12345678/ble] Hello from MQTT_ThingStream on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
HH
MQTT Message Send : esp32-sniffer/12345678/ble => Hello from MQTT_ThingStream on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library

MQTT Message receive [esp32-sniffer/12345678/ble] Hello from MQTT_ThingStream on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
HH
MQTT Message Send : esp32-sniffer/12345678/ble => Hello from MQTT_ThingStream on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library

MQTT Message receive [esp32-sniffer/12345678/ble] Hello from MQTT_ThingStream on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
HH
```

---

#### 6. MQTT_ThingStream_Ethernet_STM32_LAN8720 on STM32F4 BLACK_F407VE with LAN8720 Ethernet using STM32Ethernet Library

This is the terminal output of STM32F4 BLACK_F407VE with LAN8720 Ethernet using STM32Ethernet Library, running complex [MQTT_ThingStream_Ethernet_STM32_LAN8720](examples/MQTT_ThingStream_Ethernet_STM32_LAN8720) example to demonstrate how to use dynamic parameters, entered via Config Portal, to connect to [**ThingStream MQTT Server**](mqtt.thingstream.io).

#### 6.1. Normal run without correct ThingStream MQTT Credentials

```cpp
Start MQTT_ThingStream_Ethernet_STM32_LAN8720 on BLACK_F407VE
Ethernet Shield type : LAN8720 Ethernet & STM32Ethernet Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] ======== USE_BUILTIN_ETHERNET ========

(Emulated-)EEPROM size = 16384, start = 0
Flag read = 0xd0d01234
doubleResetDetected
ClearFlag write = 0xd0d04321
[ETM] =====================
[ETM] DRD. Run ConfigPortal
[ETM] =====================
[ETM] EEPROMsz:4096
[ETM] EEPROM Length():16384
[ETM] CCSum=0x77e,RCSum=0x77e
[ETM] ChkCrR:CrCCsum=0x215e,CrRCsum=0x215e
[ETM] CrCCSum=215e,CrRCSum=215e
[ETM] Valid Stored Dynamic Data
[ETM] ======= Start Stored Config Data =======
[ETM] Header=STM32, BoardName=STM32-Ethernet
[ETM] StaticIP=
[ETM] Start connectEthernet using DHCP
[ETM] MAC:FE-98-FD-D6-DB-BA
[ETM] Dynamic IP OK, connected
[ETM] IP:192.168.2.149
[ETM] bg: isForcedConfigPortal = false
[ETM] bg:Stay forever in CP:DRD/MRD
Connected! IP address: 192.168.2.149
***************************************
esp32-sniffer/12345678/ble
***************************************
[ETM] h:Updating EEPROM. Please wait for reset
[ETM] SaveEEPROM,Sz=16384,DataSz=248,WCSum=0x8a9
[ETM] CrCCSum=0x2785
[ETM] h:Rst
```

#### 6.2. Got correct ThingStream MQTT Credentials from Config Portal

```cpp
Start MQTT_ThingStream_Ethernet_STM32_LAN8720 on BLACK_F407VE
Ethernet Shield type : LAN8720 Ethernet & STM32Ethernet Library
Ethernet_Manager_STM32 v1.3.2
DoubleResetDetector_Generic v1.8.1
[ETM] ======== USE_BUILTIN_ETHERNET ========

(Emulated-)EEPROM size = 16384, start = 0
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[ETM] EEPROMsz:4096
[ETM] EEPROM Length():16384
[ETM] CCSum=0x8a9,RCSum=0x8a9
[ETM] ChkCrR:CrCCsum=0x2785,CrRCsum=0x2785
[ETM] CrCCSum=2785,CrRCSum=2785
[ETM] Valid Stored Dynamic Data
[ETM] ======= Start Stored Config Data =======
[ETM] Header=STM32, BoardName=STM32-Ethernet
[ETM] StaticIP=192.168.2.220
[ETM] Start connectEthernet using Static IP =192.168.2.220
[ETM] MAC:FE-98-FD-D6-DF-BA
[ETM] IP:192.168.2.220
[ETM] begin:Ethernet Connected.
Connected! IP address: 192.168.2.220
***************************************
esp32-sniffer/12345678/ble
***************************************

Your stored Credentials :
MQTT Server = mqtt.thingstream.io
Port = 1883
MQTT UserName = user_name
MQTT PWD = password
Client ID = device:12345678-1234-1234-1234-123456789abc
Attempting MQTT connection to mqtt.thingstream.io
...connected
Published connection message successfully!
Subscribed to: esp32-sniffer/12345678/ble
HStop doubleResetDetecting
ClearFlag write = 0xd0d04321

MQTT Message Send : esp32-sniffer/12345678/ble => Hello from MQTT_ThingStream on BLACK_F407VE with LAN8720 Ethernet & STM32Ethernet Library
H
MQTT Message receive [esp32-sniffer/12345678/ble] Hello from MQTT_ThingStream on BLACK_F407VE with LAN8720 Ethernet & STM32Ethernet Library
```

---
---

### Debug

Debug is enabled by default on Serial.

You can also change the debugging level from 0 to 4

```cpp
/* Comment this out to disable prints and save space */
#define ETHERNET_MANAGER_STM32_DEBUG_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_           0
#define _ETHERNET_MANAGER_STM32_LOGLEVEL_       2

#define DRD_GENERIC_DEBUG                       true
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.

---
---

### Issues ###

Submit issues to: [Ethernet_Manager_STM32 issues](https://github.com/khoih-prog/Ethernet_Manager_STM32/issues)

---

### TO DO

1. Same features for other boards with new Ethernet shields.
2. Add SSL/TLS feature.
3. Bug Searching and Killing
4. Support more non-compatible Ethernet Libraries such as Ethernet_Shield_W5200, EtherCard, EtherSia.

### DONE

 1. Permit EEPROM size and location configurable to avoid conflict with others.
 2. More flexible to configure reconnection timeout.
 3. For fresh config data, don't need to wait for connecting timeout before entering config portal.
 4. If the config data not entered completely (Serves, HardwarePort and Blynk tokens), entering config portal
 5. Change Synch XMLHttpRequest to Async
 6. Reduce memory usage.
 7. Support ENC28J60 as well as W5100/W5200/W5500 Ethernet shields
 8. Add checksums
 9. Support STM32F/L/H/G/WB/MP1 boards
10. Easy-to-use **Dynamic Parameters** without the necessity to write complicated ArduinoJSon functions
11. Permit to input special chars such as **%** and **#** into data fields.
12. **DoubleDetectDetector** to force Config Portal when double reset is detected within predetermined time, default 10s.
13. Configurable Config Portal Title
14. Re-structure all examples to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
15. Add support to new [**`EthernetENC library`**](https://github.com/jandrassy/EthernetENC) for ENC28J60.
16. Add Table of Contents and Version String
17. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header
18. Add support to **Ethernet LAN8720** using [STM32Ethernet library](https://github.com/stm32duino/STM32Ethernet), for boards such as **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG), Discovery (DISCO_F746NG)** and **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**
19. Use new [**Ethernet_Generic** library](https://github.com/khoih-prog/Ethernet_Generic) as default for W5x00.
20. Add example [multiFileProject](examples/multiFileProject) to demo how to avoid `multiple-definitions` linker error for multiple-file project

---

### Contributions and Thanks

1. Thanks to [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing.

<table>
  <tr>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>⭐️ Miguel Wisintainer</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/Ethernet_Manager_STM32/blob/main/LICENSE)

---

### Copyright

Copyright (c) 2020- Khoi Hoang


