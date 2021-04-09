#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
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

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%c %dx%d",
           name,
           record->event.key.row, record->event.key.col);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};

  oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
      oled_render_active_locks();
      oled_render_layer_state();
      oled_render_keylog();

    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
