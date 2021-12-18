#include QMK_KEYBOARD_H

enum ferris_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _BOTH
};

#define KC_LS_Z LSFT_T(KC_Z)
#define KC_LS_CAPS LSFT_T(KC_CAPS)
#define KC_RS_SLSH RSFT_T(KC_SLSH)
#define KC_BS_L1 LT(_LOWER, KC_BSPC)
#define KC_SP_L2 LT(_RAISE, KC_SPC)
#define KC_CTL_Q LCTL_T(KC_Q)
#define KC_CTL_TAB LCTL_T(KC_TAB)
#define KC_ALT_ENT LALT_T(KC_ENT)
#define KC_CAD C(A(KC_DEL))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_CTL_Q,   KC_W,       KC_F,       KC_P,       KC_B,           KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,
        KC_A,       KC_R,       KC_S,       KC_T,       KC_G,           KC_M,       KC_N,       KC_E,       KC_I,       KC_O,
        KC_LS_Z,    KC_X,       KC_C,       KC_D,       KC_V,           KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_RS_SLSH,
                                            KC_CTL_TAB, KC_BS_L1,       KC_SP_L2,   KC_ALT_ENT
    ),
    [_LOWER] = LAYOUT(
        KC_ESC,     KC_TILDE,   KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_QUOT,    KC_LCBR,    KC_RCBR,    KC_PIPE,
        KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,        KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,
        KC_TRNS,    KC_TRNS,    KC_UNDS,    KC_PLUS,    KC_TRNS,        KC_TRNS,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,
                                            KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS  
    ),
    [_RAISE] = LAYOUT(
        KC_DEL,     KC_GRAVE,   KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_DQT,     KC_LBRC,    KC_RBRC,    KC_BSLS,
        KC_1,       KC_2,       KC_3,       KC_4,       KC_5,           KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
        KC_LS_CAPS, KC_TRNS,    KC_MINUS,   KC_EQUAL,   KC_TRNS,        KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,
                                            KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS
    ),
    [_BOTH] = LAYOUT(
        RESET,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_F1,      KC_F2,      KC_F3,      KC_F4,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_CAD,     KC_TRNS,        KC_TRNS,    KC_F5,      KC_F6,      KC_F7,      KC_F8,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_F9,      KC_F10,     KC_F11,     KC_F12,
                                            KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS
    )
};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _BOTH);
}
