#include QMK_KEYBOARD_H
#include "rbernau.h"

#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define LAYOUT_5x7_wrapper(...) LAYOUT_5x7(__VA_ARGS__)

// Layer Declarations
enum layer_number {
  _QWERTY,
  _DVORAK,
  _COLEMAK,
  _BASIC,
  _FUNCTION,
  _LAYER,
};

//Tap Dance Declarations
enum {
  TDD_LSFT,
  TDD_RSFT,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Shift, twice for Caps Lock
  [TDD_LSFT]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TDD_RSFT]  = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
};

// Custom Keycodes
enum custom_keycodes {
  PL_QWRT = SAFE_RANGE,
  PL_DVRK,
  PL_CLMK,
  PL_BASC,
};

#define MO_FUNC MO(_FUNCTION)
#define MO_LAYR MO(_LAYER)
#define TD_LSFT TD(TDD_LSFT)
#define TD_RSFT TD(TDD_RSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_5x7_wrapper(
    // left hand
    KC_GESC, ________________NUMBERS_L___________________________,
    KC_TAB , ________________QWERTY_L1__________________, KC_MINS,
    KC_A   , ________________QWERTY_L2__________________, KC_A   ,
    KC_A   , ________________QWERTY_L3__________________,
    KC_A   , KC_A   , KC_A   , KC_A   ,
                               KC_BSPC, KC_SPC ,
                                        MO_FUNC, KC_A   ,
                                        KC_A   , MO_LAYR,
    // right hand
    ________________NUMBERS_R___________________________, _______,
    KC_EQL , ________________QWERTY_R1__________________, KC_BSLS,
    _______, ________________QWERTY_R2__________________, _______,
             ________________QWERTY_R3__________________, _______,
                               _______, _______, _______, _______,
                      _______, _______,
             _______, _______,
             _______, _______),

  [_DVORAK] = LAYOUT_5x7_wrapper(
    // left hand
    _______, ________________NUMBERS_L___________________________,
    _______, ________________DVORAK_L1__________________, _______,
    _______, ________________DVORAK_L2__________________, _______,
    _______, ________________DVORAK_L3__________________,
    _______, _______, _______, _______,
                               _______, _______,
                                        _______, _______,
                                        _______, _______,
    // right hand
    ________________NUMBERS_R_DVORAK____________________, _______,
    _______, ________________DVORAK_R1__________________, _______,
    _______, ________________DVORAK_R2__________________, _______,
             ________________DVORAK_R3__________________, _______,
                               _______, _______, _______, _______,
                      _______, _______,
             _______, _______,
             _______, _______),

  [_COLEMAK] = LAYOUT_5x7_wrapper(
    // left hand
    _______, ________________NUMBERS_L___________________________,
    _______, ________________COLEMAK_L1_________________, _______,
    _______, ________________COLEMAK_L2_________________, _______,
    _______, ________________COLEMAK_L3_________________,
    _______, _______, _______, _______,
                               _______, _______,
                                        _______, _______,
                                        _______, _______,
    // right hand
    ________________NUMBERS_R___________________________, _______,
    _______, ________________COLEMAK_R1_________________, _______,
    _______, ________________COLEMAK_R2_________________, _______,
             ________________COLEMAK_R3_________________, _______,
                               _______, _______, _______, _______,
                      _______, _______,
             _______, _______,
             _______, _______),

  [_FUNCTION] = LAYOUT_5x7_wrapper(
    // left hand
    KC_GRV , ________________FUNCTION_L__________________________,
    _______, _______, KC_UP  , _______, _______, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,
                               _______, _______,
                                        _______, _______,
                                        _______, _______,
    // right hand
    ________________FUNCTION_R__________________________, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______,
                      _______, _______,
             _______, _______,
             _______, _______),

  [_LAYER] = LAYOUT_5x7_wrapper(
    // left hand
    RESET  , PL_QWRT, PL_DVRK, PL_CLMK, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,
                               _______, _______,
                                        _______, _______,
                                        _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, RESET  ,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______,
                      _______, _______,
             _______, _______,
             _______, _______),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PL_QWRT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    case PL_DVRK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      break;
    case PL_CLMK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      break;
    case PL_BASC:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASIC);
      }
      break;
  }
  return true;
}
