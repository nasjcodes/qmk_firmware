/*
Copyright 2021 <felix@fjlaboratories.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "jians.h"

#define LAYOUT_wrapper(...)            LAYOUT_65_ansi_blocker_all(__VA_ARGS__)

/* Aliases */
#define ESC_1 LT(1, KC_ESC)
#define ALT_3 LM(3, MOD_LALT)

enum layers {
    _LAYER0,
    _LAYER1,
    _LAYER2,
    _LAYER3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_LAYER0] = LAYOUT_wrapper(
        KC_GRV,  ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        ESC_1,  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,           KC_ENT,  KC_DEL,  KC_PGDN,
        KC_LSFT, KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, ALT_3,                         KC_SPC,                                 KC_RALT, MO(2),    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LAYER1] = LAYOUT_wrapper(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_DEL,  KC_PSCR,
        KC_TRNS, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_VOLU,
        KC_TRNS, ___________________BLANK___________________, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_VOLD,
        KC_TRNS, KC_LSFT, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS
    ),

    [_LAYER2] = LAYOUT_wrapper(
        KC_TRNS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
        KC_TRNS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LSFT, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_LAYER3] = LAYOUT_wrapper(
        KC_TRNS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS, STR_TV,
        KC_TRNS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_MPLY, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LSFT, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

};
