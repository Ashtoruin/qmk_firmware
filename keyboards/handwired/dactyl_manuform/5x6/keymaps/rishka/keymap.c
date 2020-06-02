/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "rishka.h"
enum layers {
  BASE, // default layer
  WIN, // Switch keys that are needed in windows
  SYMB, // symbols
  MDIA // media keys
};

enum more_custom_keycodes {
    PM_SCROLL,
    PM_PRECISION,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_5x6_wrapper(
     KC_EQL , ________________NUMBERS_L__________________,                         ________________NUMBERS_R__________________, KC_MINS,
     KC_ESC , _________________QWERTY_L1_________________,                         _________________QWERTY_R1_________________, KC_BSLS,
     KC_F1  , _____________MOD_QWERTY_L2_________________,                         _____________MOD_QWERTY_R2_________________, KC_QUOT,
     OS_LSFT, _________________QWERTY_L3_________________,                         _________________QWERTY_R3_________________, OS_RSFT,
                      KC_LEFT,KC_RGHT,                                                       KC_UP, KC_DOWN,
                                     KC_BSPC, KC_SPC,                         KC_TAB, KC_ENT,
                                     KC_LGUI, MO(SYMB),                       MO(SYMB), TT(MDIA),
                                     KC_DEL, KC_GRV,                          TT(WIN), KC_LALT
  ),
  [WIN] = LAYOUT_5x6_wrapper(

     _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
     _______, _________________QWERTY_L2_________________,                        _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                                             _______, _______,            _______, _______,
                                             _______, _______,            _______, _______,
                                             KC_LCTL, _______,            _______, _______,
                                             _______, _______,            _______, _______
  ),

  [SYMB] = LAYOUT_5x6_wrapper(
       KC_F12 , ______________________F_L__________________,                      ______________________F_R__________________, KC_F11,
       _______, _________________SYMBOL_L1_________________,                      _________________SYMBOL_R1_________________, KC_NLCK,
       _______, PM_PRECISION, PM_SCROLL, KC_BTN1, KC_BTN2, KC_BTN3,                       _________________SYMBOL_R2_________________, _______,
       _______, _________________SYMBOL_L3_________________,                      _________________SYMBOL_R3_________________, _______,
                                               _______, _______,            KC_P0 , KC_PDOT,
                                               _______, _______,            _______, _______,
                                               RESET  , _______,            _______, _______,
                                               RGB_TOG, _______,            _______, _______
  ),
  [MDIA] = LAYOUT_5x6_wrapper(

     RGB_MOD, RGB_HUI, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
     	RGB_M_SN, RGB_HUD, _______, KC_MS_U, _______, KC_WH_U,                        _______, _______, KC_WH_U, _______, _______, _______,
     RGB_VAI, RGB_SAI, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                        _______, MOUSE_L, KC_WH_D, MOUSE_R, _______, _______,
     RGB_VAD, RGB_SAD, _______, _______, KC_MPLY, _______,                        _______, KC_MUTE, _______, _______, _______, _______,
                                             KC_MPRV, KC_MNXT,            KC_VOLU, KC_VOLD,
                                             KC_BTN1, KC_BTN2,            _______, _______,
                                             KC_BTN3, KC_BTN4,            _______, _______,
                                             KC_BTN5, _______,            _______, _______

   ),
};


#ifdef PIMORONI_TRACKBALL_ENABLE
void run_trackball_cleanup(void) {
    if (trackball_is_scrolling()) {
        trackball_set_rgbw(RGB_CYAN, 0x00);
    } else if (trackball_get_precision() != 1.0) {
        trackball_set_rgbw(RGB_GREEN, 0x00);
    } else {
        trackball_set_rgbw(RGB_MAGENTA, 0x00);
    }
}
void keyboard_post_init_kb(void) {
    // trackball_set_precision(1.5);
    trackball_set_rgbw(RGB_MAGENTA, 0x00);
}
void shutdown_keymap(void) {
    trackball_set_rgbw(RGB_RED, 0x00);
}
#endif

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef PIMORONI_TRACKBALL_ENABLE
        case PM_SCROLL:
            trackball_set_scrolling(record->event.pressed);
            run_trackball_cleanup();
            break;
        case PM_PRECISION:
            if (record->event.pressed) {
                trackball_set_precision(1.5);
            } else {
                trackball_set_precision(1);
            }
            run_trackball_cleanup();
            break;
#if     !defined(MOUSEKEY_ENABLE) && defined(POINTING_DEVICE_ENABLE)
        case KC_BTN1 ... KC_BTN3:
        {
            report_mouse_t currentReport = pointing_device_get_report();
            if (record->event.pressed) {
                currentReport.buttons |= (1 << (keycode - KC_BTN1));  // this is defined in report.h
            } else {
                currentReport.buttons &= ~(1 << (keycode - KC_BTN1));
            }
            pointing_device_set_report(currentReport);
            pointing_device_send();
            break;
        }
#    endif
#endif
    }
    return true;
}
