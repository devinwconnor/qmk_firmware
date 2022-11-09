#include QMK_KEYBOARD_H


// #define _COLEMAK 0
// #define _GAMES 1
// #define _NAV 2
// #define _MEDIA 3
// #define _NUM 4
// #define _SYMBOLS 5
// #define _FUNC 6


enum custom_layers {
  _COLEMAK,
  _GAMES,
  _GW2,
  _MAPGAMES,
  _NAV,
  _MEDIA,
  _NUM,
  _SYMBOLS,
  _FUNC
};

enum custom_keycodes {
  COPY = SAFE_RANGE,
  CUT,
  PASTE,
  UNDO,
  FIND,
  SAVE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    TG(_GAMES),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,   KC_7,     KC_8,    KC_9,    KC_0,  TG(_MAPGAMES),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,     KC_A,   MT(MOD_LALT,KC_R),  MT(MOD_LCTL,KC_S),MT(MOD_LSFT,KC_T), KC_G, KC_M, MT(MOD_LSFT,KC_N), MT(MOD_LCTL,KC_E), MT(MOD_LALT,KC_I), KC_O, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,    KC_Z,    KC_X,    KC_C,  MT(MOD_LGUI,KC_D),  KC_V,    KC_ESC, TG(_GW2),  KC_K, MT(MOD_LGUI,KC_H),   KC_COMM,  KC_DOT,  KC_SLSH, KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                         KC_ESC,   LT(_NAV,KC_SPC), LT(_MEDIA,KC_TAB),      LT(_SYMBOLS,KC_ENT), LT(_NUM,KC_BSPC), LT(_FUNC,KC_DEL)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMES] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TG(_GAMES), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,     KC_7,    KC_8,    KC_9,    KC_0,   TG(_MAPGAMES),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_M,     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_U,     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                               KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_I,    KC_LCTL,  KC_X,    KC_C,    KC_V,    KC_B,   KC_ESC,           KC_LALT,  KC_N,     KC_M,   KC_COMM,  KC_DOT, KC_SLSH, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_T,  KC_SPC,  KC_G,                        KC_ENT,  KC_BSPC, KC_DEL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MAPGAMES] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TG(_GAMES), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,     KC_7,    KC_8,    KC_9,    KC_0,   TG(_MAPGAMES),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_C,     KC_TAB,  KC_Q,    KC_UP,    KC_E,    KC_R,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_U,     KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT,  KC_F,                               KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_I,    KC_LCTL,  KC_X,    KC_C,    KC_V,    KC_B,   KC_ESC,          KC_TRNS, KC_N,     KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_T,  KC_SPC,  KC_G,                        KC_ENT,  KC_BSPC, KC_DEL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GW2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,     KC_7,    KC_8,    KC_9,    KC_0,   TG(_MAPGAMES),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_I,     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_M,     KC_T,    KC_A,    KC_S,    KC_D,    KC_F,                               KC_H, MT(MOD_LSFT,KC_J), MT(MOD_LCTL,KC_K), MT(MOD_LALT,KC_L), MT(MOD_LGUI,KC_SCLN), KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_U,     KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,   KC_ESC,            KC_TRNS,   KC_N,     KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_LCTL, KC_SPC,  KC_G,                   KC_TRNS,  KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,    SAVE,   KC_ENT,   KC_UP,   COPY,     PASTE,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,    FIND, KC_LEFT, KC_DOWN, KC_RGHT,  CUT,                            KC_NO,  KC_LSFT, KC_LCTL,  KC_LALT, KC_LGUI, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,     KC_NO, KC_HOME,   UNDO,  KC_END,  KC_ENT,  KC_TRNS,          KC_TRNS,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_ESC,  KC_SPC, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

   [_MEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,    KC_NO, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                               KC_NO,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LGUI,  KC_TRNS,          KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_MPLY,  KC_NO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_GRV,    KC_P7,   KC_P8,  KC_P9,  KC_PAST,                              KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_SCLN,   KC_P4,   KC_P5,   KC_P6,  KC_EQL,                             KC_NO,  KC_LSFT, KC_LCTL, KC_LALT, KC_NO,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,  KC_PSLS, KC_TRNS,          KC_TRNS, KC_NO,   KC_LGUI,    KC_NO,  KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_DOT,    KC_P0,  KC_MINUS,                  KC_TRNS, KC_TRNS,  KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_LCBR, KC_AMPR,  KC_ASTR, KC_RPRN, KC_RCBR,                            KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_LPRN,  KC_DLR,  KC_PERC, KC_CIRC, KC_RPRN,                            KC_NO,  KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_LBRC, KC_EXLM,   KC_AT,  KC_HASH, KC_RBRC,KC_TRNS,          KC_TRNS,  KC_NO,   KC_LGUI,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_FUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,  KC_F11,   KC_F4,    KC_F5,   KC_F6,  KC_NO,                              KC_NO,  KC_LSFT, KC_LCTL, KC_LALT,  KC_NO, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_F10,  KC_F1,    KC_F2,  KC_F3,   KC_NO,  KC_TRNS,          KC_TRNS,   KC_NO,   KC_LGUI,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
}; 

