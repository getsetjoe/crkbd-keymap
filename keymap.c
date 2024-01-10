/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
// #include "keymap_uk.h"

#define CTALTDL LCA(KC_DEL)
#define DELWORD C(KC_BSPC)
#define ALT_TAB A(KC_TAB)
// VS Code shortcuts
#define CTRL_A  C(KC_A)
#define CTRL_D  C(KC_D)
#define CTL_LFT C(KC_LEFT)
#define CTL_RGT C(KC_RIGHT)
#define ALT_UP  A(KC_UP)
#define ALT_DWN A(KC_DOWN)
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
// #define MTCHBRK C(S(KC_BSLS))
// Windows shortcuts
#define VDESK_L G(C(KC_LEFT))
#define VDESK_R G(C(KC_RIGHT))
#define WIN_L A(KC_TAB)
#define WIN_R S(A(KC_TAB))
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
  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, RSH_SCL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   TT(1),  KC_SPC,     KC_SPC,   MO(2), KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PGUP, KC_HOME,   KC_UP,  KC_END, DELLINE,                      KC_PLUS,    KC_7,    KC_8,    KC_9, KC_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_TAB,                      KC_MINS,    KC_4,    KC_5,    KC_6, KC_COLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    UNDO,     CUT,    COPY,   PASTE,  CTRL_D,                       KC_DOT,    KC_1,    KC_2,    KC_3,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX,   KC_AT, KC_CIRC,  KC_DLR, XXXXXXX,                      KC_AMPR, KC_LCBR, KC_RCBR, KC_SCLN,  KC_GRV, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_LT,  KC_EQL,   KC_GT, ALT_TAB,                      KC_PIPE, KC_LPRN, KC_RPRN,   ARROW, KC_COLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_COMM, KC_COLN,  CTRL_A,                      KC_HASH, KC_LBRC, KC_RBRC, XXXXXXX, KC_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      CTALTDL,  PG_TOP, OUTDENT,  ALT_UP,  INDENT, COPY_UP,                      XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F11, DELWORD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  PG_END, CTL_LFT, ALT_DWN, CTL_RGT, COPY_DN,                      KC_UNDS,   KC_F4,   KC_F5,   KC_F6,  KC_F12, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    REDO, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX,                      KC_TILD,   KC_F1,   KC_F2,   KC_F3, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______,  KC_F10
                                      //`--------------------------'  `--------------------------'
  )
};


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return OLED_ROTATION_270;
}

void oled_render_logo(void) {
  static const char PROGMEM corne_logo[] = {
                                                                                                                            //21
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x93,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB3,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD3,
    0};
  oled_write_P(corne_logo, false);
} 

void oled_render_mini_logo(void) {
  static const char PROGMEM mini_corne_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
  oled_write_P(mini_corne_logo, false);
  oled_write_P(PSTR("corne"), false);
}

void oled_render_layer_state(void) {
  static const char PROGMEM default_layer[] = {
    0x20, 0x94, 0x95, 0x96, 0x20,
    0x20, 0xb4, 0xb5, 0xb6, 0x20,
    0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
  static const char PROGMEM raise_layer[] = {
    0x20, 0x97, 0x98, 0x99, 0x20,
    0x20, 0xb7, 0xb8, 0xb9, 0x20,
    0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
  static const char PROGMEM lower_layer[] = {
    0x20, 0x9a, 0x9b, 0x9c, 0x20,
    0x20, 0xba, 0xbb, 0xbc, 0x20,
    0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
  static const char PROGMEM adjust_layer[] = {
    0x20, 0x9d, 0x9e, 0x9f, 0x20,
    0x20, 0xbd, 0xbe, 0xbf, 0x20,
    0x20, 0xdd, 0xde, 0xdf, 0x20, 0};

  switch (get_highest_layer(layer_state|default_layer_state)) {
    case _LOWER:
      oled_write_P(lower_layer, false);
      break;
    case _RAISE:
      oled_write_P(raise_layer, false);
      break;
    case _ADJUST:
      oled_write_P(adjust_layer, false);
      break;
    default:
      oled_write_P(default_layer, false);
  }
}

void oled_render_led_state(void) {
  led_t led_state = host_keyboard_led_state();

  if (led_state.caps_lock) {
    oled_write_P(PSTR(" CAPS"), false);
  } else {
    oled_write_P(PSTR("     "), false);
  }
}

void oled_render_space(void) {
  oled_write_P(PSTR("     "), false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_space();
    oled_render_space();
    oled_render_mini_logo();
    oled_render_space();
    oled_render_space();
    oled_render_layer_state();
    oled_render_space();
    oled_render_space();
    oled_render_led_state();
  } else {
    oled_render_logo();
    oled_scroll_left();
  }

  return false;
}

#endif // OLED_ENABLE


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


const uint16_t PROGMEM combo_vdesk_l[] = {KC_COMM, KC_COLN, COMBO_END};
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
