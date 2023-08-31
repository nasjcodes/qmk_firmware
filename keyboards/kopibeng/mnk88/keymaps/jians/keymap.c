/* Copyright 2021 Samuel Lu
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
#include "jians.h"

/* Aliases */
#define ESC_1 LT(1, KC_ESC)
#define ALT_3 LM(3, MOD_LALT)

#define LAYOUT_wrapper(...)            LAYOUT_all(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default layer
    [0] = LAYOUT_wrapper(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,           KC_PSCR, KC_SCRL, KC_MPLY,
        KC_GRV,  ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,  KC_END,  KC_PGDN,
        ESC_1,   _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,                   KC_ENT,
        KC_LSFT, KC_NUBS, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSFT, MO(3),                     KC_UP,
        KC_LCTL, KC_LGUI, ALT_3,                             KC_SPC,                             KC_RALT,  MO(2),   KC_RGUI, KC_RCTL,          KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // Fn1 Layer
    [1] = LAYOUT_wrapper(
        KC_TRNS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_VOLU,
        KC_TRNS, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_MPRV, KC_MNXT, KC_VOLD,
        KC_TRNS, ___________________BLANK___________________, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_NUBS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS,                   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Fn2 Layer
    [2] = LAYOUT_wrapper(
        KC_TRNS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, QK_BOOT,
        KC_TRNS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_NUBS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS,                   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Fn3 Layer
    [3] = LAYOUT_wrapper(
        KC_TRNS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, STR_TV,           KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_MPLY, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_NUBS, ___________________BLANK___________________, ___________________BLANK___________________, KC_TRNS, KC_TRNS,                   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),

};

