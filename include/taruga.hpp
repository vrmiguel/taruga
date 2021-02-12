/*
 * taruga
 * https://github.com/vrmiguel/taruga
 *
 * Copyright (c) 2020 Vinícius R. Miguel
 * <vinicius.miguel at unifesp.br>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __TARUGA_MAIN_HPP
#define __TARUGA_MAIN_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

#include <cmath>
#include <stack>
#include <queue>

//! TODO:
//! Decide whether or not to include a second built-in icon

//! Holds a 32x32 PNG cute turtle icon
static const uint8_t __turtle_png[1479] = {
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20,
    0x08, 0x03, 0x00, 0x00, 0x00, 0x44, 0xa4, 0x8a, 0xc6, 0x00, 0x00, 0x00,
    0x03, 0x73, 0x42, 0x49, 0x54, 0x08, 0x08, 0x08, 0xdb, 0xe1, 0x4f, 0xe0,
    0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x00, 0xdd,
    0x00, 0x00, 0x00, 0xdd, 0x01, 0x70, 0x53, 0xa2, 0x07, 0x00, 0x00, 0x00,
    0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6f, 0x66, 0x74, 0x77, 0x61, 0x72,
    0x65, 0x00, 0x77, 0x77, 0x77, 0x2e, 0x69, 0x6e, 0x6b, 0x73, 0x63, 0x61,
    0x70, 0x65, 0x2e, 0x6f, 0x72, 0x67, 0x9b, 0xee, 0x3c, 0x1a, 0x00, 0x00,
    0x02, 0x8b, 0x50, 0x4c, 0x54, 0x45, 0xff, 0xff, 0xff, 0x00, 0x80, 0x80,
    0x00, 0x80, 0x80, 0x40, 0xff, 0x80, 0x4d, 0xe6, 0x66, 0xb3, 0xe6, 0x33,
    0x5d, 0xe8, 0x5d, 0xb9, 0xe8, 0x2e, 0x4e, 0xeb, 0x62, 0xb1, 0xd8, 0x3b,
    0x5b, 0xdb, 0x5b, 0xb6, 0xdb, 0x37, 0xbb, 0xdd, 0x33, 0xb8, 0xe3, 0x39,
    0x00, 0xaa, 0x61, 0x55, 0xe7, 0x61, 0x55, 0xdf, 0x60, 0x00, 0xad, 0x5b,
    0x84, 0xe5, 0x46, 0xbc, 0xda, 0x3c, 0x55, 0xe5, 0x62, 0xb7, 0xde, 0x3b,
    0x00, 0x9f, 0x59, 0xb9, 0xdf, 0x39, 0xb6, 0xdb, 0x37, 0x51, 0xe2, 0x63,
    0x53, 0xe3, 0x5e, 0xb7, 0xde, 0x37, 0x00, 0xa4, 0x57, 0xb7, 0xdd, 0x3a,
    0x55, 0xe3, 0x5e, 0x55, 0xe3, 0x61, 0xba, 0xdf, 0x39, 0x52, 0xe4, 0x5e,
    0x55, 0xe4, 0x61, 0xb9, 0xdc, 0x3a, 0xb8, 0xdd, 0x38, 0xba, 0xde, 0x3a,
    0x53, 0xe2, 0x61, 0xbb, 0xdf, 0x39, 0x55, 0xe3, 0x60, 0x83, 0xe0, 0x4f,
    0x00, 0xab, 0x5e, 0x81, 0xde, 0x4c, 0xb9, 0xde, 0x38, 0x0a, 0xae, 0x5a,
    0x53, 0xe4, 0x5f, 0xba, 0xde, 0x3a, 0x00, 0xaa, 0x5d, 0x54, 0xe4, 0x5f,
    0x55, 0xe2, 0x60, 0xba, 0xdc, 0x38, 0xb8, 0xde, 0x3a, 0xb9, 0xdd, 0x3a,
    0xb8, 0xdd, 0x39, 0x00, 0xa0, 0x59, 0x7d, 0xe0, 0x50, 0x02, 0xa2, 0x59,
    0x53, 0xe3, 0x60, 0xb8, 0xdd, 0x39, 0x54, 0xe3, 0x60, 0xb9, 0xde, 0x3a,
    0x15, 0x9a, 0x4a, 0x00, 0x9f, 0x57, 0x53, 0xe3, 0x61, 0xb9, 0xde, 0x39,
    0x00, 0xab, 0x5e, 0x54, 0xe2, 0x60, 0x79, 0xe1, 0x52, 0x54, 0xe3, 0x60,
    0xb9, 0xdd, 0x3a, 0x00, 0xab, 0x5f, 0xb9, 0xdd, 0x39, 0x55, 0xe3, 0x60,
    0x54, 0xe3, 0x60, 0xba, 0xdd, 0x39, 0x77, 0xe0, 0x52, 0xb9, 0xdd, 0x39,
    0xb9, 0xde, 0x39, 0x54, 0xe3, 0x5f, 0x00, 0xab, 0x5f, 0xba, 0xde, 0x39,
    0xb9, 0xdd, 0x39, 0x55, 0xe3, 0x60, 0x54, 0xe3, 0x60, 0xba, 0xdd, 0x39,
    0x04, 0x8a, 0x46, 0x31, 0xc8, 0x5e, 0x8e, 0xd1, 0x43, 0x55, 0xe3, 0x60,
    0xb9, 0xdd, 0x38, 0x55, 0xe3, 0x5f, 0xb9, 0xdd, 0x39, 0xb9, 0xdc, 0x39,
    0x54, 0xe3, 0x60, 0x00, 0x9e, 0x57, 0x54, 0xe3, 0x60, 0xb9, 0xdd, 0x39,
    0x54, 0xe3, 0x5f, 0xb9, 0xdd, 0x39, 0x53, 0xe3, 0x60, 0xb9, 0xdd, 0x39,
    0x00, 0xab, 0x5e, 0x00, 0x9d, 0x56, 0x00, 0xa2, 0x57, 0x54, 0xe3, 0x60,
    0x00, 0x96, 0x50, 0x3c, 0xbb, 0x52, 0xb9, 0xdd, 0x39, 0x00, 0x9d, 0x56,
    0x2c, 0xb7, 0x55, 0x54, 0xe3, 0x60, 0x69, 0xe2, 0x59, 0x54, 0xe3, 0x60,
    0x54, 0xe3, 0x60, 0xb9, 0xdd, 0x39, 0xb9, 0xdd, 0x39, 0x0a, 0xa6, 0x58,
    0x54, 0xe3, 0x60, 0xb9, 0xdd, 0x39, 0x00, 0x9b, 0x55, 0x54, 0xe3, 0x5f,
    0xb9, 0xdd, 0x39, 0xb9, 0xdd, 0x39, 0x00, 0x83, 0x44, 0x00, 0x8e, 0x4c,
    0x0f, 0xa5, 0x55, 0x54, 0xe3, 0x60, 0xb9, 0xdd, 0x39, 0x00, 0x82, 0x41,
    0x03, 0x98, 0x50, 0x08, 0xa3, 0x56, 0x0d, 0x98, 0x4b, 0x4a, 0xb2, 0x46,
    0x54, 0xe3, 0x60, 0xb9, 0xdd, 0x39, 0x00, 0x75, 0x39, 0x00, 0x76, 0x39,
    0x00, 0x76, 0x3a, 0x00, 0x77, 0x3a, 0x00, 0x78, 0x3b, 0x00, 0x79, 0x3c,
    0x00, 0x7b, 0x3e, 0x00, 0x7c, 0x3e, 0x00, 0x7d, 0x3f, 0x00, 0x7e, 0x3f,
    0x00, 0x7f, 0x40, 0x00, 0x80, 0x41, 0x00, 0x81, 0x41, 0x00, 0x81, 0x42,
    0x00, 0x82, 0x42, 0x00, 0x82, 0x43, 0x00, 0x83, 0x43, 0x00, 0x85, 0x44,
    0x00, 0x85, 0x45, 0x00, 0x87, 0x45, 0x00, 0x87, 0x46, 0x00, 0x88, 0x46,
    0x00, 0x88, 0x47, 0x00, 0x89, 0x47, 0x00, 0x8d, 0x4b, 0x00, 0x8e, 0x4a,
    0x00, 0x8e, 0x4b, 0x00, 0x8f, 0x4b, 0x00, 0x90, 0x4b, 0x00, 0x90, 0x4c,
    0x00, 0x91, 0x4c, 0x00, 0x94, 0x4e, 0x00, 0x95, 0x4f, 0x00, 0x96, 0x50,
    0x00, 0x96, 0x52, 0x00, 0x97, 0x52, 0x00, 0x99, 0x52, 0x00, 0x99, 0x54,
    0x00, 0x9a, 0x53, 0x00, 0x9a, 0x54, 0x00, 0x9c, 0x54, 0x00, 0x9d, 0x55,
    0x00, 0xa2, 0x58, 0x00, 0xa9, 0x5d, 0x00, 0xaa, 0x5d, 0x00, 0xaa, 0x5e,
    0x00, 0xab, 0x5e, 0x01, 0x8f, 0x4c, 0x01, 0x9b, 0x55, 0x01, 0xab, 0x5e,
    0x02, 0x9d, 0x56, 0x03, 0x85, 0x43, 0x06, 0xac, 0x5d, 0x07, 0xa3, 0x57,
    0x09, 0xa5, 0x58, 0x0c, 0xa8, 0x58, 0x12, 0xb0, 0x5a, 0x14, 0xaf, 0x59,
    0x1e, 0xb3, 0x58, 0x2b, 0xb8, 0x54, 0x2d, 0xc4, 0x5c, 0x37, 0xba, 0x53,
    0x3c, 0xbb, 0x52, 0x3f, 0xcc, 0x5b, 0x3f, 0xd3, 0x5e, 0x40, 0xd3, 0x5e,
    0x42, 0xbd, 0x51, 0x4b, 0xdc, 0x5f, 0x50, 0xe0, 0x60, 0x54, 0xe3, 0x60,
    0x56, 0xe3, 0x5f, 0x57, 0xe3, 0x5f, 0x5a, 0xc3, 0x4c, 0x85, 0xc8, 0x3f,
    0x88, 0xd0, 0x43, 0x9c, 0xd2, 0x3c, 0xa0, 0xd6, 0x3e, 0xa1, 0xd7, 0x3e,
    0xaf, 0xda, 0x3b, 0xb5, 0xdc, 0x3a, 0xb9, 0xdd, 0x39, 0x36, 0xf4, 0x4c,
    0x4d, 0x00, 0x00, 0x00, 0x88, 0x74, 0x52, 0x4e, 0x53, 0x00, 0x02, 0x04,
    0x04, 0x0a, 0x0a, 0x0b, 0x0b, 0x0d, 0x0d, 0x0e, 0x0e, 0x0f, 0x12, 0x15,
    0x15, 0x18, 0x1c, 0x1d, 0x22, 0x27, 0x27, 0x28, 0x28, 0x2a, 0x2c, 0x2e,
    0x2e, 0x35, 0x35, 0x36, 0x3f, 0x3f, 0x41, 0x42, 0x42, 0x44, 0x46, 0x47,
    0x47, 0x48, 0x4a, 0x4c, 0x4d, 0x4d, 0x4f, 0x56, 0x5c, 0x5d, 0x5e, 0x60,
    0x60, 0x65, 0x6a, 0x70, 0x81, 0x83, 0x84, 0x90, 0x90, 0x92, 0x92, 0x95,
    0x98, 0x99, 0x99, 0x9e, 0xa0, 0xa2, 0xa4, 0xa4, 0xaa, 0xaa, 0xac, 0xad,
    0xad, 0xaf, 0xaf, 0xb0, 0xb3, 0xba, 0xbf, 0xc1, 0xc7, 0xc9, 0xca, 0xcc,
    0xcf, 0xcf, 0xd0, 0xd0, 0xd3, 0xd3, 0xd6, 0xd8, 0xda, 0xda, 0xda, 0xdb,
    0xdb, 0xdc, 0xdc, 0xe0, 0xe3, 0xe4, 0xe9, 0xea, 0xea, 0xea, 0xec, 0xed,
    0xef, 0xef, 0xf0, 0xf1, 0xf6, 0xf7, 0xf8, 0xf9, 0xf9, 0xfb, 0xfb, 0xfb,
    0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xa7, 0x5c, 0x18, 0x53, 0x00, 0x00, 0x02, 0x1a, 0x49, 0x44, 0x41,
    0x54, 0x38, 0x4f, 0x75, 0xd2, 0xf9, 0x5b, 0x4c, 0x51, 0x18, 0x07, 0xf0,
    0x83, 0x92, 0x7d, 0x27, 0x4a, 0x52, 0x76, 0x22, 0x6b, 0xb6, 0x42, 0x28,
    0xfb, 0xbe, 0x65, 0x5f, 0xb2, 0xef, 0x2d, 0x84, 0xca, 0x56, 0x38, 0xd3,
    0x36, 0x39, 0x97, 0x21, 0xc2, 0xd4, 0x84, 0x19, 0x1c, 0x14, 0x4d, 0x0a,
    0x65, 0xdf, 0x8f, 0x25, 0xe1, 0xfc, 0x39, 0xce, 0x7b, 0xce, 0xdc, 0x99,
    0x3b, 0xcf, 0xd3, 0xfd, 0xfe, 0x30, 0xcf, 0x7d, 0xe6, 0xfb, 0x99, 0x3b,
    0xe7, 0x7d, 0xef, 0x45, 0xc8, 0x98, 0x18, 0xce, 0x19, 0x5b, 0x88, 0x4c,
    0xd3, 0x3b, 0x1d, 0xc0, 0x8f, 0x11, 0xa6, 0x60, 0x19, 0x07, 0xc0, 0x0e,
    0x9b, 0xf5, 0xc1, 0x5c, 0x01, 0x36, 0xcc, 0x04, 0xc4, 0xe8, 0xc0, 0xec,
    0x14, 0xe3, 0x75, 0x30, 0xdb, 0x04, 0x44, 0xe9, 0x60, 0x92, 0x09, 0xe8,
    0x70, 0x82, 0xff, 0xfb, 0xf3, 0xf9, 0x1b, 0xfb, 0xde, 0xad, 0xf9, 0xbe,
    0xc5, 0xf0, 0x83, 0xaf, 0x6a, 0xdd, 0x94, 0x3e, 0xcb, 0x99, 0xd8, 0xb2,
    0x99, 0x3a, 0x70, 0xda, 0x6e, 0x37, 0x84, 0x42, 0xb2, 0x57, 0x07, 0xf8,
    0xb7, 0xfd, 0x17, 0x6c, 0x3d, 0x47, 0x6c, 0x55, 0x3a, 0x28, 0xcf, 0xc3,
    0xb9, 0x5b, 0xe6, 0x87, 0x7b, 0xeb, 0xa0, 0xb8, 0x0b, 0xbc, 0xe9, 0x85,
    0x43, 0x09, 0xd5, 0x5b, 0x1f, 0x7d, 0x62, 0xe7, 0x63, 0x5b, 0xab, 0x3e,
    0x74, 0x87, 0x38, 0xfc, 0x7b, 0x77, 0xb5, 0x12, 0xaa, 0xa7, 0xf4, 0xa5,
    0x98, 0x66, 0x7b, 0x08, 0xf4, 0x6d, 0x93, 0x45, 0xdf, 0x28, 0x7e, 0x0b,
    0xc2, 0xe1, 0xb0, 0x5a, 0x65, 0x4f, 0xe9, 0x3b, 0x21, 0xb6, 0xb5, 0x11,
    0x20, 0x11, 0xa6, 0xff, 0x09, 0x7f, 0x5f, 0x7d, 0x9d, 0x10, 0x82, 0x31,
    0x2e, 0x90, 0x07, 0x7d, 0x0d, 0x1b, 0x49, 0x40, 0x68, 0x08, 0xf4, 0xfc,
    0x03, 0x80, 0x2a, 0xa2, 0x3d, 0x78, 0x78, 0xad, 0x04, 0xe3, 0x72, 0x00,
    0xf5, 0x00, 0xd8, 0x60, 0x34, 0x55, 0x82, 0x37, 0x00, 0x6e, 0x91, 0xbb,
    0x70, 0x06, 0x0d, 0x17, 0x02, 0xa8, 0x93, 0x60, 0x0a, 0x5a, 0x27, 0xc1,
    0x59, 0x97, 0xcb, 0x75, 0x87, 0x5c, 0x7d, 0x02, 0xe0, 0x5e, 0x1e, 0xbe,
    0x78, 0x45, 0x44, 0x82, 0xb5, 0x28, 0xf3, 0xf4, 0x86, 0xf8, 0x71, 0x3d,
    0xcf, 0x10, 0x88, 0x53, 0x8d, 0x79, 0x19, 0x43, 0x2c, 0x3d, 0xc6, 0xce,
    0x58, 0x7f, 0xea, 0x38, 0x1a, 0xd0, 0x1e, 0x46, 0xd9, 0xeb, 0x74, 0x3a,
    0x6f, 0x93, 0x92, 0xa7, 0x00, 0xee, 0xe7, 0xe3, 0x62, 0x4d, 0xd3, 0xb2,
    0xe0, 0xfb, 0x76, 0x91, 0x9e, 0x5d, 0xcd, 0x84, 0x33, 0xdc, 0x80, 0x5b,
    0x50, 0x6a, 0x53, 0x63, 0x6c, 0x46, 0xc6, 0x8c, 0x56, 0x53, 0x5c, 0x7a,
    0x5c, 0x79, 0xb3, 0xd4, 0x82, 0xed, 0x00, 0xa6, 0xfb, 0x81, 0xae, 0xf2,
    0x41, 0x95, 0x1a, 0xf7, 0xd0, 0xd7, 0x0f, 0xa0, 0xa5, 0xa2, 0xaf, 0x20,
    0xb6, 0xb2, 0xb2, 0xa2, 0x22, 0x0b, 0x2e, 0x16, 0xfd, 0x01, 0xff, 0x3e,
    0x2c, 0xa9, 0x16, 0x7a, 0xf9, 0x2c, 0xec, 0x52, 0xac, 0xe9, 0x63, 0xec,
    0xa3, 0xd2, 0xf8, 0x97, 0x0a, 0xef, 0xd3, 0x04, 0xd1, 0xc0, 0x52, 0x23,
    0x7c, 0x7d, 0xf7, 0x34, 0xce, 0x7f, 0x3f, 0xf7, 0xbd, 0x0f, 0x76, 0x4b,
    0xfe, 0x47, 0xc6, 0x0e, 0x75, 0xf1, 0x82, 0xc5, 0xb0, 0xcc, 0x5f, 0x27,
    0x7d, 0x6f, 0x54, 0xcd, 0x5b, 0xd8, 0xe2, 0x2c, 0xbd, 0x0f, 0xca, 0x90,
    0xeb, 0xfe, 0xbb, 0x4f, 0x07, 0x47, 0xbe, 0xca, 0x35, 0xa7, 0xb4, 0xf2,
    0x80, 0x41, 0x5c, 0x65, 0xf9, 0xc8, 0x39, 0x3b, 0xdd, 0xf4, 0xd8, 0xae,
    0xc9, 0x2b, 0x98, 0x4a, 0x3f, 0x0f, 0x98, 0xa0, 0xfa, 0x45, 0x1d, 0xc5,
    0x75, 0xa7, 0x5e, 0xe2, 0xa3, 0xf3, 0x12, 0x05, 0xc6, 0x78, 0x40, 0xf4,
    0xaa, 0xfd, 0x19, 0x1b, 0xe7, 0x0e, 0x44, 0x86, 0x0c, 0x9d, 0xb7, 0xe9,
    0xe8, 0x9e, 0x95, 0xa3, 0xc4, 0xd5, 0x7f, 0xbc, 0x59, 0x87, 0x09, 0x1b,
    0x60, 0xeb, 0xd2, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae,
    0x42, 0x60, 0x82
  };

namespace taruga
{
//!
//! \brief The Icon enum lets the user decide between the built-in icons, Turtle and (TODO) Arrow
//!
enum class Icon : bool {
    Turtle,
    Arrow,
};

typedef uint8_t u8;


//!
//! \brief The Verbosity enum defines the different options for console output verbosity
//!
enum class Verbosity : uint8_t {
    Quiet       = 1,
    Verbose     = 2,
    VeryVerbose = 3,
};

//!
//! \brief The Instruction enum
//!
enum class Instruction : uint8_t {
    Rotate,                   //! Rotates the turtle by a given amount of degrees
    Walk,                     //! Walks forwards (or backwards) by the given amount of units.
    PenMovement,              //! Puts the pen up or down.
    LineChangeColor,          //! Change the line color to something else
    PopState,                 //! Returns the turtle state to that of the top of the state stack
    PushState,                //! Saves the current turtle state to the state stack
    Screenshot,               //! Screenshot of the current
    NewWalkingSpeed,          //! Sets a new walking speed
    NewRotationSpeed,         //! Sets a new rotation speed
    //SpriteChangeColor,        //! Change the icon color to something else
    // Stamp,           //! Permanently stamp the sprite at the current position and rotation
};

//!
//! \brief The State struct is used when saving (or loading) the turtle state to (or from) the state stack
//!
struct State {
    float x, y;
    float angle;
    bool  pen_state;        //! True if the pen is down, false if the pen is up
    sf::Color line_color;
    State(float _x, float _y, float _angle, bool _pen_state, sf::Color _color) : x(_x), y(_y), angle(_angle), pen_state(_pen_state), line_color(_color) {}
};

//!
//! \brief The Action struct represents a Taruga action, e.g. walking forward, turning right, etc.
//!
struct Action {
    union Data {
        float  new_rotation_speed;     //! Used when setting a new rotation speed
        float  new_walking_speed;      //! Used when setting a new walking speed
        float  walking_distance;       //! Used when setting walking forward or backwards
        float  rotation_angle;         //! Used when rotating
        //sf::Vector2u next_pos;       //! Used for teleports (sets the turtle directly in next_pos)
        uint8_t next_color[3];         //! Used when changing icon color. Using an array here because sf::Color has non-trivial default constructor.
        bool pen_down;                 //! Used when setting the pen up or down.
        const char * filename;
    };

    Instruction instr;
    Data  data;
    Action(Instruction m_instr, const Data& m_data) : instr(m_instr), data(m_data) {};
};

//!
//! brief The Line struct holds the starting and ending point of a line.
//!
struct Line
{
    //! (xi, yi) is the initial point
    //! (xf, yf) is the destination point
    float xi, yi, xf, yf;
    sf::Color color;
    Line(float _xi, float _yi) : xi(_xi), yi(_yi) {};
    Line(float _xi, float _yi, float _xf, float _yf, sf::Color c) : xi(_xi), yi(_yi), xf(_xf), yf(_yf), color(c) {};
    Line(float _xi, float _yi, sf::Color c) : xi(_xi), yi(_yi), color(c) {};
};

class Turtle{
private:
    static constexpr double deg_to_rad = 3.14159265358979323846/180.0;
    void init();                         //! Initializes the variables with their default values
    std::vector<Line>  lines;            //! All lines to be drawn.
    sf::ContextSettings settings;        //! Window's settings
    sf::RenderWindow   window;           //! Window where the scene will be rendered
    std::string        title;            //! The window's title
    std::queue<Action> actions;          //! The queue of actions that the turtle is going to do.
    std::stack<State>  states;           //! The stack of turtle states. Used with pop_state() and push_state().
    sf::Texture        texture;          //! The image to be used on the sprite. Kept in VRAM.
    sf::Sprite         sprite;           //! The turtle's sprite.
    sf::Color          line_color;       //! The current color of the line the turtle draws
    sf::Event          event;            //! Checks for window events
    bool               _pen_down;        //! If the pen is up, the turtle will not draw while walking around
    float              walk_spd;         //! Turtle's current velocity
    float              angle;            //! Turtle's current heading angle in [0, 360)
    float              rot_vel;          //! Turtle's rotational velocity
    uint16_t           width;            //! Rendering window width
    uint16_t           height;           //! Rendering window height
    float              x, y;             //! Current positions

    void               _pop_state();     //! Internal logic to pop the state stack and return to a previous state
    void               _push_state();    //! Internal logic to push the state stack in order to save the current state
    void               _save_to_image(const char *);  //! Save a screenshot
    void               _move_pen(bool);  //! Sets the pen up or down
    void               _draw_line(Line); //! Draws the given line
    void               _draw_sprite();   //! Draws the sprite into the window
    void               _idle();          //! Keeps rendering a static scene. Runs when there are no more actions to do.
    void               _walk(float);     //! Internal logic for walking forward in the current heading angle
    void               _rotate(float);   //! Internal logic for rotating by a given amount of degrees
    void               _draw_all_lines(bool clear_screen = true); //! Draws all saved lines
public:

    Verbosity          verbosity;        //! Toggles the verbosity level (Quiet, Verbose or VeryVerbose).
    void set_window_title(const char* new_title);
    Turtle()                               : width(800),  height(600)  { init(); }
    Turtle(uint16_t _wth, uint16_t _hgt)   : width(_wth), height(_hgt) { init(); }
    explicit Turtle(const sf::Vector2f& p) : width(p.x),  height(p.y)  { init(); }
    void save_to_image(const char *);  //! Saves the current window view to an image with the given filename
    void set_line_color(sf::Color);    //! Sets the new color of the line the turtle will draw.
    void set_line_color(u8, u8, u8);   //! Sets the new color of the line the turtle will draw.
    void set_line_color(u8[3]);        //! Sets the new color of the line the turtle will draw.
    void pen_up();                     //! Sets the pen up so lines don't get drawn
    void pen_down();                   //! Sets the pen down so that the turtle draws a line wherever it walks
    void set_icon(Icon);               //! Allows to switch around between the two built-in icons: turtle or straight arrow.
    void set_icon(sf::Texture);        //! Allows for any image to be used as an icon. Do notice that Taruga won't scale the texture. If needed, use the Turtle::scale method.
    void go_to(float x, float y);      //! Transports the turtle to a new point (line not drawn)
    void go_to(const sf::Vector2f);    //! Transports the turtle to a new point (line not drawn)
    void scale(float, float);          //! Scales the turtle sprite
    void forward(float units);         //! Walk forward the given amount of units.
    void backwards(float units);       //! Walk backwards the given amount of units. The same as using forward() with a negative parameter.
    void turn_right(float ang);        //! Turns right by the specified amount of degrees.
    void set_walking_speed(float);     //! Sets a new walking speed
    void set_rotation_speed(float);    //! Sets a new rotation speed
    void push_state();                 //! Saves the current state in a stack
    void pop_state();                  //! Returns the Turtle's state to the top of the state stack
    void turn_left(float ang);         //! Turns left by the specified amount of degrees.
    void act();                        //! Start moving the turtle. Will deplete the actions queue.
    std::queue<Action> get_queue();    //! Returns a copy of the action queue. Used by the interpreter
};

std::queue<Action> Turtle::get_queue()
{
    return actions;
}

void Turtle::set_walking_speed(float new_speed)
{
    Action::Data data; data.new_walking_speed = new_speed;
    actions.push(Action(Instruction::NewWalkingSpeed, data));
}

void Turtle::set_rotation_speed(float new_speed)
{
    Action::Data data; data.new_rotation_speed = new_speed;
    actions.push(Action(Instruction::NewRotationSpeed, data));
}

void Turtle::_pop_state()
{
    if(states.empty())
    {
        if(verbosity >= Verbosity::Verbose)
        {
            fprintf(stderr, "pop_state() called with an empty state stack.\n");
        }
    }
    const State backup_state = states.top();
    this->x          = backup_state.x;
    this->y          = backup_state.y;
    this->angle      = backup_state.angle;
    this->_pen_down  = backup_state.pen_state;
    this->line_color = backup_state.line_color;
    sprite.setRotation(backup_state.angle);
    sprite.setPosition(x, y);
    _draw_sprite();
    states.pop();
}

void Turtle::_push_state()
{
    State backup_state(x, y, angle, _pen_down, line_color);
    states.push(backup_state);
}

void Turtle::pop_state()
{
    Action::Data data;    //! We don't really have any data to use here
    actions.push(Action(Instruction::PopState, data));
}

void Turtle::push_state()
{
    Action::Data data;
    actions.push(Action(Instruction::PushState, data));
}

void Turtle::save_to_image(const char * _filename)
{
    Action::Data data; data.filename = _filename;
    actions.push(Action(Instruction::Screenshot, data));
}

void Turtle::_save_to_image(const char * filename)
{
    _draw_all_lines();
    _draw_sprite();
    sf::Vector2u window_size = window.getSize();
    sf::Texture  window_texture;
    window_texture.create(window_size.x, window_size.y);
    window_texture.update(window);
    sf::Image screenshot = window_texture.copyToImage();
    screenshot.saveToFile(filename);
}


void Turtle::_move_pen(bool m_pen_down)
{
    Action::Data data; data.pen_down = m_pen_down;
    actions.push(Action(Instruction::PenMovement, data));
}

void Turtle::pen_up()
{
    this->_move_pen(false);
}

void Turtle::pen_down()
{
    this->_move_pen(true);
}

void Turtle::set_line_color(sf::Color color)
{
    this->set_line_color(color.r, color.g, color.b);
}

void Turtle::set_line_color(u8 r, u8 g, u8 b)
{
    Action::Data data;
    data.next_color[0] = r; data.next_color[1] = g; data.next_color[2] = b;
    actions.push(Action(Instruction::LineChangeColor, data));
}

void Turtle::set_line_color(u8 color[3])
{
    this->set_line_color(color[0], color[1], color[2]);
}

void Turtle::turn_left(float deg)
{
    this->turn_right(-deg);
}

void Turtle::turn_right(float deg)
{
    deg -= deg >= 360.0 ? 360. : 0.; //! Likewise, we must decrease the angle if it's too big
    Action::Data data; data.rotation_angle = deg;
    actions.push(Action(Instruction::Rotate, data));
}

void Turtle::forward(float units)
{
    Action::Data data; data.walking_distance = units;
    actions.push(Action(Instruction::Walk, data));
}

void Turtle::backwards(float units)
{
    this->forward(-units);
}

void Turtle::_draw_all_lines(bool clear_screen)
{
    if (clear_screen)
    {
        window.clear(sf::Color::White);
    }
    for (auto line : lines)
    {
        sf::Vertex line_vertices[2] = {
            sf::Vertex(sf::Vector2f(line.xi, line.yi)),
            sf::Vertex(sf::Vector2f(line.xf, line.yf))
        };
        line_vertices[0].color = line.color;
        line_vertices[1].color = line.color;
        window.draw(line_vertices, 2, sf::Lines);
    }
}

void Turtle::_draw_line(Line new_line)
{
    _draw_all_lines();

    if (_pen_down)
    {
        sf::Vertex line_vertices[2] = {
            sf::Vertex(sf::Vector2f(new_line.xi, new_line.yi)),
            sf::Vertex(sf::Vector2f(new_line.xf, new_line.yf))
        };

        line_vertices[0].color = new_line.color;
        line_vertices[1].color = new_line.color;

        window.draw(line_vertices, 2, sf::Lines);
    }
}

void Turtle::_draw_sprite()
{
    _draw_all_lines();
    window.draw(sprite);
    window.display();
}

//!
//! \brief Turtle::_rotate is the internal function that rotates the sprite.
//!
void Turtle::_rotate(float deg)
{
    if(verbosity >= Verbosity::Verbose)
    {
        fprintf(stderr, "Turtle::_rotate(%.2f) started. Current angle: %.2f.\n", deg, this->angle);
    }

    sprite.setOrigin(16, 16);
    //! At the end of the procedure, the final angle must be equal to `obj`.
    const float obj = this->angle + deg;
    if (deg > 0)
    {
        for (; this->angle < obj; this->angle+=this->rot_vel)
        {
            sprite.setRotation(this->angle);
            this->_draw_sprite();
        }
    } else {
        for (; this->angle > obj; this->angle-=this->rot_vel)
        {
            sprite.setRotation(this->angle);
            this->_draw_sprite();
        }
    }

    //! The angles need to be in the [0, 360) range
    //! If the angle is negative, we make it positive again
    this->angle += this->angle < 0      ? 360. : 0.;
    //! Likewise, we must decrease the angle if it's too big
    this->angle -= this->angle >= 360.0 ? 360. : 0.;

    if(verbosity == Verbosity::VeryVerbose)
    {
        fprintf(stderr, "Turtle::_rotate(%.2f) finished. Current angle: %.2f. Current pos.: (%0.2f, %0.2f)\n", deg, this->angle, this->x, this->y);
    }
}


//!
//! \brief Turtle::_walk is the internal function that animates the walking of the turtle.
//! Note: This function does not draw a straight line during its mid-steps (but arrives where it needs to arrive in the end) and that is an intentional choice.
//! If you'd like to make your turtle move straight in the direction it needs to go, update the midsteps with the same calculation used on `ep`.
//!
void Turtle::_walk(float distance)
{
    if (verbosity >= Verbosity::Verbose)
    {
        fprintf(stderr, "Turtle::_walk(%.2f) started. Current pos: (%0.2f, %0.2f). Current angle: %f\n", distance, this->x, this->y, angle);
    }

    //! Converts the current angle to radians
    const float ang_rad = angle*deg_to_rad;

    //! ep := the final point
    const sf::Vector2f ep (x + sin(ang_rad) * distance, y - cos(ang_rad) * distance);

    float x_spd = 0., y_spd = 0.f;   //! The speed in which the turtle will walk in the x and y direction
    int   x_iters = 0, y_iters = 0;  //! How many times we'll update each coordinate

    if (x > ep.x)
    {
        x_spd = -walk_spd;           //! Our end-point has a smaller x-coord, so we have to decrease it.
    } else if (x < ep.x) {
        x_spd = walk_spd;            //! Our end-point has a greater x-coord, so we have to decrease it.
    }                                //! if x == ep.x, the default of 0.0f will keep them equal

    x_iters = std::abs((x - ep.x)/walk_spd);   //! Approximately how many times we'll have to update the x-coord.

    //! The same logic applies to the y-coordinate
    if (y > ep.y)
    {
        y_spd = -walk_spd;
    } else if (y < ep.y)
    {
        y_spd = walk_spd;
    }

    y_iters = std::abs((y - ep.y)/walk_spd); //! Approximately how many times we'll have to update the y-coord.

    Line line(x, y, this->line_color);

    //! As cited before, this will make the turtle walked in a "crooked" way, but at the end, his position and the line drawn will be correct.
    //! I prefer this as, in most cases, the movement done by the turtle looks similar to that of the threading of a needle, which I think is aesthetically pleasing.
    while((x_iters >= 0) || (y_iters >= 0))
    {
        if (x_iters-- >= 0) { x += x_spd; }
        if (y_iters-- >= 0) { y += y_spd; }
        line.xf = x; line.yf = y;
        sprite.setPosition(x, y);
        _draw_line(line);
        window.draw(sprite);
        window.display();
    }

    //! The loop above may only get us close to the correct end-point, so we'll guarantee that we're getting there correctly now.
    sprite.setPosition(ep);
    line.xf = x = ep.x;
    line.yf = y = ep.y;
    _draw_sprite();

    if (_pen_down)
    {
        //! We only need to save this line if the pen was down
        lines.push_back(line);
    }

    if(verbosity == Verbosity::VeryVerbose){
        fprintf(stderr, "Turtle::_walk(%.2f) finished. Current pos: (%.2f, %.2f).\n", distance, this->x, this->y);
    }
}

//!
//! \brief Turtle::init initializes Turtle variables
//!
void Turtle::init()
{
    this->verbosity  = Verbosity::Quiet;
    this->x          = width/2;
    this->y          = height/2;
    this->rot_vel    = 0.5;
    this->_pen_down  = true;
    this->walk_spd   = 0.25;
    this->angle      = 0;
    this->line_color = sf::Color::Black;
}

//!
//! \brief Turtle::_idle keeps rendering a static scene
//!
void Turtle::_idle()
{
    //! TODO: check for window events here
    for (;;) { _draw_all_lines(); window.draw(sprite); window.display(); }
}

void Turtle::set_window_title(const char * new_title)
{
    this->window.setTitle(new_title);
}

void Turtle::set_icon(sf::Texture t)
{
    //! TODO: check lifetime
    texture = t;
    sprite.setTexture(t);
}

void Turtle::set_icon(Icon icon)
{
    if (icon == Icon::Arrow)
    {
        //! TODO
    } else {
        texture.loadFromMemory(__turtle_png, 1479);
    }

    sprite.setTexture(texture);
}


//!
//! \brief Turtle::act runs through the action queue and animates the turtle
//!
void Turtle::act()
{
    window.setFramerateLimit(60);
    if (title.empty())
    {
        title = "Ruga Window";
    }
    if (sprite.getTexture() == nullptr)
    {
        //! Icon not set, default to turtle.
        set_icon(Icon::Turtle);
    }

    if(verbosity >= Verbosity::Verbose)
    {
        fprintf(stderr, "\nStarting act() with actions.size() = %lu\n", (unsigned long) actions.size());
    }

    sprite.setPosition(x, y);
    
    settings.antialiasingLevel = 8;

    window.create(sf::VideoMode(width, height), title, sf::Style::Default, settings);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }
        }

        //! If there are no more actions to do, idle until user closes the window
        if(actions.empty()) { _idle(); } //! TODO: check events within _idle

        Action &current = actions.front();

        switch (current.instr)
        {
        case Instruction::Rotate:
            _rotate(current.data.rotation_angle);
            break;
        case Instruction::Walk:
            _walk(current.data.walking_distance);
            break;
        case Instruction::PenMovement:
            _pen_down = current.data.pen_down;
            break;
        case Instruction::Screenshot:
            _save_to_image(current.data.filename);
            break;
        case Instruction::PopState:
            this->_pop_state();
            break;
        case Instruction::PushState:
            this->_push_state();
            break;
        case Instruction::NewWalkingSpeed:
            this->walk_spd = current.data.new_walking_speed;
            break;
        case Instruction::NewRotationSpeed:
            this->rot_vel = current.data.new_rotation_speed;
            break;
        case Instruction::LineChangeColor:
            const auto newc = current.data.next_color;
            this->line_color = sf::Color(newc[0], newc[1], newc[2]);
            break;
        }
         actions.pop();
    }
}

}   //! <- This brace closes the namespace

#endif
