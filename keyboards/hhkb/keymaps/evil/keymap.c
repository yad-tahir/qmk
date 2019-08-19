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

/*
 * Evil HHKB layout
 */
#include QMK_KEYBOARD_H

#define BASE 0 // Dvorak
#define QWERTY 1
#define WIN 2
#define LATEX 3
#define HHKB 4
#define LMACRO 5

#define ___ KC_TRNS

// Evil's custom Keycodes
enum hhkb_keycodes
  {
   M_NAME = SAFE_RANGE,
   M_EMAIL,
   M_PASS,
   M_LOGIN,
   M_SIGNATURE,
   DYNAMIC_MACRO_RANGE,
  };

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
  {
   // Dvorak
   [BASE] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_BSLS, KC_LBRC, KC_RBRC,
				   KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_EQL, KC_BSPC,
				   KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT,
				   KC_LSFT, KC_SCLN, LT(LMACRO,KC_Q), KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT, KC_F5,
				   KC_LALT, KC_LGUI, /*		*/ LT(HHKB,KC_SPC) /*		*/, KC_F2, KC_F3),

   // QWERTY
   [QWERTY] = LAYOUT(___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, KC_GRV, KC_MINS, KC_EQL, KC_BSLS,
					 ___, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, ___,
					 ___, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, ___,
					 ___, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, ___, ___,
					 ___, ___, /*		*/ ___ /*		*/, ___, ___),

   // Function Layer
   [HHKB] = LAYOUT(TO(BASE), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_F14,
				   KC_CAPS, KC_HOME, KC_PGUP, KC_WH_U, KC_NO, KC_NO, KC_NO, KC_HOME, KC_UP, KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_DEL,
				   ___, KC_VOLD, KC_MUTE, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, KC_MS_L, KC_MS_R, ___,
				   ___, KC_END, KC_PGDN, KC_WH_D, KC_NO, KC_NO, KC_NO, KC_END, KC_NO, KC_PGDN, KC_MS_D, ___, TG(QWERTY),
				   ___, ___, /*		*/ ___ /*		*/, TG(LATEX), TG(WIN)),

   // Swap CTRL and SUPER
   [WIN] = LAYOUT(___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
				  ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
				  KC_LGUI, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
				  ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
				  ___, KC_LCTL, /*		*/ ___ /*		*/, ___, ___),

   // Swap \ and /
   [LATEX] = LAYOUT(___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, KC_SLSH, ___, ___,
					___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, KC_BSLS, ___, ___,
					___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
					___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
					___, ___, /*		*/ ___ /*		*/, ___, ___),

   // Macros
   [LMACRO] = LAYOUT(DYN_REC_STOP, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
					 ___, DYN_REC_START1, DYN_REC_START2, ___, M_PASS, M_NAME, ___, ___, ___, ___, M_LOGIN, ___, ___, ___,
					 ___, ___, M_EMAIL, ___, ___, ___, ___, ___, ___, M_NAME, M_SIGNATURE, ___, ___,
					 ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
					 ___, ___, /*		*/ ___ /*		*/, ___, ___)
  };

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  return MACRO_NONE;
};

// Called every time a key is pressed
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  // Dynamic Macros
  if (!process_record_dynamic_macro(keycode, record)) {
	return false;
  }

  // Static Macros
  // on keydown
  if(keycode == M_EMAIL && record->event.pressed){
	clear_keyboard_but_mods();
	SEND_STRING("yad@ieee.org");
  }

  if(keycode == M_PASS && record->event.pressed){
	clear_keyboard_but_mods();
	SEND_STRING("*hidden*");
  }

  if(keycode == M_LOGIN && record->event.pressed){
	clear_keyboard_but_mods();
	SEND_STRING("*hidden*" SS_TAP(X_ENTER));
  }

  if(keycode == M_NAME && record->event.pressed){
	clear_keyboard_but_mods();
	SEND_STRING("Yad");
  }

  if(keycode == M_SIGNATURE && record->event.pressed){
	clear_keyboard_but_mods();
	SEND_STRING("​--------------------------" SS_TAP(X_ENTER)
				"​Yad Tahir, PhD" SS_TAP(X_ENTER)
				"Public Key: https://bit.ly/2JFTRHD" SS_TAP(X_ENTER)
				"Fingerprint: 39B3 A279 DAC6 7985 0722 3B74 E130 54FA 1432 F996" SS_TAP(X_ENTER));
  }

  // Continue process the key as usual. If this function returns false, QMK will
  // skip the normal key handling, and key up or down events need to be handled
  // manually. For more info, check https://docs.qmk.fm/#/custom_quantum_functions
  return true;
}
