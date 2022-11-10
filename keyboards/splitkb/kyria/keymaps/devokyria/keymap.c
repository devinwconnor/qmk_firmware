/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _COLEMAK = 0,
    _NAV,
    _MEDIA,
    _NUM,
    _SYMBOLS,
    _FUNC
};


// Aliases for readability
// #define QWERTY   DF(_QWERTY)
// #define COLEMAK  DF(_COLEMAK_DH)
// #define DVORAK   DF(_DVORAK)

// #define SYM      MO(_SYM)
// #define NAV      MO(_NAV)
// #define FKEYS    MO(_FUNCTION)
// #define ADJUST   MO(_ADJUST)

// #define CTL_ESC  MT(MOD_LCTL, KC_ESC)
// #define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
// #define CTL_MINS MT(MOD_RCTL, KC_MINUS)
// #define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Home Row Mods
#define HRM_R MT(MOD_LALT,KC_R)
#define HRM_S MT(MOD_LGUI,KC_S)
#define HRM_T MT(MOD_LSFT,KC_T)
#define HRM_D MT(MOD_LCTL,KC_D)

#define HRM_N MT(MOD_LSFT,KC_N)
#define HRM_E MT(MOD_LGUI,KC_E)
#define HRM_I MT(MOD_LALT,KC_I)
#define HRM_H MT(MOD_LCTL,KC_H)

//Layer Toggles
#define LS_SPC  LT(_NAV,KC_SPC)
#define LS_TAB  LT(_MEDIA,KC_TAB)
#define LS_BSPC LT(_NUM,KC_BSPC)
#define LS_ENT  LT(_SYMBOLS,KC_ENT)
#define LS_DEL  LT(_FUNC,KC_DEL) 

//MAC desktop movement
#define DM_UP    LCTL(KC_UP)
#define DM_LEFT  LCTL(KC_LEFT)
#define DM_RIGHT LCTL(KC_RIGHT)

