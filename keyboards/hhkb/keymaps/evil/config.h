/*
 * Copyright (C) 2019
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef CONFIG_EVIL_H
#define CONFIG_EVIL_H

#include "../../config.h"

// Device ID
#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION

#define MANUFACTURER QMK
#define PRODUCT HHKB Evil
#define DESCRIPTION HHKB on QMK Firmware with Evil keymap

// Allocate memory for dynamic macros as much as possible
#define DYNAMIC_MACRO_SIZE 300

// Mouse config
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 15
#define MOUSEKEY_MAX_SPEED 2
#define MOUSEKEY_TIME_TO_MAX 8
#define MOUSEKEY_WHEEL_DELAY 0

// Waiting time for a tap to become a hold
#undef TAPPING_TERM
#define TAPPING_TERM 250

// Avoid injecting MOD keys during TAPPING_TERM
#undef PERMISSIVE_HOLD

// One shot keys
#define ONESHOT_TAP_TOGGLE 20  // Avoid auto-holding one shot keys
#define ONESHOT_TIMEOUT 1000  // Time before the one shot key is released

#endif