const rgblight_segment_t PROGMEM my_default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_OFF},       // Light 4 LEDs, starting with LED 3
    {6, 6, HSV_OFF}
);

const rgblight_segment_t PROGMEM my_games_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_RED},     
    {6, 6, HSV_RED}
);

// Light LEDs 6 to 9 and 12 to 15 red when games layer is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_gw2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_MAGENTA}, 
    {1, 1, HSV_GOLD},
    {2, 1, HSV_MAGENTA},
    {3, 1, HSV_YELLOW},
    {4, 1, HSV_MAGENTA},
    {5, 1, HSV_YELLOW},
    {6, 1, HSV_MAGENTA}, 
    {7, 1, HSV_GOLD},
    {8, 1, HSV_MAGENTA},
    {9, 1, HSV_YELLOW},
    {10, 1, HSV_MAGENTA},
    {11, 1, HSV_YELLOW}
);


const rgblight_segment_t PROGMEM my_mapgames_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_CYAN},
    {6, 6, HSV_CYAN}
);
// const rgblight_segment_t PROGMEM my_media_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {6, 6, HSV_ORANGE}
// );
// // Light LEDs 11 & 12 in purple when num layer is active
// const rgblight_segment_t PROGMEM my_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 6, HSV_CHARTREUSE}
// );
// // Light LEDs 13 & 14 in green when symbol layer is active
// const rgblight_segment_t PROGMEM my_symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 6, HSV_CORAL}
// );

// const rgblight_segment_t PROGMEM my_func_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 6, HSV_GOLD}
// );

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_default_layer,
    my_games_layer,
    my_gw2_layer,
    my_mapgames_layer
    // my_nav_layer,
    // my_media_layer,        
    // my_num_layer,    // Overrides other layers
    // my_symbol_layer,     // Overrides other layers
    // my_func_layer
);


void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _GAMES));
    rgblight_set_layer_state(2, layer_state_cmp(state, _GW2));
    rgblight_set_layer_state(3, layer_state_cmp(state, _MAPGAMES));
    // rgblight_set_layer_state(3, layer_state_cmp(state, _NAV));
    // rgblight_set_layer_state(3, layer_state_cmp(state, _MEDIA));
    // rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
    // rgblight_set_layer_state(5, layer_state_cmp(state, _SYMBOLS));
    // rgblight_set_layer_state(6, layer_state_cmp(state, _FUNC));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COPY:
        if (record->event.pressed) {
        } else {
            tap_code16(LCTL(KC_C));
        }
        return false;
    case CUT:
        if (record->event.pressed) {
        } else {
            tap_code16(LCTL(KC_X));
        }
        return false;
    case PASTE:
        if (record->event.pressed) {     
        } else {
            tap_code16(LCTL(KC_V));
        }
        return false;
    case UNDO:
        if (record->event.pressed) {     
        } else {
            tap_code16(LCTL(KC_Z));
        }
        return false;
    case FIND:
        if (record->event.pressed) {    
        } else { 
            tap_code16(LCTL(KC_F));
        }
        return false;
    case SAVE:
        if (record->event.pressed) {    
        } else { 
            tap_code16(LCTL(KC_S));
        }
        return false;
  }
  return true;
}

