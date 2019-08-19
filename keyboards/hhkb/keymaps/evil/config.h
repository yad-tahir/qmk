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

#endif
