/*
Copyright 2021 flamwenco

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x7FF7
#define PRODUCT_ID   0xDEAD
#define MANUFACTURER flamwenco
#define PRODUCT      mori
#define DEVICE_VER 0x0001

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 13

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define MATRIX_ROW_PINS { B5, B2, C6, C7 }
#define MATRIX_COL_PINS { F4, F5, F6, F1, F7, F0, E6, D3, D0, D1, D2, D4, D6 }

#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { D7 }
#define ENCODER_RESOLUTION 4

/*enable midi slider*/
#define POT_ENABLE
#define MIDI_BASIC

#define COMBO_COUNT 11