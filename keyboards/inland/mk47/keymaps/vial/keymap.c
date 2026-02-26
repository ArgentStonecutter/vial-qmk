/* Copyright (C) 2023 jonylee@hfd
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

// Comment KEYMAP_DEFAULT out to get a keymap that makes more sense in terms of the actual keys:

// Bottom row: CTRL, CODE, ALT, HYPER(L5), LOWER(FN1/3), SPACE, RAISE(FN2/3), FN(L4), LEFT, DOWN, RIGHT
// L1 L2 and L3 are blank for user hacking with the raise/lower keys
// L4 is the function layer and completes all the standard keys:
//     ZXCV -> -='` and ,./ -> []\ and the arrow keys map to PgUp, PgDn, Home, End
// L5 is the media/backlight layer and matches the media keys on the keycaps
//     ZXCV -> SAT-+ and HUE-+ and Enter -> RGB TOG and HYPER-SPACE is CF_TOGGLE

#define KEYMAP_DEFAULT
// Fn-space is CF_TOGGLE

enum cf_keycode {
    CF_TOGGLE = QK_KB_0,
};

// clang-format off
#ifdef KEYMAP_DEFAULT
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_SLSH,
        KC_LCTL, TL_UPPR, KC_LALT, KC_DEL, KC_PGDN, KC_SPC, KC_PGUP, TL_LOWR, KC_LEFT, KC_DOWN, KC_RGHT),

    [1] = LAYOUT(
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, RGB_MOD,
        RGB_HUI, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MSEL, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, RGB_VAI, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CF_TOGGLE, KC_TRNS, KC_TRNS, RGB_SPD, RGB_VAD, RGB_SPI),

    [2] = LAYOUT(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_CAPS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_SLSH,
        KC_LCTL, KC_NO, KC_LALT, KC_DEL, KC_PGDN, KC_SPC, KC_PGUP, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CF_TOGGLE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [4] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [5] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};
#else
// This keymap actually matches the bottom row in the default keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,  KC_R,    KC_T,   KC_Y, KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,  KC_F,    KC_G,   KC_H, KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,   KC_N, KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT, MO(5), TL_LOWR, KC_SPC,       TL_UPPR, MO(4),   KC_LEFT, KC_DOWN, KC_RGHT),

    // TL_LOWR/MO13, available
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______),

    // TL_UPPR/MO23, available
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______),

    // UPPR + LOWR, available
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______),

    // layer 4 is the Fn layer
    [4] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
        KC_TRNS, KC_MINS, KC_EQL,  KC_QUOT, KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_PGUP, KC_BSLS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END),

    // Hyper: media and backlight
    [5] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG,
        _______, RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, KC_MSEL, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, RGB_VAI, _______,
        _______, _______, _______, _______, KC_VOLD, CF_TOGGLE,        KC_VOLU, _______, RGB_SPD, RGB_VAD, RGB_SPI)

};
#endif
// clang-format on

#ifdef RGB_MATRIX_ENABLE

static uint8_t cf_magic = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CF_TOGGLE:
            if (record->event.pressed)
                cf_magic = !cf_magic;
            return false;
    }

    return true;
}

static int colors[][3] = {
    {-1, -1, -1},
    {RGB_BLUE},
    {RGB_GREEN},
    {RGB_RED},
    {RGB_CYAN},
    {RGB_YELLOW},
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!cf_magic)
        return true;

    int act = get_highest_layer(layer_state);
    int def = get_highest_layer(default_layer_state);

    // Ignore default layers
    if(act == def)
        return true;

    int *color_p = colors[act];

    // Ignore the special color -1, -1, -1
    if(color_p[0] == -1)
        return true;

    // Scale color to brightness level;
    int color[3];
    uint8_t rgb_val = rgblight_get_val();
    for (int i = 0; i < 3; i++) {
        int level = color_p[i];
        level *= rgb_val;
        level >>= 8;

        color[i] = level;
    }

    // Walk the matrix
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            // Ignore special keys (KC_NO, KC_TRNS, etc)
            uint16_t code = keymap_key_to_keycode(act, (keypos_t){col,row});
            if (IS_INTERNAL_KEYCODE(code))
                continue;

            // Look up the LED
            uint8_t index = g_led_config.matrix_co[row][col];

            // Ignore LEDs that aren't actually LEDs
            if (index < led_min || index >= led_max || index == NO_LED)
                continue;

            // Set the color
            rgb_matrix_set_color(index, color[0], color[1], color[2]);
        }
    }

    return false;
}

#endif
