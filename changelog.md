## Ethernet_Manager_STM32

[![arduino-library-badge](https://www.ardu-badge.com/badge/Ethernet_Manager_STM32.svg?)](https://www.ardu-badge.com/Ethernet_Manager_STM32)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Ethernet_Manager_STM32.svg)](https://github.com/khoih-prog/Ethernet_Manager_STM32/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Ethernet_Manager_STM32/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Ethernet_Manager_STM32.svg)](http://github.com/khoih-prog/Ethernet_Manager_STM32/issues)

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.3.1](#releases-v131)
  * [Releases v1.3.0](#releases-v130)
  * [Major Releases v1.2.0](#major-releases-v120)
  * [Releases v1.0.1](#releases-v101)
  * [Releases v1.0.0](#releases-v100)

---
---

## Changelog

### Releases v1.3.1

1. Update `platform.ini` and `library.json` to use original `khoih-prog` instead of `khoih.prog` after PIO fix
2. Update `Packages' Patches`

### Releases v1.3.0

1. Add support to **LAN8720** Ethernet for many **STM32F4** (F407xx, NUCLEO_F429ZI) and **STM32F7** (DISCO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG) boards.
2. Add LAN8720 examples
3. Add Packages' Patches for STM32 to use LAN8720 with STM32Ethernet and LwIP libraries

### Major Releases v1.2.0

1. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header.
2. Add functions to control Config Portal from software or Virtual Switches. Check [How to trigger a Config Portal from code #25](https://github.com/khoih-prog/Blynk_WM/issues/25)
3. Use more efficient [**FlashStorage_STM32 v1.0.1**](https://github.com/khoih-prog/FlashStorage_STM32)
4. Fix Config Portal Bug. 
5. Update examples
6. Bump up to version v1.2.0 to sync with [**Ethernet_Manager**](https://github.com/khoih-prog/Ethernet_Manager)

### Releases v1.0.1

1. Clean-up all compiler warnings possible.
2. Add Table of Contents

### Releases v1.0.0

1. Initial coding to support STM32F/L/H/G/WB/MP1.
2. Provide support to W5x00, ENC28J60 and built-in LAN8742A Ethernet.
3. Supporting Ethernet, EthernetLarge, Ethernet2, Ethernet3, EthernetENC, UIPEthernet and STM32Ethernet Libraries

