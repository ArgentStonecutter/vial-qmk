/* Copyright 2025 GSKY <gskyGit@gsky.com.tw>
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.

enum layers {
    _Win,
    _Mac,
    _Winfn,
    _Macfn,
};

enum cf_keycode {
    CF_TOGGLE = QK_KB_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_Win] = LAYOUT_75_ansi(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,      KC_F4,        KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,      KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_PAUS, KC_DEL,
  KC_GRV,  KC_1,    KC_2,    KC_3,       KC_4,         KC_5,    KC_6,    KC_7,    KC_8,    KC_9,       KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
  KC_TAB,  KC_Q,    KC_W,    KC_E,       KC_R,         KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
  KC_CAPS, KC_A,    KC_S,    KC_D,       KC_F,         KC_G,    KC_H,    KC_J,    KC_K,    KC_L,       KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
  KC_LSFT, KC_Z,    KC_X,    KC_C,       KC_V,         KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
  KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                    KC_RALT, MO(_Winfn), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[_Winfn] = LAYOUT_75_ansi(
  KC_TRNS, KC_BRID, KC_BRIU, LGUI(KC_D), LGUI(KC_TAB), KC_MAIL, KC_CALC, KC_MPRV, KC_MPLY, KC_MNXT,    KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_INS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_NEXT,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_HUEU,
  KC_TRNS, TO(_Win),TO(_Mac),KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, RM_TOGG,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, RM_VALU, CF_TOGGLE,
  KC_TRNS, GU_TOGG, KC_TRNS,                           EE_CLR,                    MO(4),   KC_TRNS,    MO(5),   RM_SPDD, RM_VALD, RM_SPDU),

[_Mac] = LAYOUT_75_ansi(
  KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL,    KC_LPAD,      KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT,    KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR, KC_PAUS, KC_DEL,
  KC_GRV,  KC_1,    KC_2,    KC_3,       KC_4,         KC_5,    KC_6,    KC_7,    KC_8,    KC_9,       KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
  KC_TAB,  KC_Q,    KC_W,    KC_E,       KC_R,         KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
  KC_CAPS, KC_A,    KC_S,    KC_D,       KC_F,         KC_G,    KC_H,    KC_J,    KC_K,    KC_L,       KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
  KC_LSFT, KC_Z,    KC_X,    KC_C,       KC_V,         KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
  KC_LCTL, KC_LALT, KC_LGUI,                           KC_SPC,                    KC_RGUI, MO(_Macfn), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[_Macfn] = LAYOUT_75_ansi(
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,      KC_F4,        KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,      KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_INS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_NEXT,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_HUEU,
  KC_TRNS, TO(_Win),TO(_Mac),KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, RM_TOGG,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, RM_VALU, CF_TOGGLE,
  KC_TRNS, KC_TRNS, KC_TRNS,                           EE_CLR,                    MO(5),   KC_TRNS,    MO(5),   RM_SPDD, RM_VALD, RM_SPDU),

[4] = LAYOUT_75_ansi(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_TOGG,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_NEXT,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_HUEU,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_SATD,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_VALU, RM_SATU,
  KC_TRNS, KC_TRNS, KC_TRNS,                   EE_CLR,                    KC_TRNS, KC_TRNS, KC_TRNS, RM_SPDD, RM_VALD, RM_SPDU),

[5] = LAYOUT_75_ansi(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,                   EE_CLR,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT)
};
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
    {-1, -1, -1},
    {RGB_BLUE},
    {RGB_GREEN},
    {RGB_CYAN},
    {RGB_RED},
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
