#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

enum unicode_name {
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [SNEK] = 0x1F363
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             X(SNEK), KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤────────┐
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_GRAVE,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ESC,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,       KC_ENT,     KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐
                       KC_LALT, KC_LCMD,          LOWER,   KC_SPC,           KC_SPC,           KC_RCMD,          KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT
  //└────────┴────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤────────┐
     _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            _______, KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,      _______,     _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐
                       _______, _______,          _______, _______,          _______,          _______,          _______,          _______, _______, _______
  //└────────┴────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤────────┐
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,      _______,     _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐
                       _______, _______,          _______, _______,          _______,          _______,          _______,          _______, _______, _______
  //└────────┴────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤────────┐
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,      _______,     _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐
                       _______, _______,          _______, _______,          _______,          _______,          _______,          _______, _______, _______
  //└────────┴────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
            if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

