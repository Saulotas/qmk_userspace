/**
 * Copyright 2024 George Avronidakis <saulot1982@gmail.com> (@Hakuho)
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

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_FUNCTION,
    LAYER_NAVIGATION,
    LAYER_POINTER,
    LAYER_NUMERAL,
    LAYER_SYMBOLS,
	LAYER_GAMES,
	LAYER_MEDIA,
};

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#define ESC_MED LT(LAYER_MEDIA, KC_ESC)
#define ESC_FUN LT(LAYER_FUNCTION, KC_ESC)
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
#define TAB_FUN LT(LAYER_FUNCTION, KC_TAB)
#define TAB_NUM LT(LAYER_NUMERAL, KC_TAB)
#define ENT_SYM LT(LAYER_SYMBOLS, KC_ENT)
#define BSP_NUM LT(LAYER_NUMERAL, KC_BSPC)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
/** \brief QWERTY layout (3 rows, 10 columns). */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x5_3(
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
       LSFT_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LGUI_T(KC_F), KC_G, KC_H, RGUI_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RSFT_T(KC_SCLN),
       PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, PT_SLSH,
                      ESC_FUN, SPC_NAV, KC_BSPC, ENT_SYM, TAB_NUM, KC_MUTE
  ),

/*
 * Layers used on this Dilemma.
 *
 * These layers started off heavily inspired by the Miryoku layout, but trimmed
 * down and tailored for a stock experience that is meant to be fundation for
 * further personalization.
 *
 * See https://github.com/manna-harbour/miryoku for the original layout.
 */

/**
 * \brief Function layer. 1
 *
 * Secondary right-hand layer has function keys mirroring the numerals on the
 * primary layer with extras on the pinkie column, plus system keys on the inner
 * column. App is on the tertiary thumb key and other thumb keys are duplicated
 * from the base layer to enable auto-repeat.
 */
  [LAYER_FUNCTION] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F12,
    KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, XXXXXXX, KC_SCRL,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUS,   KC_F1,   KC_F2,   KC_F3,  KC_F10,
                      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

/**
 * \brief Navigation layer. 2
 *
 * Primary right-hand layer (left home thumb) is navigation and editing. Cursor
 * keys are on the home position, line and page movement below, clipboard above,
 * caps lock and insert on the inner column. Thumb keys are duplicated from the
 * base layer to avoid having to layer change mid edit and to enable auto-repeat.
 */
  [LAYER_NAVIGATION] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, XXXXXXX, KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
                      XXXXXXX, _______, XXXXXXX,  KC_ENT, KC_BSPC, KC_DEL
  ),

/** \brief Mouse emulation and pointer functions.  3*/
  [LAYER_POINTER] = LAYOUT_split_3x5_3(
    XXXXXXX,  XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD, S_D_MOD, DPI_MOD, XXXXXXX,  XXXXXXX, TO(6),
    KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, XXXXXXX, XXXXXXX, KC_RGUI, KC_LCTL, KC_LALT, KC_RSFT,
    _______, DRGSCRL, SNIPING, KC_BTN3, XXXXXXX, XXXXXXX, KC_BTN3, SNIPING, DRGSCRL, _______,
                      KC_BTN3, KC_BTN2, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN3
  ),

/**
 * \brief Numeral layout. 4
 *
 * Primary left-hand layer (right home thumb) is numerals and symbols. Numerals
 * are in the standard numpad locations with symbols in the remaining positions.
 * `KC_DOT` is duplicated from the base layer.
 */
  [LAYER_NUMERAL] = LAYOUT_split_3x5_3(
    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_QUOT,    KC_4,    KC_5,    KC_6,  KC_EQL, XXXXXXX, KC_RGUI, KC_LCTL, KC_LALT, KC_RSFT,
     KC_DOT,    KC_1,    KC_2,    KC_3, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       KC_DOT, KC_MINS,    KC_0, XXXXXXX, _______, XXXXXXX
  ),

/**
 * \brief Symbols layer. 5
 *
 * Secondary left-hand layer has shifted symbols in the same locations to reduce
 * chording when using mods with shifted symbols. `KC_LPRN` is duplicated next to
 * `KC_RPRN`.
 */
  [LAYER_SYMBOLS] = LAYOUT_split_3x5_3(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR, QK_BOOT,
    KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX, KC_RGUI, KC_LCTL, KC_LALT, KC_RSFT,
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_LPRN,  KC_UNDS, KC_RPRN, _______, XXXXXXX, XXXXXXX
  ),
  
  /**
 * \brief gaming layer. 6
 *
 */
  [LAYER_GAMES] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0),
    XXXXXXX,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX,  KC_UP, XXXXXXX, KC_ENT, XXXXXXX, XXXXXXX
  ),
  
  /**
 * \brief Media layer. 7
 *
 * Tertiary left- and right-hand layer is media and RGB control.  This layer is
 * symmetrical to accomodate the left- and right-hand trackball.
 */
  [LAYER_MEDIA] = LAYOUT_split_3x5_3(
    XXXXXXX,RGB_RMOD, RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX,RGB_RMOD, RGB_TOG, RGB_MOD, XXXXXXX,
    KC_MPRV, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT, KC_MPRV, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, KC_MPLY, KC_MSTP, KC_MSTP, KC_MPLY, KC_MUTE
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(KC_WH_D, KC_WH_U),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_FUNCTION]   = {ENCODER_CCW_CW(KC_DOWN, KC_UP),    ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_NAVIGATION] = {ENCODER_CCW_CW(KC_PGDN, KC_PGUP),  ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT),  ENCODER_CCW_CW(KC_DOWN, KC_UP)},
    [LAYER_NUMERAL]    = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT),  ENCODER_CCW_CW(KC_DOWN, KC_UP)},
    [LAYER_SYMBOLS]    = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_GAMES]      = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_MEDIA]      = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case LAYER_BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case LAYER_FUNCTION:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case LAYER_NAVIGATION:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case LAYER_POINTER:
            oled_write_P(PSTR("Pointer\n"), false);
            break;
        case LAYER_NUMERAL:
            oled_write_P(PSTR("Numerals\n"), false);
            break;
        case LAYER_SYMBOLS:
            oled_write_P(PSTR("Sumbols\n"), false);
            break;
        case LAYER_GAMES:
            oled_write_P(PSTR("Games\n"), false);
            break;
        case LAYER_MEDIA:
            oled_write_P(PSTR("Media\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif


