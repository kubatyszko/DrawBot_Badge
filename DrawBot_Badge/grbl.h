/*
  grbl.h - Header for system level commands and real-time processes
  Part of Grbl
  Copyright (c) 2014-2016 Sungeun K. Jeon for Gnea Research LLC
	
	2018 -	Bart Dring This file was modifed for use on the ESP32
					CPU. Do not use this with Grbl for atMega328P
	
  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

// Grbl versioning system
#define GRBL_VERSION "1.1f"
#define GRBL_VERSION_BUILD "20180917"

//#include <sdkconfig.h>
#include <Arduino.h>
#include <EEPROM.h>
#include <driver/rmt.h>
#include <esp_task_wdt.h>
#include <freertos/task.h>

#include "driver/timer.h"

// Define the Grbl system include files. NOTE: Do not alter organization.
#include "config.h"
#include "cpu_map.h"
#include "tdef.h"
#include "nuts_bolts.h"
#include "defaults.h"
#include "settings.h"
#include "system.h"

#include "planner.h"
#include "coolant_control.h"
#include "eeprom.h"
#include "gcode.h"
#include "limits.h"
#include "motion_control.h"
#include "print.h"
#include "probe.h"
#include "protocol.h"
#include "report.h"
#include "serial.h"
#include "spindle_control.h"
#include "stepper.h"
#include "jog.h"
#include "servo.h" // for badge

#ifdef ENABLE_BLUETOOTH
	#include "grbl_bluetooth.h"
#endif

#ifdef ENABLE_SD_CARD	
	#include "grbl_sd.h"
#endif

#ifdef ENABLE_WIFI	
    #include "wificonfig.h"
    #ifdef ENABLE_HTTP
    #include "serial2socket.h"
    #endif
#endif
