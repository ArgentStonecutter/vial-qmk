#ifdef RGB_MATRIX_ENABLE

static uint8_t cf_magic = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CF_TOGGLE:
            if (record->event.pressed)
                cf_magic = !cf_magic;
            return false;
	case AP_GLOB:
	    host_consumer_send(record->event.pressed ? AC_NEXT_KEYBOARD_LAYOUT_SELECT : 0);
	    return false;
    }

    return true;
}

static int colors[][3] = {
    {-1, -1, -1},
    {RGB_BLUE},
    {RGB_GREEN},
    {RGB_RED},
    {-1,-1,-1},
    {RGB_CYAN},
    {RGB_PURPLE},
    {RGB_GOLD},
    {RGB_TEAL},
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
