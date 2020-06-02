/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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


// #define USE_SERIAL
#define USE_I2C
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS
// Rows are doubled-up
// #define DEBOUNCE 5
#define TAPPING_TOGGLE 3
#define ONESHOT_TAP_TOGGLE 3
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 300
// #ifdef RGBLED_NUM
// #  undef RGBLED_NUM
// #endif
// #define RGBLED_NUM 54
// #define RGBLIGHT_LIMIT_VAL 200
// #define RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_LED_MAP { 11,10,9,8,7,6,5,4,3,2,1,0,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 }
// #define RGBLIGHT_SPLIT 27

#define RGB_WHITE 0xFF, 0xFF, 0xFF
#define RGB_RED 0xFF, 0x00, 0x00
#define RGB_CORAL 0xFF, 0x7C, 0x4D
#define RGB_ORANGE 0xFF, 0x80, 0x00
#define RGB_GOLDENROD 0xD9, 0xA5, 0x21
#define RGB_GOLD 0xFF, 0xD9, 0x00
#define RGB_YELLOW 0xFF, 0xFF, 0x00
#define RGB_CHARTREUSE 0x80, 0xFF, 0x00
#define RGB_GREEN 0x00, 0xFF, 0x00
#define RGB_SPRINGGREEN 0x00, 0xFF, 0x80
#define RGB_TURQUOISE 0x47, 0x6E, 0x6A
#define RGB_TEAL 0x00, 0x80, 0x80
#define RGB_CYAN 0x00, 0xFF, 0xFF
#define RGB_AZURE 0x99, 0xf5, 0xFF
#define RGB_BLUE 0x00, 0x00, 0xFF
#define RGB_PURPLE 0x7A, 0x00, 0xFF
#define RGB_MAGENTA 0xFF, 0x00, 0xFF
#define RGB_PINK 0xFF, 0x80, 0xBF
