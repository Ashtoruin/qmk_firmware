#include QMK_KEYBOARD_H
#include "rbernau.h"

#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define LAYOUT_dactodox_wrapper(...) LAYOUT_dactodox(__VA_ARGS__)

// Layer Declarations
enum layer_number {
  _QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_dactodox_wrapper(
    // left hand
    KC_GESC, ________________NUMBERS_L___________________________,
    KC_TAB , ________________QWERTY_L1__________________, KC_MINS,
    KC_LCTL, ________________QWERTY_L2__________________, _______,
    KC_LSFT, ________________QWERTY_L3__________________,
    KC_CAPS, KC_LGUI, KC_LALT, _______, _______,
                                                 KC_BSPC, KC_SPC ,
                                                          KC_END ,
                                        KC_PSCR, KC_INS , _______,
    // right hand
    ________________NUMBERS_R___________________________, _______,
    KC_EQL , KC_GESC, KC_GESC, KC_GESC, KC_GESC, KC_GESC, KC_BSLS,
    _______, KC_GESC, KC_GESC, KC_GESC, KC_GESC, KC_GESC, KC_RCTL,
             KC_GESC, KC_GESC, KC_GESC, KC_GESC, KC_GESC, KC_RSFT,
                      _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT,
    KC_BSPC, _______,
    KC_PGUP,
    _______, KC_PGDN, _______)
};
