#include QMK_KEYBOARD_H

enum iris_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _BOTH
};

#define KC_LS_CAPS LSFT_T(KC_CAPS)
#define KC_LS_Z LSFT_T(KC_Z)
#define KC_RS_ENT RSFT_T(KC_ENT)
#define KC_RS_SLSH RSFT_T(KC_SLSH)
#define KC_LC_TAB LCTL_T(KC_TAB)
#define KC_BS_L1 LT(_LOWER, KC_BSPC)
#define KC_ENT_L2 LT(_RAISE, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
    KC_LGUI,    KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,                                   KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_DEL,
    KC_LC_TAB,  KC_A,       KC_R,       KC_S,       KC_T,       KC_G,                                   KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOT,
    KC_LS_CAPS, KC_LS_Z,    KC_X,       KC_C,       KC_D,       KC_V,       KC_HOME,        KC_END,     KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_RS_SLSH, KC_RS_ENT,
                                                    KC_LCTL,    KC_BS_L1,   KC_DEL,         KC_SPC,     KC_ENT_L2,  KC_LALT
),
[_LOWER] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    KC_LBRC,    KC_RBRC,    _______,    _______,                                _______,    KC_MINUS,   KC_UNDS,    KC_EQUAL,   KC_PLUS,    _______,
    KC_TILDE,   KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_PIPE,
    _______,    _______,    KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, _______,    _______,        _______,    _______,    KC_LCBR,    KC_RCBR,    _______,    _______,    _______,
                                                    _______,    _______,    _______,        _______,    _______,    _______
),
[_RAISE] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,
    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                                  KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
    KC_GRAVE,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSLS,
    _______,    _______,    _______,    _______,    _______,    _______,    KC_PGUP,        _______,    _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   _______,
                                                    _______,    _______,    KC_PGDN,        _______,    _______,    _______
),
[_BOTH] = LAYOUT(
    RESET,      _______,    _______,    _______,    _______,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                _______,    RGB_TOG,    RGB_VAI,    RGB_VAD,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,    _______,    RGB_MOD,    RGB_HUI,    RGB_HUD,    _______,    _______,
                                                    _______,    _______,    _______,        _______,    _______,    _______
)};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _BOTH);
}

// Colors (HSV)
#define _BL {0, 0, 0}
#define _FN {80, 255, 128}
#define _NUM {100, 255, 128}
#define _SYM {170, 255, 128}
#define _NAV {220, 255, 128}
#define _L1 {160, 255, 255}
#define _L2 {100, 255, 255}
#define _L3 {0, 255, 255}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = {
        _BL,    _BL,    _BL,    _BL,    _BL,    _BL,
        _BL,    _BL,    _SYM,   _SYM,   _BL,    _BL,
        _SYM,   _SYM,   _SYM,   _SYM,   _SYM,   _SYM,
        _BL,    _NAV,   _NAV,   _NAV,   _BL,    _BL,
        _BL,    _BL,    _BL,    _BL,
        _L1,    _L1,    _L1,    _L1,    _L1,    _L1,

        _BL,    _BL,    _BL,    _BL,    _BL,    _BL,
        _BL,    _SYM,   _SYM,   _SYM,   _SYM,   _BL,
        _SYM,   _SYM,   _SYM,   _SYM,   _SYM,   _SYM,
        _BL,    _SYM,   _SYM,   _BL,    _BL,    _BL,
        _BL,    _BL,    _BL,    _BL,
        _L1,    _L1,    _L1,    _L1,    _L1,    _L1,
    },
    [2] = {
        _BL,    _BL,    _BL,    _BL,    _BL,    _BL,
        _FN,    _FN,    _FN,    _FN,    _FN,    _FN,
        _SYM,   _NUM,   _NUM,   _NUM,   _NUM,   _NUM,
        _BL,    _BL,    _BL,    _BL,    _BL,    _BL,
        _BL,    _BL,    _NAV,   _NAV,
        _L2,    _L2,    _L2,    _L2,    _L2,    _L2,

        _BL,    _BL,    _BL,    _BL,    _BL,    _BL,
        _FN,    _FN,    _FN,    _FN,    _FN,    _FN,
        _SYM,   _NUM,   _NUM,   _NUM,   _NUM,   _NUM,
        _BL,    _NAV,   _NAV,   _NAV,   _NAV,   _BL,
        _BL,    _BL,    _BL,    _BL,
        _L2,    _L2,    _L2,    _L2,    _L2,    _L2,
    },
    [3] = {
    {0, 255, 255},  _BL,        _BL,        _BL,        _BL,        _BL,
        _BL,        _BL,        _BL,        _BL,        _BL,        _BL,
        _BL,        _BL,        _BL,        _BL,        _BL,        _BL,
        _BL,        _BL,        _BL,        _BL,        _BL,        _BL,
        _BL,        _BL,        _BL,        _BL,
        _L3,        _L3,        _L3,        _L3,        _L3,        _L3,

        _BL,        _BL,        _BL,        _BL,        _BL,        _BL,
        _BL,        _BL,        _BL,        _BL,        _BL,        _BL,
        _BL,        _BL,  {0, 0, 64},{0, 0, 255}, {80, 255, 255},  _BL,
        _BL,{220, 255, 255},{0, 255, 255},{160, 255, 255},_BL,      _BL,
        _BL,        _BL,        _BL,        _BL,
        _L3,        _L3,        _L3,        _L3,        _L3,        _L3,
    },
};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB rgb = hsv_to_rgb(hsv);
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

#define CAPS_LED 23

void rgb_matrix_indicators_user(void) {
    // Layer
    int layer = biton32(layer_state);
    if (layer) {
        set_layer_color(layer);
    }

    // Caps lock
    if (host_keyboard_led_state().caps_lock) {
        HSV hsv = {16, 255, 64};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(CAPS_LED, rgb.r, rgb.g, rgb.b);
    }
}