#include "keymap_german.h"

//Tap Dance Declarations
enum {
  L0 = 0,
  R0 = 1,
  L1 = 2,
  R1 = 3,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [L0] = ACTION_TAP_DANCE_DOUBLE(DE_LBRC, DE_LABK), // 1x '[' || 2x '<'
  [R0] = ACTION_TAP_DANCE_DOUBLE(DE_RBRC, DE_RABK), // 1x ']' || 2x '>'
  [L1] = ACTION_TAP_DANCE_DOUBLE(DE_LPRN, DE_LCBR), // 1x '(' || 2x '{'
  [R1] = ACTION_TAP_DANCE_DOUBLE(DE_RPRN, DE_RCBR), // 1x ')' || 2x '}'
};
