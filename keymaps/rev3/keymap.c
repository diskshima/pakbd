#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_GRAVE,   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSLS, KC_DEL,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,             KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSPC,
    KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,             KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,             KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
             KC_LALT, KC_LCMD,    LOWER,                               KC_SPC,   RAISE  ,       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
      ),
  [_RAISE] = LAYOUT(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,   KC_F6  , KC_F7  , KC_F8  , KC_9   , KC_F10 , KC_F11  , KC_F12 , _______, _______,
    _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,            KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______, LCMD(KC_ENT),
    _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
             _______, _______,    _______,                             _______,   _______,      _______, _______, _______, _______
  ),
  [_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, LCTL(KC_MINS), _______,
    _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,            KC_F12 , _______, _______, _______, _______, _______, _______,
             _______, _______,    _______,                             _______,   _______,      _______, _______, _______, _______
  )
};

static bool raise_pressed = false;
static bool lower_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        layer_on(_RAISE);
      }
      else {
        layer_off(_RAISE);
        if (raise_pressed) {
          register_code(KC_RCMD);
          unregister_code(KC_RCMD);
        }
        raise_pressed = false;
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed= true;
        layer_on(_LOWER);
      }
      else {
        layer_off(_LOWER);
        if (lower_pressed) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
        lower_pressed = false;
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        raise_pressed = false;
        lower_pressed = false;
      }
      break;
  }
  return true;
}

