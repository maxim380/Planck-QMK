#include QMK_KEYBOARD_H
#include "quantum.h"
#include "timer.h"

#define CONTROL_MACRO_TIMER 350

static uint16_t key_timer;

bool process_control_macro(uint16_t keycode, bool keyHeld);

enum planck_layers {
    _QWERTY,
    _NUMPAD,
    _PROGRAMMING,
    _FUNCTIONS,
    _PC_CONTROL,
    _NAVIGATION
};

enum tapdance {
    TD_ESC_CAPS,
    TD_CURLY_BRACKETS,
    TD_ROUND_BRACKETS,
    TD_BOX_BRACKETS,
    TD_ANGLE_BRACKETS
};

enum macros {
    CONTROL_C_MACRO = SAFE_RANGE,
    CONTROL_V_MACRO,
    CONTROL_X_MACRO,
    CONTROL_Z_MACRO,
    CONTROL_Y_MACRO,
    CONTROL_A_MACRO,
    CONTROL_N_MACRO,
    CONTROL_O_MACRO,
    CONTROL_F_MACRO,
    CONTROL_S_MACRO,
    CONTROL_Q_MACRO,
    CONTROL_T_MACRO,
    CONTROL_W_MACRO,
    CONTROL_P_MACRO
};

qk_tap_dance_action_t tap_dance_actions[] = {
        // Tap once for Control, twice for Caps Lock
        [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
        [TD_ANGLE_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(S(KC_COMMA), S(KC_DOT)),
        [TD_BOX_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
        [TD_CURLY_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(S(KC_LBRC), S(KC_RBRC)),
        [TD_ROUND_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(S(KC_9), S(KC_0))
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        key_timer = timer_read();
    } else {
        if (timer_elapsed(key_timer) > CONTROL_MACRO_TIMER) { // held down
            key_timer = 0;
            process_control_macro(keycode, true);
        } else { // less than 150ms count as a tap and we just send the regular key
            key_timer = 0;
            process_control_macro(keycode, false);
        }
    }
    return true;
};

bool process_control_macro(uint16_t keycode, bool keyHeld) {
    uint16_t pressed_key;
    switch (keycode) {
        case CONTROL_C_MACRO:
            pressed_key = KC_C;
            break;
        case CONTROL_V_MACRO:
            pressed_key = KC_V;
            break;
        case CONTROL_X_MACRO:
            pressed_key = KC_X;
            break;
        case CONTROL_Z_MACRO:
            pressed_key = KC_Z;
            break;
        case CONTROL_Y_MACRO:
            pressed_key = KC_Y;
            break;
        case CONTROL_A_MACRO:
            pressed_key = KC_A;
            break;
        case CONTROL_N_MACRO:
            pressed_key = KC_N;
            break;
        case CONTROL_O_MACRO:
            pressed_key = KC_O;
            break;
        case CONTROL_F_MACRO:
            pressed_key = KC_F;
            break;
        case CONTROL_S_MACRO:
            pressed_key = KC_S;
            break;
        case CONTROL_Q_MACRO:
            pressed_key = KC_Q;
            break;
        case CONTROL_T_MACRO:
            pressed_key = KC_T;
            break;
        case CONTROL_W_MACRO:
            pressed_key = KC_W;
            break;
        case CONTROL_P_MACRO:
            pressed_key = KC_P;
            break;
        default:
            return false;
    }
    if (keyHeld == true) {
        register_code(KC_LCTL);
        register_code(pressed_key);
        unregister_code(pressed_key);
        unregister_code(KC_LCTL);
        return true;
    } else {
        register_code(pressed_key);
        unregister_code(pressed_key);
        return true;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] =
LAYOUT_ortho_4x12(
        KC_Q, KC_W, KC_E, KC_R, KC_T, TD(TD_ESC_CAPS), KC_DEL, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_TAB, KC_ENT, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LSFT, KC_LCTL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        MO(1),  KC_LGUI,  KC_LALT, MO(3), KC_BSPC, MO(4), MO(2), KC_SPC, KC_LEFT,  KC_UP, KC_DOWN,  KC_RGHT),

[_NUMPAD] =
LAYOUT_ortho_4x12(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_DEL, KC_7, KC_8, KC_9, KC_KP_SLASH, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_BSPC, KC_4, KC_5, KC_6, KC_KP_ASTERISK, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_LCTL, KC_1, KC_2, KC_3, KC_MINS, KC_NO,
        KC_TRNS, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_ENT, KC_SPC, KC_PPLS, KC_0, KC_PDOT, KC_KP_PLUS, KC_PENT
),

[_PROGRAMMING] =
LAYOUT_ortho_4x12(
        KC_NO, KC_NO, KC_NO, C(A(KC_L)), KC_EQUAL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        TD(TD_ANGLE_BRACKETS), TD(TD_BOX_BRACKETS), TD(TD_ROUND_BRACKETS), TD(TD_CURLY_BRACKETS), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_BSPC, MO(5), KC_ENT, KC_SPC, KC_TRNS, KC_NO, KC_NO, KC_NO
),

[_FUNCTIONS] =
LAYOUT_ortho_4x12(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),

[_PC_CONTROL] =
LAYOUT_ortho_4x12(
        RESET, DYN_REC_STOP, DYN_REC_START1, DYN_MACRO_PLAY1, KC_NO, KC_NO, KC_NO, LWIN(KC_L), LWIN(KC_K), LWIN(KC_R), KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LWIN(S(KC_S)), KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LWIN(S(KC_C)), KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, MO(5), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),
[_NAVIGATION] =
LAYOUT_ortho_4x12(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO 
)
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_GREEN);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif

void matrix_init_user(void) {
    rgblight_enable();
}

void matrix_scan_user(void) {
#ifdef RGBLIGHT_ENABLE

    static uint8_t old_layer = 255;
    uint8_t new_layer = biton32(layer_state);

    if (old_layer != new_layer) {
      switch (new_layer) {
        case _QWERTY:
          rgblight_setrgb(RGB_GREEN);
          break;
        case _NUMPAD:
          rgblight_setrgb(RGB_TEAL);
          break;
        case _PROGRAMMING:
          rgblight_setrgb(RGB_RED);
          break;
        case _FUNCTIONS:
          rgblight_setrgb(RGB_PURPLE);
          break;
        case _PC_CONTROL:
          rgblight_setrgb(RGB_YELLOW);
          break;
        case _NAVIGATION:
          rgblight_setrgb(RGB_MAGENTA);
          break;
      }

      old_layer = new_layer;
    }

#endif //RGBLIGHT_ENABLE
}
