/* Copyright 2022 DOIO
 * Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
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

#include "quantum.h"

#define ANIM_SIZE 525  // number of bytes in array, minimize for adequate firmware size, max is 1024

void render_logo(void) {
    static const char PROGMEM doio[][ANIM_SIZE] = {
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x20, 0x30, 0x10, 0x18, 0x08, 0x08,
        0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02,
        0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x08, 0x08, 0x18, 0x10, 0x30, 0x20, 0x60, 0xc0,
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0xf0, 0xfc, 0x0e, 0x03, 0x01, 0x00, 0xf8, 0xf8, 0xf8, 0x38, 0x38, 0x38, 0xf0,
        0xf0, 0xe0, 0x00, 0xc0, 0xe0, 0xf0, 0x70, 0x38, 0x38, 0x38, 0x70, 0xf0, 0xe0, 0xc0, 0x00, 0x18,
        0xf8, 0xf8, 0xf8, 0x18, 0x00, 0xc0, 0xe0, 0xf0, 0x70, 0x38, 0x38, 0x38, 0x70, 0xf0, 0xe0, 0xc0,
        0x01, 0x03, 0x0e, 0xfc, 0xf8, 0x80, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xf8,
        0xf8, 0xf8, 0x80, 0xc0, 0xe0, 0xf0, 0x78, 0x38, 0x18, 0x00, 0xf8, 0xf8, 0xf8, 0xb8, 0xb8, 0xb8,
        0xf8, 0xf8, 0x70, 0x00, 0x60, 0x60, 0x70, 0x78, 0xf8, 0xf8, 0xf8, 0x00, 0xe0, 0xf0, 0xf0, 0xb8,
        0xb8, 0xb8, 0xb8, 0xb8, 0x30, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0xe0, 0xf0, 0xf8,
        0x38, 0x38, 0x38, 0xf8, 0xf0, 0xe0, 0x00, 0x60, 0x60, 0x70, 0x78, 0xf8, 0xf8, 0xf8, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x0f, 0x3f, 0x70, 0xc0, 0x80, 0x00, 0x1f, 0x1f, 0x1f, 0x1c, 0x1c, 0x1c, 0x0f,
        0x0f, 0x07, 0x00, 0x03, 0x07, 0x0f, 0x0e, 0x1c, 0x1c, 0x1c, 0x0e, 0x0f, 0x07, 0x03, 0x00, 0x18,
        0x1f, 0x1f, 0x1f, 0x18, 0x00, 0x03, 0x07, 0x0f, 0x0e, 0x1c, 0x1c, 0x1c, 0x0e, 0x0f, 0x07, 0x03,
        0x80, 0xc0, 0x70, 0x3f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x1f,
        0x1f, 0x1f, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1c, 0x18, 0x00, 0x1f, 0x1f, 0x1f, 0x1d, 0x1d, 0x1d,
        0x1f, 0x1f, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x00, 0x07, 0x0f, 0x0f, 0x1d,
        0x1d, 0x1d, 0x1f, 0x1f, 0x0f, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x07, 0x0f, 0x1f,
        0x1c, 0x1c, 0x1c, 0x1f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x04, 0x0c, 0x08, 0x18, 0x10, 0x10,
        0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40,
        0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x10, 0x10, 0x18, 0x08, 0x0c, 0x04, 0x06, 0x03,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };

    oled_write_raw_P(doio[0], ANIM_SIZE);
}
