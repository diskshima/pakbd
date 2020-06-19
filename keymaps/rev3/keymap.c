#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _RAISE 1

#define MS_UP KC_MS_UP
#define MS_DOWN KC_MS_DOWN
#define MS_LEFT KC_MS_LEFT
#define MS_RIGHT KC_MS_RIGHT
#define WH_UP KC_MS_WH_UP
#define WH_DOWN KC_MS_WH_DOWN
#define WH_LEFT KC_MS_WH_LEFT
#define WH_RIGHT KC_MS_WH_RIGHT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_GRAVE,   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_DEL , KC_BSPC,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,             KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
    KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,             KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,             KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
             KC_LALT, KC_LCMD,    KC_SPC,                               KC_SPC,   TG(_RAISE),       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  ),
  [_RAISE] = LAYOUT(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5   , _______,   KC_F6  , KC_F7  , KC_F8  , KC_9    , KC_F10 , KC_F11 , KC_F12 , _______, _______,
    _______, _______, _______, _______, _______, _______ ,            WH_LEFT, WH_DOWN, WH_UP  , WH_RIGHT, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______ ,            MS_LEFT, MS_DOWN, MS_UP  , MS_RIGHT, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______ , _______, _______, _______,
             _______, _______,    KC_MS_BTN1,                           KC_MS_BTN2, _______,      _______, _______, _______, _______
  )
};
