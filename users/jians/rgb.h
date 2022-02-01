#pragma once

#include QMK_KEYBOARD_H

void rgb_matrix_set_color_for_indices(
    uint8_t indices[],
    uint8_t size,
    uint8_t h,
    uint8_t s,
    uint8_t v
);
