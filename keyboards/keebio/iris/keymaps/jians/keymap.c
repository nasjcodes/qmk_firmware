#include QMK_KEYBOARD_H

#include "swapper.h"
#include "oneshot.h"
#include "rgb.h"
#include "print.h"

extern keymap_config_t keymap_config;

/* Layers */
#define _MAIN 0
#define _GAME 1
#define _LOWER 2
#define _RAISE 3
#define _FUNC 4
#define _MISC 5

/* Aliases */
// Layers
#define SPC_RSE LT(_RAISE, KC_SPC)
#define TAB_SFT MT(MOD_LSFT, KC_TAB)
#define BSP_SFT MT(MOD_LSFT, KC_BSPC)
#define DEL_SFT MT(MOD_LSFT, KC_DEL)
#define SPC_LWR LT(_LOWER, KC_SPC)
#define ESC_FN LT(_FUNC, KC_ESC)
// #define OS_CTL OSM(MOD_LCTL)
// #define OS_GUI OSM(MOD_LGUI)
// #define OS_ALT OSM(MOD_LALT)
// #define OS_SFT OSM(MOD_LSFT)
// Text editing
// Brackets
// #define BR_LPR S(KC_9) // (
// #define BR_RPR S(KC_0) // )
// #define BR_LCUR S(KC_LBRC) // {
// #define BR_RCUR S(KC_RBRC) // }
// #define BR_LSQ KC_LBRC // [
// #define BR_RSQ KC_RBRC // ]

enum keycodes {
    SW_WIN = SAFE_RANGE,  // Switch to next window         (alt-tab)

    // Callum's custom oneshot mod implementation with no timers.
    OS_SFT,
    OS_CTL,
    OS_ALT,
    OS_GUI,

    UNDO,
    CUT,
    COPY,
    PASTE,
    REDO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAIN] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    RESET,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    DF(_GAME),        _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSL(_MISC),
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       KC_LALT,  TAB_SFT, SPC_LWR,                   SPC_RSE, KC_BSPC, KC_ENT
                                //    └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    // // SHIFTED
    // [_GAME] = LAYOUT(
    // //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    //     _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    // //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    //     KC_T,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    // //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    //     KC_G,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
    // //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    //     KC_B,    KC_ESC,  KC_Z,    KC_X,    KC_C,    KC_V,    _______,          _______,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, _______,
    // //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
    //                                 KC_TAB,  KC_LALT, KC_SPC,                  DF(_MAIN),  _______, _______
    //                             // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    // ),

    // NORMAL
    [_GAME] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSL(_MISC),
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       KC_LALT, KC_LSFT, KC_SPC,                  DF(_MAIN), KC_BSPC, KC_ENT
                                //    └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_LOWER] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, A(KC_F4),                           _______, _______, _______, _______, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, SW_WIN,  _______, _______, _______,                            _______, KC_7,    KC_8,    KC_9,    _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LGUI,  OS_CTL,  OS_SFT,  OS_ALT,  _______,                            _______, KC_4,    KC_5,    KC_6,    _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, UNDO,    CUT,     COPY,    PASTE,   REDO,    _______,          _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______, _______, _______,                   _______, KC_DEL,  KC_0
                                //    └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_RAISE] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_UNDS,                            KC_PLUS, KC_HOME, KC_UP,   KC_END,  KC_INS,  _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LGUI,  OS_CTL,  OS_SFT,  OS_ALT,  KC_MINS,                            KC_EQL,  KC_LEFT, KC_DOWN, KC_RIGHT,KC_PSCR, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_ASTR, KC_AMPR, KC_CIRC, KC_PERC, KC_TILD, _______,          _______, KC_GRV,  KC_PGUP, KC_PGDN, _______, _______, _______,
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______, _______, _______,                   _______,  KC_DEL,  _______
                                //    └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_FUNC] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                            _______, _______, _______, _______, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                            _______, OS_ALT,  OS_SFT,  OS_CTL,  KC_LGUI,  _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______, _______, _______,                   _______, _______, _______
                                //    └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    // // Original _MISC
    // [_MISC] = LAYOUT(
    // //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    //     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    // //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    //     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    // //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    //     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
    // //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    //     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
    // //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
    //                                 _______, _______, _______,                   _______, _______, _______
    //                             // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    // )

    [_MISC] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                            _______, _______, KC_F13,  KC_F14,  KC_F15,  _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                            _______, _______, KC_F16,  KC_F17,  KC_F18,  _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                            _______, _______, KC_F19,  KC_F20,  KC_F21,  _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, AG_NORM,          AG_SWAP, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______, _______, TO(_LOWER),                  TO(_RAISE), _______, _______
                                //    └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    )
};

