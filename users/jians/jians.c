#include "jians.h"
// #include "print.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // uprintf("0x%04X keycode\n", keycode);
    switch (keycode) {
        case STR_TV:
            if (record->event.pressed) {
                register_code(KC_RCTL);
                register_code(KC_RSFT);
                register_code(KC_F13);
            } else {
                unregister_code(KC_F13);
                unregister_code(KC_RSFT);
                unregister_code(KC_RCTL);
            }
            return false;
        }
    return true;
};
