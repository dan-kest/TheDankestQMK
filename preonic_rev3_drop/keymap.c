#include QMK_KEYBOARD_H

enum preonic_layers {
    _DEFAULT,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCTION,
};

#define MO_FUNC MO(_FUNCTION)

enum preonic_keycodes {
    L_LOWER = SAFE_RANGE,
    L_RAISE,
};

#define RS_SLSH RSFT_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Back |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   M  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LCtrl |  Del | LGUI | LAlt |_LOWR |    Space    |_RAIS |_FUNC | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DEFAULT] = LAYOUT_preonic_1x2uC(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_M,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   RS_SLSH,
    KC_LCTL, KC_DEL,  KC_LGUI, KC_LALT, L_LOWER,      KC_SPC,      L_RAISE, MO_FUNC, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F17 |  F21 |      |      |   -  |   =  | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |  F5  |  F6  |  F7  |  F8  |  F18 |  F22 |      |  Up  |   [  |   ]  | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |  F9  |  F10 |  F11 |  F12 |  F19 |  F23 | Left | Down |Right |   '  | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |  F13 |  F14 |  F15 |  F16 |  F20 |  F24 |      |      |      | ____ | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | _3L_ |     ____    |_ADJS | ____ | ____ | ____ | ____ |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_1x2uC(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F17,  KC_F21,  XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F18,  KC_F22,  XXXXXXX, KC_UP,   KC_LBRC, KC_RBRC, _______,
    KC_CAPS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F19,  KC_F23,  KC_LEFT, KC_DOWN, KC_RGHT, KC_QUOT, _______,
    _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F20,  KC_F24,  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
    _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |PrtSc |ScrLk |Pause |      |      |      |      |NumLk |Num / |Num * |Num - |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |Insrt | Home | PgUp |      |      |      |      |Num 7 |Num 8 |Num 9 |Num + |
 * |------+------+------+------+------+------+------+------+--- --+--- --+--- --+--- --|
 * | Caps |  Del |  End | PgDn |      |      |      |      |Num 4 |Num 5 |Num 6 |   ,  |
 * |------+------+------+------+------+------+------+------+--- --+--- --+--- --+--- --|
 * | ____ |      |      |      |      |      |      |      |Num 1 |Num 2 |Num 3 |NumEn |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ |_ADJS |     ____    | _3L_ |Num 0 |Num 0 |Num . |NumEn |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_1x2uC(
    KC_GRV,  KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    _______, KC_INS,  KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    KC_CAPS, KC_DEL,  KC_END,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_COMM,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    _______, _______, _______, _______, _______,      _______,     _______, KC_P0,   KC_P0,   KC_PDOT, KC_PENT
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |      |      |      |      |      |      |      |      |      |      | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |      |WhelD |MousU |WhelU |      |      |MBtn3 |MBtn3 |MBtn5 |      | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |      |MousL |MousD |MousR |      |      |MBtn1 |MBtn2 |MBtn4 |      | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |      |WhelL |      |WhelR |      |      |MAcc0 |MAcc1 |MAcc2 | ____ | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | _3L_ |     ____    | _3L_ | ____ | ____ | ____ | ____ |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_1x2uC(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, KC_WH_D, KC_MS_U, KC_WH_U, XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN3, KC_BTN5, XXXXXXX, _______,
    _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN4, XXXXXXX, _______,
    _______, XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
    _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |  Win |  Mac |      |      |Reset |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |GUIOn |GUIOf |      |      |      |      | Stop | Rwnd | Frwd |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Play | Prev | Next |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShft |      |      |      |      |      |      | Mute | Vol- | Vol+ |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RCtrl |      | RGUI | RAlt |      |             |      | _MO_ |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_preonic_1x2uC(
    XXXXXXX, AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, GUI_ON,  GUI_OFF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MSTP, KC_MRWD, KC_MFFD, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,
    KC_RSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
    KC_RCTL, XXXXXXX, KC_RGUI, KC_RALT, XXXXXXX,      XXXXXXX,     XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_LOWER: {
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        }
        case L_RAISE: {
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        }
    }
    return true;
};
