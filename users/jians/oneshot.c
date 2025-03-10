#include "oneshot.h"

bool update_oneshot(
    ONESHOT *oneshot,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == oneshot->trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (oneshot->state == os_up_unqueued) {
                register_code(oneshot->mod);
            }
            oneshot->state = os_down_unused;
        } else {
            // Trigger keyup
            switch (oneshot->state) {
            case os_down_unused:
                // If we didn't use the mod while trigger was held, queue it.
                oneshot->state = os_up_queued;
                break;
            case os_down_used:
                // If we did use the mod while trigger was held, unregister it.
                oneshot->state = os_up_unqueued;
                unregister_code(oneshot->mod);
                break;
            default:
                break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode)) {

                switch (oneshot->state) {
                    // ignored if oneshot is not queued or currently still holding
                    case os_up_unqueued:
                    case os_down_used:
                        break;

                    // consider used on keydown of cancel key
                    case os_down_unused:
                        oneshot->state = os_down_used;
                        break;

                    // Cancel oneshot on designated cancel keydown.
                    default:
                        oneshot->state = os_up_unqueued;
                        unregister_code(oneshot->mod);
                        return true;
                        break;
                }
            }
        } else {
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (oneshot->state) {
                    case os_down_unused:
                        oneshot->state = os_down_used;
                        break;
                    case os_up_queued:
                        oneshot->state = os_up_unqueued;
                        unregister_code(oneshot->mod);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    return false;
}
