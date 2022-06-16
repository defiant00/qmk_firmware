#include QMK_KEYBOARD_H

enum ferris_layers {
    _BASE,
    _NUM,
    _SYM,
    _FN,
    _NAV
};

#define KC_A_GUI    LGUI_T(KC_A)
#define KC_R_ALT    LALT_T(KC_R)
#define KC_S_CTL    LCTL_T(KC_S)
#define KC_T_SFT    LSFT_T(KC_T)

#define KC_N_SFT    RSFT_T(KC_N)
#define KC_E_CTL    RCTL_T(KC_E)
#define KC_I_ALT    RALT_T(KC_I)
#define KC_O_GUI    RGUI_T(KC_O)

#define KC_SP_L1    LT(_NUM, KC_SPACE)
#define KC_ENT_L2   LT(_SYM, KC_ENTER)
#define KC_TAB_L3   LT(_FN, KC_TAB)
#define KC_BS_L4    LT(_NAV, KC_BACKSPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,           KC_J,       KC_L,       KC_U,       KC_Y,       KC_QUOT,
        KC_A_GUI,   KC_R_ALT,   KC_S_CTL,   KC_T_SFT,   KC_G,           KC_M,       KC_N_SFT,   KC_E_CTL,   KC_I_ALT,   KC_O_GUI,
        KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,           KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,
                                            KC_TAB_L3,  KC_BS_L4,       KC_SP_L1,   KC_ENT_L2
    ),
    [_NUM] = LAYOUT(
        KC_GRAVE,   KC_7,       KC_8,       KC_9,       KC_BSLS,        QK_BOOT,    _______,    _______,    _______,    _______,
        KC_SCLN,    KC_4,       KC_5,       KC_6,       KC_EQUAL,       _______,    KC_RSFT,    KC_RCTL,    KC_RALT,    KC_DELETE,
        KC_LBRC,    KC_1,       KC_2,       KC_3,       KC_RBRC,        _______,    _______,    _______,    _______,    _______,
                                            KC_MINUS,   KC_0,           KC_SPACE,   KC_ENTER
    ),
    [_SYM] = LAYOUT(
        KC_TILDE,   KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_PIPE,        _______,    _______,    _______,    _______,    _______,
        KC_COLON,   KC_DLR,     KC_PERC,    KC_CIRC,    KC_PLUS,        _______,    KC_RSFT,    KC_RCTL,    KC_RALT,    KC_RGUI,
        KC_LCBR,    KC_EXLM,    KC_AT,      KC_HASH,    KC_RCBR,        _______,    _______,    _______,    _______,    _______,
                                            KC_UNDS,    KC_RPRN,        KC_SPACE,   KC_ENTER
    ),
    [_FN] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,        KC_PSCR,    KC_F9,      KC_F10,     KC_F11,     KC_F12,
        KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    _______,        KC_SCRL,    KC_F5,      KC_F6,      KC_F7,      KC_F8,
        _______,    _______,    _______,    _______,    _______,        KC_PAUSE,   KC_F1,      KC_F2,      KC_F3,      KC_F4,
                                            KC_TAB,     KC_BSPC,        KC_SPACE,   KC_ENTER
    ),
    [_NAV] = LAYOUT(
        _______,    _______,    _______,    _______,    QK_BOOT,        _______,    KC_CAPS,    _______,    _______,    _______,
        KC_ESC,     KC_LALT,    KC_LCTL,    KC_LSFT,    _______,        CAPS_WORD,  KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,
        _______,    _______,    _______,    _______,    _______,        KC_INSERT,  KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,
                                            KC_TAB,     KC_BSPC,        KC_LPRN,    KC_ENTER
    )
};
