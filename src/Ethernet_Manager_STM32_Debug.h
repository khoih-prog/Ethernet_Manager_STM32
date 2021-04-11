/****************************************************************************************************************************
  Ethernet_Manager_STM32_Debug.h
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

#pragma once

#ifndef Ethernet_Manager_STM32_Debug
#define Ethernet_Manager_STM32_Debug

#ifdef ETHERNET_MANAGER_STM32_DEBUG_PORT
  #define ETM_DBG_PORT      ETHERNET_MANAGER_STM32_DEBUG_PORT
#else
  #define ETM_DBG_PORT      Serial
#endif

// Change _ETHERNET_MANAGER_STM32_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _ETHERNET_MANAGER_STM32_LOGLEVEL_
  #define _ETHERNET_MANAGER_STM32_LOGLEVEL_       0
#endif

const char ETM_MARK[] = "[ETM] ";

#define ETM_PRINT        ETM_DBG_PORT.print
#define ETM_PRINTLN      ETM_DBG_PORT.println

#define ETM_PRINT_MARK   ETM_PRINT(ETM_MARK)

////////////////////////////////////////////////////

#define ETM_LOGERROR0(x)        if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>0) { ETM_PRINT(x); }
#define ETM_LOGERROR(x)         if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>0) { ETM_PRINT_MARK; ETM_PRINTLN(x); }
#define ETM_LOGERROR1(x,y)      if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>0) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINTLN(y); }
#define ETM_LOGERROR2(x,y,z)    if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>0) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINTLN(z); }
#define ETM_LOGERROR3(x,y,z,w)  if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>0) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINT(z); ETM_PRINTLN(w); }
#define ETM_LOGERROR5(x,y,z,w,xx,yy) if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>0) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINT(z); ETM_PRINT(w); ETM_PRINT(xx); ETM_PRINTLN(yy); }

////////////////////////////////////////////////////

#define ETM_LOGWARN0(x)         if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>1) { ETM_PRINT(x); }
#define ETM_LOGWARN(x)          if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>1) { ETM_PRINT_MARK; ETM_PRINTLN(x); }
#define ETM_LOGWARN1(x,y)       if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>1) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINTLN(y); }
#define ETM_LOGWARN2(x,y,z)     if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>1) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINTLN(z); }
#define ETM_LOGWARN3(x,y,z,w)   if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>1) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINT(z); ETM_PRINTLN(w); }
#define ETM_LOGWARN5(x,y,z,w,xx,yy) if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>1) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINT(z); ETM_PRINT(w); ETM_PRINT(xx); ETM_PRINTLN(yy); }

////////////////////////////////////////////////////

#define ETM_LOGINFO0(x)         if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>2) { ETM_PRINT(x); }
#define ETM_LOGINFO(x)          if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>2) { ETM_PRINT_MARK; ETM_PRINTLN(x); }
#define ETM_LOGINFO1(x,y)       if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>2) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINTLN(y); }
#define ETM_LOGINFO2(x,y,z)     if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>2) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINTLN(z); }
#define ETM_LOGINFO3(x,y,z,w)   if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>2) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINT(z); ETM_PRINTLN(w); }
#define ETM_LOGINFO5(x,y,z,w,xx,yy) if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>2) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINT(z); ETM_PRINT(w); ETM_PRINT(xx); ETM_PRINTLN(yy); }

////////////////////////////////////////////////////

#define ETM_LOGDEBUG0(x)        if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>3) { ETM_PRINT(x); }
#define ETM_LOGDEBUG(x)         if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>3) { ETM_PRINT_MARK; ETM_PRINTLN(x); }
#define ETM_LOGDEBUG1(x,y)      if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>3) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINTLN(y); }
#define ETM_LOGDEBUG2(x,y,z)    if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>3) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINTLN(z); }
#define ETM_LOGDEBUG3(x,y,z,w)  if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>3) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINT(z); ETM_PRINTLN(w); }
#define ETM_LOGDEBUG5(x,y,z,w,xx,yy) if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>3) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT(y); ETM_PRINT(z); ETM_PRINT(w); ETM_PRINT(xx); ETM_PRINTLN(yy); }

////////////////////////////////////////////////////

#endif    //Ethernet_Manager_STM32_Debug
