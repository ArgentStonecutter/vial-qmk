// Copyright 2025 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    WIN_BASE,
    WIN_T,
    WIN_ALT,
    ARROW_FN,
    LWIN_DIS,
    WIN_FN,
    WIN_T_FN,
    WIN_ALT_FN,
    MAC_BASE,
    MAC_FN,
};

enum cf_keycode {
    CF_TOGGLE = QK_KB_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_UP,                      KC_RSFT,
        KC_LCTL, KC_LWIN, KC_LALT,                KC_SPC,                 KC_LEFT, KC_DOWN, KC_RIGHT,          MO(WIN_FN)
    ),
    [WIN_FN]   = LAYOUT_60_ansi(
        KC_GRV,      KC_F1,        KC_F2,        KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______,     _______,      _______,      _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, RM_VALD, RM_VALU, RM_NEXT,
        _______,     _______,      DF(MAC_BASE), _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______, RM_SPDD, RM_SPDU,          TG(ARROW_FN),
        _______,     _______,      _______,      _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN, RM_HUEU, _______,                   _______,
        DF(WIN_ALT), TG(LWIN_DIS), _______,                          _______,                          _______, _______, _______,          _______
    ),
    [WIN_T]    = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______,                       _______,                        _______, _______, _______,          MO(WIN_T_FN)
    ),
    [WIN_T_FN]   = LAYOUT_60_ansi(
        KC_ESC,	      KC_MYCM,      KC_WHOM,      KC_MAIL, KC_CALC, KC_MSEL, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSPC,
        _______,      _______,      _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,      DF(MAC_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,      _______,      _______,      _______, _______, _______, _______, _______, _______, _______, _______,                   TG(ARROW_FN),
        DF(WIN_BASE), TG(LWIN_DIS), _______,                          _______,                          _______, _______, _______,          _______
    ),
    [WIN_ALT]   = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______,                   _______,
        _______, _______, _______,                       _______,                        _______, _______, _______,          MO(WIN_ALT_FN)
    ),
    [WIN_ALT_FN]   = LAYOUT_60_ansi(
        KC_ESC,	   KC_MYCM,      KC_WHOM, KC_MAIL, KC_CALC, KC_MSEL, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSPC,
        _______,   _______,      _______, _______, _______, _______, KC_Y,    KC_U,    KC_I,    _______, _______, _______, _______, _______,
        _______,   _______,      _______, _______, _______, _______, KC_H,    KC_J,    KC_K,    _______, _______, _______,          TG(ARROW_FN),
        _______,   _______,      _______, _______, _______, _______, KC_N,    KC_M,    KC_COMM, _______, _______,                   _______,
        DF(WIN_T), TG(LWIN_DIS), _______,                       _______,                        _______, _______, _______,          _______
    ),
    [MAC_BASE] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH,                    KC_RSFT,
        KC_LCTL, KC_LOPT, KC_LCMD,                 KC_SPC,                KC_RCMD, KC_APP, KC_RCTL,            MO(MAC_FN)
    ),
    [MAC_FN]   = LAYOUT_60_ansi(
        _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
        _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
        _______, DF(WIN_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,          _______,
        _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______,  KC_SLSH,                   _______,
        _______, _______,      _______,                       _______,                        _______,  KC_F1,   KC_RCTL,          KC_F2
    ),
    [ARROW_FN]   = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH,                   _______,
        _______, _______, _______,                       _______,                        KC_RALT, KC_APP,  KC_RCTL,          _______
    ),
    [LWIN_DIS]   = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, KC_NO,   _______,                       _______,                        _______, _______, _______,          _______
    ),
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
    {RGB_BLUE},
    {RGB_GREEN},
    {RGB_RED},
    {RGB_CYAN},
    {RGB_YELLOW},
    {RGB_GOLD},
    {RGB_TEAL},
    {RGB_PURPLE},
    {RGB_ORANGE},
    {RGB_BLACK},
    {RGB_BLACK},
    {RGB_BLACK},
    {RGB_BLACK},
    {RGB_BLACK},
    {RGB_BLACK},
    {RGB_BLACK},
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
#ifdef CAPS_LOCK_LED_INDEX
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, 255, 255, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
            rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, 0, 0, 0);
        }
    }
#endif

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
