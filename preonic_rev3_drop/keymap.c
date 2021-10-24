#include QMK_KEYBOARD_H

enum preonic_layers {
    _BASE,
    _NUMPAD,
    _LEFT,
    _RIGHT,
    _BOTH,
    _MOUSE,
    _WHEEL,
};

#define TT_NUMP TT(_NUMPAD)
#define MO_LEFT MO(_LEFT)
#define MO_RGHT MO(_RIGHT)
#define MO_BOTH MO(_BOTH)
#define MO_MOUS MO(_MOUSE)
#define MO_WHEL MO(_WHEEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Back |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |_NUMP |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Del |  Alt |_LEFT |    Space    |_RGHT |_MOUS | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_preonic_1x2uC(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    TT_NUMP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
    KC_LCTL, KC_LGUI, KC_DEL,  KC_LALT, MO_LEFT,      KC_SPC,      MO_RGHT, MO_MOUS, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |NumLk |Num / |Num * |Num - |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |Num 7 |Num 8 |Num 9 |Num + |
 * |------+------+------+------+------+------+------+------+--- --+--- --+--- --+--- --|
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |Num 4 |Num 5 |Num 6 |Num , |
 * |------+------+------+------+------+------+------+------+--- --+--- --+--- --+--- --|
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |Num 1 |Num 2 |Num 3 |Num = |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ |Num 0 |Num . |NumEn |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_1x2uC(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PCMM,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL,
    _______, _______, _______, _______, _______,      _______,     _______, _______, KC_P0,   KC_PDOT, KC_PENT
),

/* Left
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F17 |  F21 |   9  |   0  |   -  |   =  | Back |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |  F5  |  F6  |  F7  |  F8  |  F18 |  F22 |      |  Up  |   [  |   ]  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |  F9  |  F10 |  F11 |  F12 |  F19 |  F23 | Left | Down |Right |   '  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |  F13 |  F14 |  F15 |  F16 |  F20 |  F24 |      |   ,  |   .  |  Up  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ |     ____    |_BOTH | ____ | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_LEFT] = LAYOUT_preonic_1x2uC(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F17,  KC_F21,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F18,  KC_F22,  XXXXXXX, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F19,  KC_F23,  KC_LEFT, KC_DOWN, KC_RGHT, KC_QUOT, KC_ENT,
    _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F20,  KC_F24,  XXXXXXX, KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
    _______, _______, _______, _______, _______,      _______,     MO_BOTH, _______, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Right
 * ,-----------------------------------------------------------------------------------.
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |PrtSc |ScrLk |Pause | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |Insrt | Home | PgUp | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |  Del |  End | PgDn | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ |_BOTH |     ____    | ____ | ____ | ____ | ____ | ____ |
 * `-----------------------------------------------------------------------------------'
 */
[_RIGHT] = LAYOUT_preonic_1x2uC(
    _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, _______,
    _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_INS,  KC_HOME, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_DEL,  KC_END,  KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______,
    _______, _______, _______, _______, MO_BOTH,      _______,     _______, _______, _______, _______, _______
),

/* Both
 * ,-----------------------------------------------------------------------------------.
 * | ____ |      |      |      |      |Reset |      |      |      |      |      | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |      |      |      |      |      |      |      |      |      |      | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |      |      |      |      |      |      |      |      |      |      | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |      |      |      |      |      |      |      |      |      | ____ | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ |
 * `-----------------------------------------------------------------------------------'
 */
[_BOTH] = LAYOUT_preonic_1x2uC(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
    _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |      |      |      |      |      |      |      |PrtSc |ScrLk |Pause | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |      |      | M Up |      |      |MBtn4 |MBtn3 |MBtn3 | Home | PgUp | Stop |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MLeft |MDown |MRght |      |MBtn5 |MBtn1 |MBtn2 |  End | PgDn | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |_WHEL |      |MAcc2 |MAcc1 |MAcc0 |MAcc0 |MAcc1 |MAcc2 | Play | Prev | Next |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ |      |     ____    |      | ____ | Mute | Vol- | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_preonic_1x2uC(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, _______,
    _______, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN3, KC_HOME, KC_PGUP, KC_MSTP,
    XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_BTN5, KC_BTN1, KC_BTN2, KC_END,  KC_PGDN, _______,
    _______, MO_WHEL, XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, KC_ACL0, KC_ACL1, KC_ACL2, KC_MPLY, KC_MPRV, KC_MNXT,
    _______, _______, _______, _______, XXXXXXX,      _______,     XXXXXXX, _______, KC_MUTE, KC_VOLD, KC_VOLU
),

/* Mouse Wheel
 * ,-----------------------------------------------------------------------------------.
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | MWUp | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ |MWLft |MWDwn |MWRgt | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ |
 * `-----------------------------------------------------------------------------------'
 */
[_WHEEL] = LAYOUT_preonic_1x2uC(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_WH_U, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

};
