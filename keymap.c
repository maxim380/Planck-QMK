#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _NUMPAD,
  _PROGRAMMING,
  _FUNCTIONS,
  _PC_CONTROL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_ortho_4x12(KC_Q,   KC_W,     KC_E,     KC_R,   KC_T,   KC_ESC,   KC_DEL,   KC_Y,   KC_U,     KC_I,     KC_O,     KC_P, 
                                KC_A,   KC_S,     KC_D,     KC_F,   KC_G,   KC_TAB,   KC_ENT,   KC_H,   KC_J,     KC_K,     KC_L,     KC_SCLN, 
                                KC_Z,   KC_X,     KC_C,     KC_V,   KC_B,   KC_LSFT,  KC_LCTL,  KC_N,   KC_M,     KC_COMM,  KC_DOT,   KC_SLSH, 
                                MO(1),  KC_LGUI,  KC_LALT,  MO(4),  MO(3),  KC_BSPC,  KC_SPC,   MO(2),  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RGHT),

	[_NUMPAD] = LAYOUT_ortho_4x12(KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO, KC_ESC,  KC_DEL,   KC_7,     KC_8,  KC_9,    KC_KP_SLASH,    KC_NO,
                                KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO, KC_TAB,  KC_BSPC,  KC_4,     KC_5,  KC_6,    KC_KP_ASTERISK, KC_NO, 
                                KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO, KC_LSFT, KC_LCTL,  KC_1,     KC_2,  KC_3,    KC_MINS,        KC_NO, 
                                KC_TRNS,  KC_LSFT,  KC_NO, KC_NO, KC_NO, KC_ENT,  KC_SPC,   KC_PPLS,  KC_0,  KC_PDOT, KC_KP_PLUS,     KC_PENT),

	[_PROGRAMMING] = LAYOUT_ortho_4x12( KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, 
                                      KC_NO, KC_LCBR,  KC_RCBR,  KC_LPRN,  KC_RPRN,  KC_NO,   KC_NO,  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, 
                                      KC_NO, KC_LBRC,  KC_RBRC,  KC_LT,    KC_GT,    KC_NO,   KC_NO,  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, 
                                      KC_NO, KC_LEFT,  KC_UP,    KC_DOWN,  KC_RGHT,  KC_NO, KC_ENT,  KC_SPC, KC_TRNS,  KC_NO, KC_NO, KC_NO, KC_NO),

	[_FUNCTIONS] = LAYOUT_ortho_4x12( KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_F1, KC_F2,   KC_F3,  KC_F4,  KC_NO, 
                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_F5, KC_F6,   KC_F7,  KC_F8,  KC_NO, 
                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_F9, KC_F10,  KC_F11, KC_F12, KC_NO, 
                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,  KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO),

	[_PC_CONTROL] = LAYOUT_ortho_4x12(KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,
                                    KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_NO, KC_NO,
                                    KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_NO, KC_NO,
                                    KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO)
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_GREEN);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif