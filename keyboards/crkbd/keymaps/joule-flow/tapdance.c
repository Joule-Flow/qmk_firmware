//Tap Dance Declarations
enum {
  TD_LALT_LGUI = 0,
  TD_LSHIFT_OPENPARENTHESIS = 1,
  TD_RSHIFT_CLOSEPARENTHESIS = 2,
  TD_RALT_QUOT = 3,
  TD_Q_AT = 4,
  TD_SPEN = 5,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for left Alt, twice for Left Gui
  [TD_LALT_LGUI]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LGUI),
  [TD_LSHIFT_OPENPARENTHESIS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, LSFT(KC_8)),
  [TD_RSHIFT_CLOSEPARENTHESIS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, RSFT(KC_9)),
  [TD_RALT_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_QUOT),

  [TD_Q_AT] = ACTION_TAP_DANCE_DOUBLE(KC_Q, ALGR(KC_Q)),
  [TD_SPEN] = ACTION_TAP_DANCE_DOUBLE(KC_SPC,KC_ENT),

  // Other declarations would go here, separated by commas, if you have them
};
