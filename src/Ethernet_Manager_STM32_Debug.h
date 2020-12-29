/****************************************************************************************************************************
  Ethernet_Manager_STM32_Debug.h
  For W5x00, ENC28J60 and built-in LAN8742A Ethernet shields.

  Ethernet_Manager is a library for STM32F/L/H/G/WB/MP1 with Ethernet W5x00, ENC28J60 or built-in LAN8742A shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_STM32
  Licensed under MIT license
  Version: 1.0.1

  Version  Modified By   Date      Comments
  -------  -----------  ---------- -----------
  1.0.0     K Hoang     16/12/2020 Initial coding.
  1.0.1     K Hoang     29/12/2020 Suppress all possible compiler warnings
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

#define ETM_LOGERROR(x)         if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>0) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.println(x); }
#define ETM_LOGERROR0(x)        if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>0) { ETM_DBG_PORT.print(x); }
#define ETM_LOGERROR1(x,y)      if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>0) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(y); }
#define ETM_LOGERROR2(x,y,z)    if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>0) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(y); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(z); }
#define ETM_LOGERROR3(x,y,z,w)  if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>0) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(y); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(z); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(w); }

#define ETM_LOGWARN(x)          if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>1) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.println(x); }
#define ETM_LOGWARN0(x)         if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>1) { ETM_DBG_PORT.print(x); }
#define ETM_LOGWARN1(x,y)       if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>1) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(y); }
#define ETM_LOGWARN2(x,y,z)     if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>1) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(y); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(z); }
#define ETM_LOGWARN3(x,y,z,w)   if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>1) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(y); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(z); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(w); }

#define ETM_LOGINFO(x)          if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>2) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.println(x); }
#define ETM_LOGINFO0(x)         if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>2) { ETM_DBG_PORT.print(x); }
#define ETM_LOGINFO1(x,y)       if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>2) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(y); }
#define ETM_LOGINFO2(x,y,z)     if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>2) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(y); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(z); }
#define ETM_LOGINFO3(x,y,z,w)   if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>2) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(y); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(z); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(w); }

#define ETM_LOGDEBUG(x)         if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>3) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.println(x); }
#define ETM_LOGDEBUG0(x)        if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>3) { ETM_DBG_PORT.print(x); }
#define ETM_LOGDEBUG1(x,y)      if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>3) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(y); }
#define ETM_LOGDEBUG2(x,y,z)    if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>3) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(y); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(z); }
#define ETM_LOGDEBUG3(x,y,z,w)  if(_ETHERNET_MANAGER_STM32_LOGLEVEL_>3) { ETM_DBG_PORT.print("[ETM] "); ETM_DBG_PORT.print(x); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(y); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.print(z); ETM_DBG_PORT.print(" "); ETM_DBG_PORT.println(w); }

#endif    //Ethernet_Manager_STM32_Debug
