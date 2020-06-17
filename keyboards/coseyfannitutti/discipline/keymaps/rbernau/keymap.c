/* Copyright 2019 COSEYFANNITUTTI
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "rbernau.h"

#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define LAYOUT_65_wrapper(...) LAYOUT_65_ansi(__VA_ARGS__)

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
  [_QWERTY] = LAYOUT_65_wrapper(
      KC_GESC, ________________NUMBERS___________________________________________________________________________________,    KC_BSPC   , KC_DEL ,
      KC_TAB   , ________________QWERTY_1__________________________________________________________________________________,   KC_BSLS  , KC_PGUP,
      KC_BSPC     , ________________QWERTY_2_________________________________________________________________________,       KC_ENT     , KC_PGDN,
      TD_LSFT         , ________________QWERTY_3________________________________________________________________,   TD_RSFT    , KC_UP  , MO_LAYR,
      KC_LCTL  , KC_LGUI  , KC_LALT  ,                        KC_SPC                       , KC_RALT, MO_FUNC, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

  [_DVORAK] = LAYOUT_65_wrapper(
      _______, ________________NUMBERS_DVORAK____________________________________________________________________________,    _______   , _______,
      _______   , ________________DVORAK_1__________________________________________________________________________________,  _______  , _______,
      _______     , ________________DVORAK_2_________________________________________________________________________,       _______    , _______,
      _______         , ________________DVORAK_3________________________________________________________________,   _______    , _______, _______,
      _______  , _______  , _______  ,                        _______                      , _______, _______, _______, _______, _______, _______),


  [_COLEMAK] = LAYOUT_65_wrapper(
      _______, ________________NUMBERS___________________________________________________________________________________,    _______   , _______,
      _______   , ________________COLEMAK_1_________________________________________________________________________________,  _______  , _______,
      _______     , ________________COLEMAK_2________________________________________________________________________,       _______    , _______,
      _______         , ________________COLEMAK_3_______________________________________________________________,   _______    , _______, _______,
      _______  , _______  , _______  ,                        _______                      , _______, _______, _______, _______, _______, _______),

  [_BASIC] = LAYOUT_65_wrapper(
      KC_GESC, ________________NUMBERS___________________________________________________________________________________,    KC_BSPC   , KC_DEL ,
      KC_TAB   , ________________QWERTY_1__________________________________________________________________________________,   KC_BSLS  , KC_PGUP,
      KC_CAPS     , ________________QWERTY_2_________________________________________________________________________,       KC_ENT     , KC_PGDN,
      KC_LSFT         , ________________QWERTY_3________________________________________________________________,   KC_RSFT    , KC_UP  , _______,
      KC_LCTL  , KC_LGUI  , KC_LALT  ,                        KC_SPC                       , KC_RALT, _______, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

  [_FUNCTION] = LAYOUT_65_wrapper(
      KC_GRV , ________________FUNCTIONS_________________________________________________________________________________,    KC_DEL    , KC_PSCR,
      _______   , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______  , KC_HOME,
      _______     , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______    , KC_END ,
      _______         , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______    , _______, _______,
      _______  , _______  , _______  ,                        _______                      , _______, _______, _______, _______, _______, _______),


  [_LAYER] = LAYOUT_65_wrapper(
      RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______   , _______,
      _______   , PL_QWRT, _______, _______, _______, _______, _______, _______, PL_CLMK, _______, _______, _______, _______,  _______  , _______,
      _______     , _______, _______, PL_DVRK, _______, PL_DVRK, PL_DVRK, _______, _______, _______, _______, _______,       _______    , _______,
      _______         , _______, PL_QWRT, PL_CLMK, _______, PL_BASC, PL_BASC, _______, _______, _______, _______,   _______    , _______, _______,
      _______  , _______  , _______  ,                        _______                      , _______, _______, _______, _______, _______, _______),
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