/* Combos */
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(df_combo, KC_LPRN), // (
    COMBO(jk_combo, KC_RPRN), // )
    COMBO(er_combo, KC_LCBR), // {
    COMBO(ui_combo, KC_RCBR), // }
    COMBO(cv_combo, KC_LBRC), // [
    COMBO(mcomm_combo, KC_RBRC) // ]
};

/* Oneshot config */
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case SPC_RSE:
    case SPC_LWR:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case SPC_RSE:
        case SPC_LWR:
        case KC_LSFT:
        case OS_SFT:
        case OS_CTL:
        case OS_ALT:
        case OS_GUI:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

/* Swapper config */
bool sw_win_active = false;

bool is_swapper_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case OS_SFT:
            return true;
        default:
            return false;
    }
}

uint16_t get_ctrl_or_cmd(uint8_t code) {
    if (keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
        return G(code);
    } else {
        return C(code);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case UNDO:
            if (record->event.pressed) {
                register_code16(get_ctrl_or_cmd(KC_Z));
            } else {
                unregister_code16(get_ctrl_or_cmd(KC_Z));
            }
            return false;
        case CUT:
            if (record->event.pressed) {
                register_code16(get_ctrl_or_cmd(KC_X));
            } else {
                unregister_code16(get_ctrl_or_cmd(KC_X));
            }
            return false;
        case COPY:
            if (record->event.pressed) {
                register_code16(get_ctrl_or_cmd(KC_C));
            } else {
                unregister_code16(get_ctrl_or_cmd(KC_C));
            }
            return false;
        case PASTE:
            if (record->event.pressed) {
                register_code16(get_ctrl_or_cmd(KC_V));
            } else {
                unregister_code16(get_ctrl_or_cmd(KC_V));
            }
            return false;
        case REDO:
            if (record->event.pressed) {
                register_code16(get_ctrl_or_cmd(KC_Y));
            } else {
                unregister_code16(get_ctrl_or_cmd(KC_Y));
            }
            return false;
    }

    update_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_GUI,
        keycode, record
    );

    return true;
}

/* RGB */
#define HSV_PRIMARY     128, 255, 100 // Cyan
#define HSV_SECONDARY     213, 255, 100 // Magenta

// ESDF indices
uint8_t esdf_indices [] = { 8, 14, 15, 16 };
// Left side underglow indices:
uint8_t underglow_l_indices [] = { 28, 29, 30, 31, 32, 33 };
// Right side underglow indices
uint8_t underglow_r_indices [] = { 62, 63, 64, 65, 66, 67 };
// Underglow primary
uint8_t underglow_pri_indices [] = { 29, 31, 33, 63, 65, 67 };
// Underglow secondary
uint8_t underglow_sec_indices [] = { 28, 30, 32, 62, 64, 66 };

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_PRIMARY);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _GAME:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
            rgb_matrix_set_color_for_indices(esdf_indices, 4, HSV_SECONDARY);
            // rgb_matrix_set_color_for_indices(underglow_pri_indices, 6, HSV_PRIMARY);
            // rgb_matrix_set_color_for_indices(underglow_sec_indices, 6, HSV_SECONDARY);
            combo_disable();
            break;
        default: //  for any other layers, or the default layer
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            combo_enable();
            break;
    }

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // switch (get_highest_layer(state)) {
    // case _RAISE:
    //     rgblight_setrgb (0x00,  0x00, 0xFF);
    //     break;
    // case _LOWER:
    //     rgblight_setrgb (0xFF,  0x00, 0x00);
    //     break;
    // case _PLOVER:
    //     rgblight_setrgb (0x00,  0xFF, 0x00);
    //     break;
    // case _ADJUST:
    //     rgblight_setrgb (0x7A,  0x00, 0xFF);
    //     break;
    // default: //  for any other layers, or the default layer
    //     rgblight_setrgb (0x00,  0xFF, 0xFF);
    //     break;
    // }
  return state;
}
