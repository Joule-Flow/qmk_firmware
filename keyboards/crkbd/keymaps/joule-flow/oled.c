#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return OLED_ROTATION_270;
}

void oled_render_active_locks(void) {
  led_t led_state = host_keyboard_led_state();

  oled_write_P(PSTR("N"),led_state.num_lock ? true : false);
  oled_write_P(PSTR(" "),false);
  oled_write_P(PSTR("C"),led_state.caps_lock ? true : false);
  oled_write_P(PSTR(" "),false);
  oled_write_ln_P(PSTR("L"),led_state.scroll_lock ? true : false);
}


bool isAnEvenPosition(int position){
  return position % 2 == 0;
}

void oled_render_checkered_squares (int maxNumberOfSquares) {
  #define RENDER_SQUARE " "

  for (int i=0; i<maxNumberOfSquares;i++){
    oled_write_P(PSTR(RENDER_SQUARE), isAnEvenPosition(i) );
  }
}

void oled_render_layer_state(void) {
  #define L_BASE_QWERTZ 0
  #define L_GAME_QWERTZ (1 << 1)
  #define L_BASE_WORKMAN (1 << 2)
  #define L_GAME_WORKMAN (1 << 3)
  #define L_LOWER (1 << 4)
  #define L_RAISE (1 << 5)
  #define L_NUMBER (1 << 6)
  #define L_ADJUST (1 << 7)

    switch (layer_state) {
      case L_BASE_QWERTZ:
          oled_write_ln_P(PSTR("DEFLT"), false);
          break;
      case L_GAME_QWERTZ:
          oled_write_ln_P(PSTR("GMN-Q"), false);
          break;
      case L_BASE_WORKMAN:
          oled_write_ln_P(PSTR("WRKMN"), false);
          break;
      case L_GAME_WORKMAN:
          oled_write_ln_P(PSTR("GMN-W"), false);
          break;
      case L_LOWER:
      case L_LOWER|L_GAME_QWERTZ:
          oled_write_ln_P(PSTR("LOWER"), false);
          break;
      case L_RAISE:
      case L_RAISE|L_GAME_QWERTZ:
          oled_write_ln_P(PSTR("RAISE"), false);
          break;
      case L_NUMBER:
      case L_NUMBER|L_GAME_QWERTZ:
          oled_write_ln_P(PSTR("NMBRS"), false);
          break;
      case L_ADJUST:
      case L_ADJUST|L_LOWER:
      case L_ADJUST|L_RAISE:
      case L_ADJUST|L_LOWER|L_RAISE:
      case L_ADJUST|L_GAME_QWERTZ:
      case L_ADJUST|L_LOWER|L_GAME_QWERTZ:
      case L_ADJUST|L_RAISE|L_GAME_QWERTZ:
      case L_ADJUST|L_LOWER|L_RAISE|L_GAME_QWERTZ:
          oled_write_ln_P(PSTR("ADJST"), false);
          break;
      default:
          oled_write_ln_P(PSTR("? ? ?"), false);
          break;
  }
}


char     key_name_internal = ' ';
uint16_t last_keycode;
uint8_t  last_row;
uint8_t  last_col;

static const char PROGMEM code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};


static void set_keylog(uint16_t keycode, keyrecord_t *record) {
    // save the row and column (useful even if we can't find a keycode to show)
    last_row = record->event.key.row;
    last_col = record->event.key.col;

    key_name_internal     = ' ';
    last_keycode = keycode;
    if (IS_QK_MOD_TAP(keycode)) {
        if (record->tap.count) {
            keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
        } else {
            keycode = 0xE0 + biton(QK_MOD_TAP_GET_MODS(keycode) & 0xF) + biton(QK_MOD_TAP_GET_MODS(keycode) & 0x10);
        }
    } else if (IS_QK_LAYER_TAP(keycode) && record->tap.count) {
        keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    } else if (IS_QK_MODS(keycode)) {
        keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
    } else if (IS_QK_ONE_SHOT_MOD(keycode)) {
        keycode = 0xE0 + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0xF) + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0x10);
    }
    if (keycode > ARRAY_SIZE(code_to_name)) {
        return;
    }

    // update keylog
    key_name_internal = pgm_read_byte(&code_to_name[keycode]);
}

void oled_render_keylog(void) {
    oled_write_char('0' + last_row, false);
    oled_write_P(PSTR("x"), false);
    oled_write_char('0' + last_col, false);
    oled_write_P(PSTR(", k"), false);
    oled_write_P(PSTR(":"), false);
    oled_write_char(key_name_internal, false);
}

void oled_render_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_active_locks();
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
        oled_scroll_left();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

    return true;
}
#endif // OLED_ENABLE
