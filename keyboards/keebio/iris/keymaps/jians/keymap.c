#include QMK_KEYBOARD_H

#include "swapper.h"
#include "oneshot.h"
#include "rgb.h"
#include "print.h"

extern keymap_config_t keymap_config;

/* Layers */
#define _MAIN 0
#define _LOWER 1
#define _RAISE 2
#define _NUM 3
#define _FUNC 4
#define _MISC 5
#define _GAME 6
#define _GAMEFN 7

/* Aliases */
// Layers
#define SPC_RSE LT(_RAISE, KC_SPC)
#define SPC_LWR LT(_LOWER, KC_SPC)
#define TAB_SFT MT(MOD_LSFT, KC_TAB)
#define BSP_NUM LT(_NUM, KC_BSPC)
#define ENT_MISC LT(_MISC, KC_ENT)

#define ESC_SFT MT(MOD_LSFT, KC_ESC)

enum keycodes {
    SW_WIN = SAFE_RANGE,  // Switch to next window         (alt-tab)

    // Callum's custom oneshot mod implementation with no timers.
    OS_SFT,
    OS_CTL,
    OS_ALT,
    OS_GUI,

    LAUNCH,

    UNDO,
    CUT,
    COPY,
    PASTE,
    REDO,
    SAVE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAIN] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_LGUI,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    DF(_GAME),        _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSL(_MISC),
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       KC_LALT, KC_LSFT, SPC_LWR,                   SPC_RSE, BSP_NUM, ENT_MISC
                                //    └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_LOWER] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, A(KC_F4),                           _______, _______, _______, _______, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, SW_WIN,  _______, _______, _______,                            KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  KC_BSPC,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LGUI, OS_CTL,  OS_SFT,  OS_ALT,  SAVE,                               KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PSCR, KC_DEL,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, UNDO,    CUT,     COPY,    PASTE,   REDO,    _______,          _______, _______, LAUNCH,  _______, _______, _______, _______,
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        _______, _______, _______,                   _______, KC_DEL,  _______
                                //    └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_RAISE] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, KC_TILD, KC_ASTR, KC_AMPR, KC_UNDS,                            KC_PLUS, KC_LCBR, KC_PIPE, KC_RCBR, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, KC_CIRC,  KC_PERC, KC_DLR, KC_MINS,                            KC_EQL,  KC_LPRN, KC_BSLS, KC_RPRN, KC_COLN, KC_DQT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, KC_HASH, KC_AT,   KC_EXLM, KC_GRV,  _______,          _______, KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, KC_QUES, _______,
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______, _______, _______,                   _______, _______,  _______
                                //    └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_NUM] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, OS_ALT,  OS_SFT,  OS_CTL,  KC_LGUI, _______,
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______, _______, _______,                   _______, _______, _______
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

    [_MISC] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, RGB_VAD, RGB_VAI,                            _______, _______, _______, _______, _______, RESET,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, RGB_SAD, RGB_SAI,                            _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, RGB_HUD, RGB_HUI,                            _______, KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, AG_NORM,          AG_SWAP, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_F21,  _______,
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______, _______, TO(_LOWER),               TO(_RAISE), _______, _______
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
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_QUOT,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSL(_MISC),
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                             LM(_GAMEFN, MOD_LSFT), KC_LALT, KC_SPC,                    DF(_MAIN), BSP_NUM , KC_ENT
                                //    └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_GAMEFN] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_MINS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              _______, _______, _______, _______, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______,  KC_P,   KC_O,    _______, KC_U,    KC_Y,                               _______, _______, _______, _______, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, KC_H,                               _______, _______, _______, _______, _______, _______,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    _______,          _______, _______, _______, _______, _______, _______, _______,
    // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______, _______, _______,                   _______, _______, _______
                                //    └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    )
};

// cannot double tap to hold tap action
// For entire thumb cluster
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPC_RSE:
        case SPC_LWR:
        case TAB_SFT:
        case BSP_NUM:
            return true;
        default:
            return false;
    }
}

// Able to tap keys immediately without waiting for release (permissive hold still requires key to be released when within tapping term)
// For secondary thumb keys
// include main left thumb since space is rarely used
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TAB_SFT:
        case BSP_NUM:
        case SPC_LWR:
        case ENT_MISC:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_SFT:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        default:
            // Force the mod-tap key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return false;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _FUNC);
}

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

const ONESHOT shft = {
    state: os_up_unqueued,
    KC_LSFT,
    OS_SFT,
    led_index: 15
};
const ONESHOT ctrl = {
    state: os_up_unqueued,
    KC_LCTL,
    OS_CTL,
    led_index: 14
};
const ONESHOT alt = {
    state: os_up_unqueued,
    KC_LALT,
    OS_ALT,
    led_index: 16
};
const ONESHOT cmd = {
    state: os_up_unqueued,
    KC_LGUI,
    OS_GUI,
    led_index: 13
};

ONESHOT osm_arr[] = { shft, ctrl, alt, cmd };
int OSM_ARR_SIZE = 4;

/* Swapper config */
bool sw_win_active = false;

bool is_swapper_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case OS_SFT:
        case KC_LSFT:
            return true;
        default:
            return false;
    }
}

bool is_win_os(void) {
    if (keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
        return false;
    }

    return true;
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
        case SAVE:
            if (record->event.pressed) {
                register_code16(get_ctrl_or_cmd(KC_S));
            } else {
                unregister_code16(get_ctrl_or_cmd(KC_S));
            }
            return false;

        case LAUNCH:
            if (record->event.pressed) {
                if (is_win_os()) {
                    register_code(KC_LGUI);
                    register_code(KC_GRV);
                } else {
                    register_code(KC_LGUI);
                    register_code(KC_SPC);
                }
            } else {
                if (is_win_os()) {
                    unregister_code(KC_LGUI);
                    unregister_code(KC_GRV);
                } else {
                    unregister_code(KC_LGUI);
                    unregister_code(KC_SPC);
                }
            }
            return false;
    }

    update_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN,
        keycode, record
    );

    bool osm_cancelled = false;
    for (int i = 0; i < OSM_ARR_SIZE; i++) {
        bool canc = update_oneshot(
            &osm_arr[i],
            keycode, record
        );

        if (canc) {
            osm_cancelled = canc;
        }
    }

    if (osm_cancelled) {
        // don't trigger key if oneshot was cancelled
        return false;
    }

    return true;
}

/* RGB */
#define HSV_PRIMARY     120, 191, 80 // Cyan
#define HSV_SECONDARY     213, 255, 80 // Magenta
#define HSV_HIGHLIGHT     237, 255, 160 // Magenta bright

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
// outermost thumb keys
uint8_t outer_thumb_indices [] = { 24, 58 };

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_PRIMARY);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _GAME:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
            break;
        default: //  for any other layers, or the default layer
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            break;
    }

    return state;
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = { HSV_HIGHLIGHT };
    RGB rgb = hsv_to_rgb(hsv);

    for (int i = 0; i < OSM_ARR_SIZE; i++) {
        if (osm_arr[i].state != os_up_unqueued) {
            rgb_matrix_set_color(osm_arr[i].led_index, rgb.r, rgb.g, rgb.b);
        }
    }

    if (!is_win_os()) {
        rgb_matrix_set_color_for_indices(outer_thumb_indices, 2, HSV_SECONDARY);
    }
}
