#pragma once

#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define LAYOUT_65_wrapper(...)                 LAYOUT_65_ansi(__VA_ARGS__)

// Mouse speed setting constant
#undef MK_MOMENTARY_ACCEL
#define MK_3_SPEED 1


// layout parts for easy reuse between keyboard keymaps
// ,-----+-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----+-----+
// |  1  |  2  |  3  |  4  |  5  |  6  |   |  7  |  8  |  9  |  0  |  -  |  =  |
// ,-----+-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----+-----+
#define ________________NUMBERS_L___________________________  KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6
#define ________________NUMBERS_R___________________________  KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL
#define ________________NUMBERS_R_DVORAK____________________  KC_7   , KC_8   , KC_9   , KC_0   , KC_LBRC, KC_RBRC

#define ________________NUMBERS___________________________________________________________________________________  ________________NUMBERS_L___________________________, ________________NUMBERS_R___________________________
#define ________________NUMBERS_DVORAK____________________________________________________________________________  ________________NUMBERS_L___________________________, ________________NUMBERS_R_DVORAK____________________

// ,-----+-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----+-----,
// | F1  | F2  | F3  | F4  | F5  | F6  |   | F7  | F8  | F9  | F10 | F11 | F12 |
// ,-----+-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----+-----,
#define ________________FUNCTION_L__________________________  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6
#define ________________FUNCTION_R__________________________  KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12
#define ________________FUNCTIONS_________________________________________________________________________________  ________________NUMBERS_L___________________________, ________________NUMBERS_R_DVORAK____________________

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  Q  |  W  |  F  |  P  |  G  |   |  J  |  L  |  U  |  Y  |  ;  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  A  |  R  |  S  |  T  |  D  |   |  H  |  N  |  E  |  I  |  O  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  Z  |  X  |  C  |  V  |  B  |   |  K  |  M  |  ,  |  .  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ________________COLEMAK_L1_________________  KC_Q   , KC_W   , KC_F   , KC_P   , KC_G
#define ________________COLEMAK_L2_________________  KC_A   , KC_R   , KC_S   , KC_T   , KC_D
#define ________________COLEMAK_L3_________________  KC_Z   , KC_X   , KC_C   , KC_V   , KC_B

#define ________________COLEMAK_R1_________________  KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN
#define ________________COLEMAK_R2_________________  KC_H   , KC_N   , KC_E   , KC_I   , KC_O
#define ________________COLEMAK_R3_________________  KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

#define ________________COLEMAK_1_________________________________________________________________________________  ________________COLEMAK_L1_________________, ________________COLEMAK_R1_________________, KC_LBRC, KC_RBRC
#define ________________COLEMAK_2________________________________________________________________________  ________________COLEMAK_L2_________________, ________________COLEMAK_R2_________________, KC_QUOT
#define ________________COLEMAK_3_______________________________________________________________  ________________COLEMAK_L3_________________, ________________COLEMAK_R3_________________

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  '  |  ,  |  .  |  P  |  Y  |   |  F  |  G  |  C  |  R  |  L  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  A  |  O  |  E  |  U  |  I  |   |  D  |  H  |  T  |  N  |  S  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  ;  |  Q  |  J  |  K  |  X  |   |  B  |  M  |  W  |  V  |  Z  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ________________DVORAK_L1__________________  KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y
#define ________________DVORAK_L2__________________  KC_A   , KC_O   , KC_E   , KC_U   , KC_I
#define ________________DVORAK_L3__________________  KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X

#define ________________DVORAK_R1__________________  KC_F   , KC_G   , KC_C   , KC_R   , KC_L
#define ________________DVORAK_R2__________________  KC_D   , KC_H   , KC_T   , KC_N   , KC_S
#define ________________DVORAK_R3__________________  KC_B   , KC_M   , KC_W   , KC_V   , KC_Z

#define ________________DVORAK_1__________________________________________________________________________________  ________________DVORAK_L1__________________, ________________DVORAK_R1__________________, KC_SLSH, KC_EQL
#define ________________DVORAK_2_________________________________________________________________________  ________________DVORAK_L2__________________, ________________DVORAK_R2__________________, KC_MINS
#define ________________DVORAK_3________________________________________________________________  ________________DVORAK_L3__________________, ________________DVORAK_R3__________________

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  Q  |  W  |  E  |  R  |  T  |   |  Y  |  U  |  I  |  O  |  P  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  A  |  S  |  D  |  F  |  G  |   |  H  |  J  |  K  |  L  |  ;  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  Z  |  X  |  C  |  V  |  B  |   |  N  |  M  |  ,  |  .  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ________________QWERTY_L1__________________  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define ________________QWERTY_L2__________________  KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define ________________QWERTY_L3__________________  KC_Z   , KC_X   , KC_C   , KC_V   , KC_B

#define ________________QWERTY_R1__________________  KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define ________________QWERTY_R2__________________  KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN
#define ________________QWERTY_R3__________________  KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

#define ________________QWERTY_1__________________________________________________________________________________  ________________QWERTY_L1__________________, ________________QWERTY_R1__________________, KC_LBRC, KC_RBRC
#define ________________QWERTY_2_________________________________________________________________________  ________________QWERTY_L2__________________, ________________QWERTY_R2__________________, KC_QUOT
#define ________________QWERTY_3________________________________________________________________  ________________QWERTY_L3__________________, ________________QWERTY_R3__________________


// Miscellaneous bits

#if defined(PIMORONI_TRACKBALL_ENABLE)
#    include "pimoroni_trackball.h"
#endif
