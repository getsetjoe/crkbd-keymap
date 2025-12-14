// Corne RP2040: Hold Q and plug in to enter bootloader

#include QMK_KEYBOARD_H

#define CTALTDL LCA(KC_DEL)
#define CTLBKSP C(KC_BSPC)
#define CTLDEL  C(KC_DEL)
#define ALT_TAB A(KC_TAB)
// VS Code shortcuts
#define CTRL_A  C(KC_A)
#define CTRL_D  C(KC_D)
#define CTL_LFT C(KC_LEFT)
#define CTL_RGT C(KC_RIGHT)
#define ALT_UP  A(KC_UP)
#define ALT_DWN A(KC_DOWN)
#define ALT_LFT A(KC_LEFT)
#define ALT_RGT A(KC_RIGHT)
#define INDENT  C(KC_RBRC)
#define OUTDENT C(KC_LBRC)
#define PG_TOP  C(KC_HOME)
#define PG_END  C(KC_END)
#define DELLINE C(S(KC_K))
#define UNDO    C(KC_Z)
#define REDO    C(KC_Y)
#define CUT     C(KC_X)
#define COPY    C(KC_C)
#define PASTE   C(KC_V)
#define COPY_UP S(A(KC_UP))
#define COPY_DN S(A(KC_DOWN))
#define EXP_SEL S(A(KC_RIGHT))
#define CTRL_P  C(KC_P)
#define CTL_S_P C(S(KC_P))
// #define AI_SGST A(KC_BSLS)
// #define MTCHBRK C(S(KC_BSLS))
// Windows shortcuts
#define VDESK_L G(C(KC_LEFT))
#define VDESK_R G(C(KC_RIGHT))
#define WIN_L A(KC_TAB)
#define WIN_R S(A(KC_TAB))
#define WIN_TAB G(KC_TAB)
// Mod-taps
#define RSH_SCL RSFT_T(KC_SCLN) // right-shift on hold, semicolon on tap

enum layers {
  _COLEMAK, // Colemak DH
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  ARROW = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, RM_NEXT,    RM_TOGG,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,  CTRL_P,    WIN_TAB,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, RSH_SCL,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   TT(1),  KC_SPC,     KC_SPC,   MO(2), KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      ALT_TAB, KC_PGUP, KC_HOME,   KC_UP,  KC_END, DELLINE, _______,    _______, KC_PLUS,    KC_7,    KC_8,    KC_9, KC_PERC, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_TAB, CTL_S_P,    _______, KC_MINS,    KC_4,    KC_5,    KC_6, KC_COLN, _______,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      _______,    UNDO,     CUT,    COPY,   PASTE,  CTRL_D,                       KC_DOT,    KC_1,    KC_2,    KC_3,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, XXXXXXX,   KC_AT, KC_CIRC,  KC_DLR, XXXXXXX, _______,    _______, KC_AMPR, KC_LCBR, KC_RCBR, KC_SCLN,  KC_GRV, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_LT,  KC_EQL,   KC_GT, ALT_TAB, CTL_S_P,    _______, KC_PIPE, KC_LPRN, KC_RPRN,   ARROW, KC_COLN, _______,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, ALT_LFT, EXP_SEL, ALT_RGT,  CTRL_A,                      KC_HASH, KC_LBRC, KC_RBRC, XXXXXXX, KC_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      CTALTDL,  PG_TOP, OUTDENT,  ALT_UP,  INDENT, COPY_UP, _______,    _______, CTLBKSP,   KC_F7,   KC_F8,   KC_F9,  KC_F11, CTLDEL ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______,  PG_END, CTL_LFT, ALT_DWN, CTL_RGT, COPY_DN, _______,    _______, KC_UNDS,   KC_F4,   KC_F5,   KC_F6,  KC_F12, _______,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      _______,    REDO, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX,                      KC_TILD,   KC_F1,   KC_F2,   KC_F3, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______,  KC_F10
                                      //`--------------------------'  `--------------------------'
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ARROW:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
    break;
  }
  return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


const uint16_t PROGMEM combo_vdesk_l[] = {EXP_SEL, ALT_RGT, COMBO_END};
const uint16_t PROGMEM combo_vdesk_r[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM combo_tab_prev[] = {KC_CIRC, KC_DLR, COMBO_END};
const uint16_t PROGMEM combo_tab_next[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM combo_save[] = {KC_LT, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_caps[] = {KC_LSFT, RSH_SCL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_vdesk_l, VDESK_L),
    COMBO(combo_vdesk_r, VDESK_R),
    COMBO(combo_tab_prev, C(KC_PGUP)),
    COMBO(combo_tab_next, C(KC_PGDN)),
    COMBO(combo_save, C(KC_S)),
    COMBO(combo_caps, KC_CAPS)
};