//Editing
#define FIND  LGUI(KC_F)
#define SAVE  LGUI(KC_S)
#define COPY  LGUI(KC_C)
#define CUT   LGUI(KC_X)
#define PASTE LGUI(KC_V)
#define UNDO  LGUI(KC_Z)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                            ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_NO,    KC_Q,   KC_W,     KC_F,    KC_P,    KC_B,                                                 KC_J,    KC_L,    KC_U,    KC_Y,  KC_QUOT,  KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                                            ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,    KC_A,   HRM_R,    HRM_S,  HRM_T,    KC_G,                                                 KC_M,   HRM_N,   HRM_E,   HRM_I,    KC_O,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐        ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,    KC_Z,    KC_X,    KC_C,   HRM_D,    KC_V,   KC_NO,   KC_ESC,           LS_DEL,  KC_NO,    KC_K,   HRM_H,   KC_COMM, KC_DOT, KC_SLSH,  KC_NO,
    //└────────┴────────┴────────┼────────┼────────┼────────┼        ┼────────┼        ┼────────┼        ┼────────┼────────┼────────┼────────┴────────┘────────┘
                                   DM_UP,  DM_LEFT, DM_RIGHT, LS_SPC,  LS_TAB,           LS_ENT, LS_BSPC,  KC_NO,    KC_NO,  KC_NO
    //                           └────────└────────┴────────┴────────┴────────┘        └────────└────────┴────────┴────────┴────────┘
),

    [_NAV] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                            ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_NO,    SAVE,   KC_ENT,   KC_UP,   COPY,     PASTE,                                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                                            ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,    FIND,  KC_LEFT, KC_DOWN, KC_RGHT,  CUT,                                                  KC_NO,  KC_LSFT, KC_LGUI, KC_LALT,  KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐        ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,   KC_NO,   KC_HOME,  UNDO,  KC_END,   KC_ENT,  KC_NO,  KC_TRNS,          KC_TRNS,  KC_NO,   KC_NO,  KC_LCTL,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //└────────┴────────┴────────┼────────┼────────┼────────┼        ┼────────┼        ┼────────┼        ┼────────┼────────┼────────┼────────┴────────┘────────┘
                                   DM_UP,  DM_LEFT, DM_RIGHT,KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,  KC_NO,    KC_NO,  KC_NO
    //                           └────────└────────┴────────┴────────┴────────┘        └────────└────────┴────────┴────────┴────────┘
),

    [_MEDIA] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                            ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,                                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                                            ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,   KC_NO,  KC_LALT, KC_LGUI, KC_LSFT,  KC_NO,                                                KC_NO,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,  KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐        ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,    KC_NO,   KC_NO, KC_LCTL,  KC_NO,  KC_LGUI,  KC_NO,   KC_TRNS,          KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //└────────┴────────┴────────┼────────┼────────┼────────┼        ┼────────┼        ┼────────┼        ┼────────┼────────┼────────┼────────┴────────┘────────┘
                                   KC_NO,   KC_NO,   KC_NO,  KC_TRNS,  KC_TRNS,          KC_NO,  KC_MPLY,  KC_NO,   KC_NO,   KC_NO
    //                           └────────└────────┴────────┴────────┴────────┘        └────────└────────┴────────┴────────┴────────┘
),

    [_NUM] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                            ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_NO,   KC_GRV,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,                                               KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                                            ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,   KC_SCLN, KC_P4,   KC_P5,   KC_P6,   KC_PAST,                                               KC_NO, KC_LSFT,  KC_LGUI, KC_LALT,  KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐        ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,   KC_GRV,  KC_P1,   KC_P2,   KC_P3,  KC_PSLS,  KC_NO,   KC_EQL,          KC_TRNS,  KC_NO,   KC_NO,  KC_LCTL,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //└────────┴────────┴────────┼────────┼────────┼────────┼        ┼────────┼        ┼────────┼        ┼────────┼────────┼────────┼────────┴────────┘────────┘
                                  KC_LCBR, KC_LBRC, KC_LPRN, KC_P0,   KC_MINUS,         KC_TRNS, KC_TRNS,  KC_NO,    KC_NO,  KC_NO
    //                           └────────└────────┴────────┴────────┴────────┘        └────────└────────┴────────┴────────┴────────┘
),

    [_SYMBOLS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                            ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_NO,   KC_LCBR, KC_AMPR, KC_ASTR, KC_RPRN, KC_RCBR,                                               KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                                            ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,   KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_RPRN,                                                KC_NO, KC_LSFT, KC_LGUI, KC_LALT,  KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐        ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,   KC_TILD, KC_EXLM,  KC_AT, KC_HASH, KC_RBRC,  KC_NO,  KC_TRNS,          KC_TRNS,  KC_NO,   KC_NO,   KC_LCTL,  KC_NO,  KC_NO,   KC_NO,    KC_NO,
    //└────────┴────────┴────────┼────────┼────────┼────────┼        ┼────────┼        ┼────────┼        ┼────────┼────────┼────────┼────────┴────────┘────────┘
                                  KC_RCBR, KC_RBRC, KC_RPRN, KC_P0,  KC_MINUS,          KC_TRNS, KC_TRNS,  KC_NO,    KC_NO,  KC_NO
    //                           └────────└────────┴────────┴────────┴────────┘        └────────└────────┴────────┴────────┴────────┘
),

    [_FUNC] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                            ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_NO,   KC_F12,  KC_F7,    KC_F8,   KC_F9,   KC_NO,                                                KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                                            ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,  KC_F11,   KC_F4,    KC_F5,   KC_F6,   KC_NO,                                                KC_NO, KC_LSFT, KC_LGUI, KC_LALT,  KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐        ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,   KC_F10,  KC_F1,    KC_F2,  KC_F3,    KC_NO,  KC_NO,  KC_TRNS,          KC_TRNS,  KC_NO,   KC_NO,   KC_LCTL,  KC_NO,  KC_NO,   KC_NO,    KC_NO,
    //└────────┴────────┴────────┼────────┼────────┼────────┼        ┼────────┼        ┼────────┼        ┼────────┼────────┼────────┼────────┴────────┘────────┘
                                  KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,  KC_NO,    KC_NO,  KC_NO
    //                           └────────└────────┴────────┴────────┴────────┘        └────────└────────┴────────┴────────┴────────┘
)
}; 

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//   }
//   return true;
// }

