#include QMK_KEYBOARD_H

enum iris_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _BOTH
};

#define KC_LS_CAPS LSFT_T(KC_CAPS)
#define KC_RS_ENT RSFT_T(KC_ENT)
#define KC_BS_L1 LT(_LOWER, KC_BSPC)
#define KC_ENT_L2 LT(_RAISE, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
    KC_ESC,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,       KC_BSPC,
    KC_TAB,     KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                       KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,    KC_DEL,
    KC_LCTL,    KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                       KC_M,   KC_N,   KC_E,   KC_I,   KC_O,       KC_QUOT,
    KC_LS_CAPS, KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_HOME,    KC_END, KC_K,   KC_H,  KC_COMM, KC_DOT, KC_SLSH,    KC_RS_ENT,
                                       KC_LCTL,KC_BS_L1,KC_LGUI,    KC_SPC,KC_ENT_L2,KC_LALT
),
[_LOWER] = LAYOUT(
    _______,    _______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,    _______,
    _______,    _______,KC_LBRC,KC_RBRC,_______,_______,                   _______,KC_MINUS,KC_UNDS,KC_EQUAL,KC_PLUS,   _______,
    KC_TILDE,   KC_EXLM, KC_AT, KC_HASH,KC_DLR, KC_PERC,                    KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,    KC_PIPE,
    _______,    _______,_______,_______,_______,_______,_______,    _______,_______,KC_LCBR,KC_RCBR,_______,_______,    _______,
                                        _______,_______,_______,    _______,_______,_______
),
[_RAISE] = LAYOUT(
    _______,    _______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,    _______,
    KC_F1,      KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                      KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,     KC_F12,
    KC_GRAVE,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,       KC_BSLS,
    _______,    _______,_______,_______,_______,_______,KC_PGUP,    _______,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,   _______,
                                        _______,_______,KC_PGDN,    _______,_______,_______
),
[_BOTH] = LAYOUT(
    RESET,      _______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,    _______,
    _______,    _______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,    _______,
    _______,    _______,_______,_______,_______,_______,                    _______,RGB_TOG,RGB_VAI,RGB_VAD,_______,    _______,
    _______,    _______,_______,_______,_______,_______,_______,    _______,_______,RGB_MOD,RGB_HUI,RGB_HUD,_______,    _______,
                                        _______,_______,_______,    _______,_______,_______
)};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _BOTH);
}