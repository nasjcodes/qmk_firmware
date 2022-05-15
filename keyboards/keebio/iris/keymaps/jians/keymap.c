#include QMK_KEYBOARD_H

#include "jians.h"
#include "swapper.h"
#include "oneshot.h"
#include "rgb.h"
// #include "print.h"

extern keymap_config_t keymap_config;

/* Layers */
#define _COLEMAK 0
#define _QWERTY 1
#define _GAME 2
#define _GAMEFN 3
#define _LOWER 4
#define _RAISE 5
#define _NUM 6
#define _FUNC 7
#define _MISC 8
#define _ALT 9

/* Aliases */
// Layers
#define SPC_RSE LT(_RAISE, KC_SPC)
#define SPC_LWR LT(_LOWER, KC_SPC)
#define TAB_SFT MT(MOD_LSFT, KC_TAB)
#define BSP_NUM LT(_NUM, KC_BSPC)
#define ENT_MISC LT(_MISC, KC_ENT)
#define ALT_ALT LM(_ALT, MOD_LALT)

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

// clang-format off

#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define LAYOUT_iris_base( \
    N01, N02, N03, N04, N05,                 N06, N07, N08, N09, N0A, N0B, \
    K01, K02, K03, K04, K05,                 K06, K07, K08, K09, K0A, K0B, \
    K11, K12, K13, K14, K15,                 K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26,       K27, K28, K29, K2A, K2B, K2C,      \
                   K31, K32, K33,       K34, K35, K36 \
  ) \
  LAYOUT_wrapper( \
     KC_LGUI,  N01,    N02,     N03,      N04,     N05,                           N06,     N07,     N08,     N09,     N0A,     N0B,         \
     KC_TAB,   K01,    K02,     K03,      K04,     K05,                           K06,     K07,     K08,     K09,     K0A,     K0B,         \
     KC_ESC,   K11,    K12,     K13,      K14,     K15,                           K16,     K17,     K18,     K19,     K1A,     K1B,         \
     KC_LCTL,  K21,    K22,     K23,      K24,     K25,     K26,            K27,  K28,     K29,     K2A,     K2B,     K2C,     KC_MPLY,   \
                                          K31,     K32,     K33,            K34,  K35,     K36                                              \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_iris_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_base_wrapper(
        ________________NUMBER_LEFT________________,                        ________________NUMBER_RIGHT_______________, KC_BSPC,
        ______________COLEMAK_MOD_DH_L1____________,                        ______________COLEMAK_MOD_DH_R1____________, KC_DEL,
        ______________COLEMAK_MOD_DH_L2____________,                        ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, DF(_GAME),    AG_TOGG, ______________COLEMAK_MOD_DH_R3____________,
                                   ALT_ALT, KC_LSFT, SPC_LWR,      SPC_RSE, BSP_NUM, ENT_MISC
    ),

    [_QWERTY] = LAYOUT_base_wrapper(
        ________________NUMBER_LEFT________________,                        ________________NUMBER_RIGHT_______________, KC_BSPC,
        _________________QWERTY_L1_________________,                        _________________QWERTY_R1_________________, KC_DEL,
        _________________QWERTY_L2_________________,                        _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, DF(_GAME),    AG_TOGG, _________________QWERTY_R3_________________,
                                   ALT_ALT, KC_LSFT, SPC_LWR,      SPC_RSE, BSP_NUM, ENT_MISC
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
    //                                 KC_TAB,  KC_LALT, KC_SPC,                  DF(_QWERTY),  _______, _______
    //                             // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    // ),

    [_GAME] = LAYOUT_base_wrapper(
        ________________NUMBER_LEFT________________,                        ________________NUMBER_RIGHT_______________, KC_BSPC,
        ______________COLEMAK_MOD_DH_L1____________,                        ______________COLEMAK_MOD_DH_R1____________, KC_DEL,
        ______________COLEMAK_MOD_DH_L2____________,                        ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, KC_QUOT,    DF(_COLEMAK),  ______________COLEMAK_MOD_DH_R3____________,
                     LM(_GAMEFN, MOD_LALT), KC_LSFT, KC_SPC,     SPC_RSE, BSP_NUM, ENT_MISC
    ),

    [_GAMEFN] = LAYOUT_wrapper(
    DF(_COLEMAK), KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                       ___________________BLANK___________________, _______,
        _______, ___________________BLANK___________________,                         ___________________BLANK___________________, _______,
        KC_MPLY, ___________________BLANK___________________,                         ___________________BLANK___________________, _______,
        _______, ___________________BLANK___________________,    _______,    _______, ___________________BLANK___________________, _______,
                                            _______, _______, _______,    _______, _______, _______
    ),

    [_LOWER] = LAYOUT_wrapper(
        _______, AG_NORM, AG_SWAP, _______, _______, A(KC_F4),                      ___________________BLANK___________________, _______,
        _______, _______, SW_WIN,  _______, _______, LAUNCH,                        KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  KC_BSPC,
        _______, OS_GUI,  OS_CTL,  OS_SFT,  OS_ALT,  SAVE,                          KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PSCR, KC_DEL,
        _______, UNDO,    CUT,     COPY,    PASTE,   REDO,    _______,     _______, ___________________BLANK___________________, _______,
                                            _______, _______, _______,     _______, KC_DEL,  _______
    ),

    [_RAISE] = LAYOUT_wrapper(
        _______, ___________________BLANK___________________,                       ___________________BLANK___________________, _______,
        _______, _______, KC_TILD, KC_ASTR, KC_AMPR, KC_UNDS,                       KC_PLUS, KC_DQT,  KC_LBRC, KC_RBRC, _______, _______,
        _______, KC_CIRC, KC_GRV,  KC_PERC, KC_DLR,  KC_MINS,                       KC_EQL,  KC_COLN, KC_LPRN, KC_RPRN, KC_BSLS, _______,
        _______, _______, KC_HASH, KC_AT,   KC_EXLM, KC_PIPE, _______,     _______, KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, KC_QUES, _______,
                                            _______, _______, _______,     _______, _______,  _______
    ),

    [_NUM] = LAYOUT_wrapper(
        _______, ___________________BLANK___________________,                       ___________________BLANK___________________, _______,
        _______, _______, KC_7,    KC_8,    KC_9,    _______,                       KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  _______,
        _______, _______, KC_4,    KC_5,    KC_6,    _______,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PSCR, _______,
        _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,     _______, _______, OS_ALT,  OS_SFT,  OS_CTL,  OS_GUI,  _______,
                                            _______, KC_0,    _______,     _______, _______, _______
    ),

    [_FUNC] = LAYOUT_wrapper(
        _______, ___________________BLANK___________________,                       ___________________BLANK___________________, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                       ___________________BLANK___________________, _______,
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                       _______, OS_ALT,  OS_SFT,  OS_CTL,  OS_GUI,  _______,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,     _______, ___________________BLANK___________________, _______,
                                            _______, _______, _______,     _______, _______, _______
    ),

    [_MISC] = LAYOUT_wrapper(
        _______, _______, _______, _______, RGB_VAD, RGB_VAI,                       ___________________BLANK___________________, RESET,
        _______, _______, _______, _______, RGB_SAD, RGB_SAI,                       _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  DF(_QWERTY),
        _______, _______, _______, _______, RGB_HUD, RGB_HUI,                       _______, KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_F21,  _______,
                                         _______, _______, TO(_LOWER),     _______, _______, _______
    ),

    [_ALT] = LAYOUT_wrapper(
    _______, ___________________BLANK___________________,                         ___________________BLANK___________________, _______,
    _______, ___________________BLANK___________________,                         ___________________BLANK___________________, _______,
    KC_MPLY, ___________________BLANK___________________,                         ___________________BLANK___________________, _______,
    _______, ___________________BLANK___________________,    _______,    _______, ___________________BLANK___________________, _______,
                                        _______, _______, _______,    _______, _______, _______
    )
};
// clang-format on

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

const ONESHOT shft = {state : os_up_unqueued, KC_LSFT, OS_SFT, led_index : 15};
const ONESHOT ctrl = {state : os_up_unqueued, KC_LCTL, OS_CTL, led_index : 14};
const ONESHOT alt  = {state : os_up_unqueued, KC_LALT, OS_ALT, led_index : 16};
const ONESHOT cmd  = {state : os_up_unqueued, KC_LGUI, OS_GUI, led_index : 13};

ONESHOT osm_arr[]    = {shft, ctrl, alt, cmd};
int     OSM_ARR_SIZE = 4;

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
    switch (keycode) {
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

    update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, keycode, record);

    bool osm_cancelled = false;
    for (int i = 0; i < OSM_ARR_SIZE; i++) {
        bool canc = update_oneshot(&osm_arr[i], keycode, record);

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
#define HSV_PRIMARY 120, 191, 80     // Cyan
#define HSV_SECONDARY 213, 255, 80   // Magenta
#define HSV_HIGHLIGHT 237, 255, 160  // Magenta bright

// ESDF indices
uint8_t esdf_indices[] = {8, 14, 15, 16};
// IJKL indices
uint8_t ijkl_indices[] = {42, 48, 49, 50};
// outermost thumb keys
uint8_t outer_thumb_indices[] = {24, 58};

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_PRIMARY);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _GAME:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
            break;
        case _QWERTY:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(HSV_PRIMARY);
            break;
        default:  //  for any other layers, or the default layer
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_PRIMARY);
            break;
    }

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _FUNC);
    switch (get_highest_layer(state | default_layer_state)) {
        case _MISC:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_SECONDARY);
            break;
        case _GAME:
        case _GAMEFN:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
            break;
        case _QWERTY:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(HSV_PRIMARY);
            break;
        default:  //  for any other layers, or the default layer
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_PRIMARY);
            break;
    }

    return state;
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = {HSV_HIGHLIGHT};
    RGB rgb = hsv_to_rgb(hsv);

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _LOWER:
            rgb_matrix_set_color_for_indices(ijkl_indices, 4, HSV_SECONDARY);
            break;
        default:
            break;
    }

    for (int i = 0; i < OSM_ARR_SIZE; i++) {
        if (osm_arr[i].state != os_up_unqueued) {
            rgb_matrix_set_color(osm_arr[i].led_index, rgb.r, rgb.g, rgb.b);
        }
    }

    if (!is_win_os()) {
        rgb_matrix_set_color_for_indices(outer_thumb_indices, 2, HSV_SECONDARY);
    }
}
