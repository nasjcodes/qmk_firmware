#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        CTL_T(KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   MO(2),   KC_RCTL
    ),
    [1] = LAYOUT_60_ansi(
        KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, KC_UP,   _______, _______, _______, KC_CALC, _______, KC_INS,  _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP,          _______,
        KC_MPRV,          KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, NK_TOGG, _______, _______, KC_END,  KC_PGDN,          KC_MNXT,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
    [2] = LAYOUT_60_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, RGB_TOG, _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),

    [3] = LAYOUT_60_ansi(
        _______, _______,   _______, _______,   _______, _______,   _______, _______,   _______, _______,   _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )
};

void rgb_matrix_indicators_kb(void) {
    if (layer_state_is(2)) {
        RGB rgb = { r: 0, g: 200, b: 0 };

        // PL;'
        rgb_matrix_set_color(17, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(31, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(29, rgb.r, rgb.g, rgb.b);
    }

    if (layer_state_is(3)) {
        RGB rgb = { r: 0, g: 200, b: 0 };

        // IOP
        rgb_matrix_set_color(19, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(18, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(17, rgb.r, rgb.g, rgb.b);

        // KL;
        rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(31, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);

        // M,.
        rgb_matrix_set_color(44, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(43, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(42, rgb.r, rgb.g, rgb.b);

        // Right-Alt/Super/Fn
        rgb_matrix_set_color(56, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(55, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(54, rgb.r, rgb.g, rgb.b);
    }
}