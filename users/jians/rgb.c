#include "rgb.h"

void rgb_matrix_set_color_for_indices(uint8_t indices[] , uint8_t size, uint8_t h, uint8_t s, uint8_t v) {
    HSV hsv = { h, s, v };
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = 0; i < size; i++) {
        rgb_matrix_set_color(indices[i], rgb.r, rgb.g, rgb.b);
    }
}
