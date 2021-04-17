#include QMK_KEYBOARD_H
#include "tapdance.c"
#include "oled.c"
#include "keymap_german.h"

enum custom_keycodes {
  RGBRST = SAFE_RANGE, // reset RGB lightning

  RALT_ET = RALT_T(KC_ENT),
  // Shorter homerow mod tap keycodes
  // layer 0 - QWERTZ
  LGUI_A = LGUI_T(KC_A),
  LALT_S = LALT_T(KC_S),
  LCTL_D = LCTL_T(KC_D),
  LSFT_F = LSFT_T(KC_F),
  LSFT_J = LSFT_T(KC_J),
  LCTL_K = LCTL_T(KC_K),
  LALT_L = LALT_T(KC_L),
  LGUI_OE = LGUI_T(KC_SCLN),

  // layer 1 - no mod tap keycodes

  // layer 2 - WORKMAN
  LCTL_H = LCTL_T(KC_H),
  LSFT_T = LSFT_T(KC_T),
  LSFT_N = LSFT_T(KC_N),
  LCTL_E = LCTL_T(KC_E),
  LALT_O = LALT_T(KC_O),
  LGUI_I = LGUI_T(KC_I),

  // layer 3 - no mod tap keycodes

  // layer 4 - functions & numpad
  LGUI_L4 = LGUI_T(KC_F5),
  LALT_L4 = LALT_T(KC_F6),
  LCTL_L4 = LCTL_T(KC_F7),
  LSFT_L4 = LSFT_T(KC_F8),
  LSFT_R4 = LSFT_T(KC_KP_4),
  LCTL_R4 = LCTL_T(KC_KP_5),
  LALT_R4 = LALT_T(KC_KP_6),
  LGUI_R4 = LGUI_T(KC_PPLS),

  // layer 5 - homerow numbers & shifted numbers
  LGUI_L5 = LGUI_T(DE_ADIA),
  LALT_L5 = LALT_T(DE_ODIA),
  LCTL_L5 = LCTL_T(DE_UDIA),
  LSFT_L5 = LSFT_T(DE_TILD),
  LSFT_R5 = LSFT_T(KC_EQL),
  LCTL_R5 = LCTL_T(KC_LCBR),
  LALT_R5 = LALT_T(KC_RCBR),
  LGUI_R5 = LGUI_T(KC_PIPE),

  // layer 6 - homerow numbers & function keys - possibly unneccessary
  LGUI_L6 = LGUI_T(KC_1),
  LALT_L6 = LALT_T(KC_2),
  LCTL_L6 = LCTL_T(KC_3),
  LSFT_L6 = LSFT_T(KC_4),
  LSFT_R6 = LSFT_T(KC_7),
  LCTL_R6 = LCTL_T(KC_8),
  LALT_R6 = LALT_T(KC_9),
  LGUI_R6 = LGUI_T(KC_0),

  // layer 7 - navigation and only needs simple mod keys on lefthand side
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         DE_Z,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  LGUI_A,  LALT_S,  LCTL_D,  LSFT_F,    KC_G,                         KC_H,  LSFT_J,  LCTL_K,  LALT_L, LGUI_OE, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   TG(1),\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          RALT_ET,  MO(4),   KC_SPC,     KC_ENT,   MO(5),   MO(6)\
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F, _______,                      _______,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LSFT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,   TG(1),\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                         KC_J,    KC_F,    KC_U,    KC_P, KC_SCLN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  LGUI_A,  LALT_S,  LCTL_H,  LSFT_T,    KC_G,                         KC_Y,  LSFT_N,  LCTL_E,  LALT_O,  LGUI_I, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_L, KC_COMM,  KC_DOT, KC_SLSH,   TG(3),\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_H,    KC_T, _______,                      _______,    KC_N,    KC_E,    KC_O,    KC_I, KC_LSFT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,   TG(3),\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_1,                       KC_INS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST,  DE_EQL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, LGUI_L4, LALT_L4, LCTL_L4, LSFT_L4,    KC_2,                       KC_DEL, LSFT_R4, LCTL_R4, LALT_R4, LGUI_R4, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12,    KC_3,                      KC_PSLS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PMNS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,   MO(7),    KC_0\
                                      //`--------------------------'  `--------------------------'
  ),

  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       DE_DEG, DE_EXLM, DE_DQUO, DE_SECT,  DE_DLR, DE_PERC,                      DE_AMPR, DE_SLSH, DE_LPRN, DE_RPRN,  DE_EQL, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, LGUI_L5, LALT_L5, LCTL_L5, LSFT_L5, KC_TILD,                        DE_SS, LSFT_R5, LCTL_R5, LALT_R5, LGUI_R5, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, DE_PIPE, DE_SLSH, DE_BSLS, DE_HASH,  KC_GRV,                      DE_QUES, KC_PLUS, DE_TILD, KC_RBRC, KC_BSLS, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   MO(7), _______,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  ),

  [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  ),

  [7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,  TD(L0),                       TD(R0), XXXXXXX, KC_LSCR, KC_CLCK, KC_NLCK,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  TD(L1),                       TD(R1), KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        DF(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END,   DF(2),\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  )
};
