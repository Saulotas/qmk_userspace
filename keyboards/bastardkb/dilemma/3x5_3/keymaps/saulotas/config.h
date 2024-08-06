/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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
#pragma once

#undef MOUSE_EXTENDED_REPORT
#undef CIRQUE_PINNACLE_DIAMETER_MM
#undef CIRQUE_PINNACLE_CURVED_OVERLAY
#undef POINTING_DEVICE_GESTURES_SCROLL_ENABLE 
#undef MOUSE_EXTENDED_REPORT
#undef POINTING_DEVICE_TASK_THROTTLE_MS
#undef POINTING_DEVICE_ROTATION_90
#undef SPI_DRIVER 
#undef SPI_SCK_PIN
#undef SPI_MOSI_PIN 
#undef SPI_MISO_PIN 
#undef POINTING_DEVICE_CS_PIN 

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

/* SPI & PMW3360 settings. */

#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20
#define POINTING_DEVICE_CS_PIN GP21


/* Trackball angle adjustment. */
#define ROTATIONAL_TRANSFORM_ANGLE -25

// Limits the frequency that the sensor is polled for motion.
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

// Invert X axis on mouse reports.
#define POINTING_DEVICE_INVERT_X

/*OLED config*/
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3
#define I2C1_DRIVER I2CD1

#define OLED_DISPLAY_128X64




