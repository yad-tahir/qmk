# Copyright (C) 2019

# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
# 02110-1301, USA.

# Evil's HHKB firmware

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#

BOOTMAGIC_ENABLE = no		# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  = yes		# Mouse keys(+4700)
EXTRAKEY_ENABLE  = yes		# Audio control and System control(+450)
CONSOLE_ENABLE   = no		# Console for debug(+400)
COMMAND_ENABLE   = no		# Commands for debug and configuration
NKRO_ENABLE      = yes		# Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no		# Enable keyboard backlight functionality
MIDI_ENABLE      = no		# MIDI controls
AUDIO_ENABLE     = no		# Audio output on port C6
UNICODE_ENABLE   = no		# Unicode
RGBLIGHT_ENABLE  = no		# Enable WS2812 RGB underlight.
SLEEP_LED_ENABLE = no		# Breathing sleep LED during USB suspend
HHKB_RN42_ENABLE = yes		# Enable support for hasu's BT alt controller

# Remove warring errors when HHKB BT is enabled
ifeq ($(strip $(HHKB_RN42_ENABLE)), yes)

OPT_DEFS += -Wno-unused-variable \
			-Wno-unused-but-set-variable \
			-Wno-unused-function
endif
