#include QMK_KEYBOARD_H
#include "process_unicode.h"
#include "outputselect.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
/*
void eeconfig_init_user(void) {

set_unicode_input_mode(UC_WINC);

}
*/


enum unicode_name {  
TJOY, // 😂
FEAR, // 😱
COOL, // 😎
NEVK, // 🙊
CLOW, // 🤡
EVIL, // 🤡
};

const uint32_t PROGMEM unicode_map[] = {
  [TJOY] = 0x1F602,
  [FEAR] = 0x1F631,
  [COOL] = 0x1F60E,
  [NEVK] = 0x1F64A,
  [CLOW] = 0x1F921,
  [EVIL] = 0x1F608,
};


extern keymap_config_t keymap_config;

//Tap Dance Declarations
enum {
  TD_Z_LCTL = 0,
  TD_X_LGUI = 1,
  TD_C_LALT = 2,
  TD_A_LSHIFT = 3,
  TD_Q_ESC = 4,
  TD_S_TAB = 5,
  TD_B_SPACE = 6,
  TD_P_BSPC = 7,
  TD_SCLN_ENT = 8,
};

//Friendly Layer Names
enum gherkin_layers {
  _MACROPAD,
  _QWERTY,
  _SONGS,
  _NUMBERS,
  _SYMBOLS,
  _PLOVER,
  _ADJUST
};

// custom keycodes
enum gherkin_keycodes {
  MACROPAD = SAFE_RANGE,
  QWERTY,// = SAFE_RANGE,
  NUMBERS,
  SYMBOLS,
  SONGS,
  PLOVER,
  BACKLIT,
  MACSLEEP,
  AMD_RESTART,
  TELEGRAM_RESTART,
  EXPLORER_RESTART,
  RAGE_BUTTON,
  DISCORD_STREAM,
  DISCORD_MICROPHONE,
  OBS_STREAM,
  OBS_RECORD,
  GPU_SCREENSHOT,
  GPU_LATESTVIDEO,
  RTSS,
  EMOJI_FIGHT1,
  EMOJI_FIGHT2,
  EMOJI_EYES,
  EMOJI_PEKA,
  EMOJI_SHRUG,
  EMOJI_ANGRYPEKA,
/*
  COOL_ALT,
  EVIL_ALT,
  ROFL_ALT,
  FEAR_ALT,
  SEEN_ALT,
  CLOWN_ALT,
*/
  EXT_PLV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MACROPAD] = LAYOUT_ortho_3x10(
    QWERTY,       DISCORD_MICROPHONE, DISCORD_STREAM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AMD_RESTART,      OBS_STREAM,  GPU_SCREENSHOT,
    EMOJI_FIGHT1, EMOJI_EYES,         EMOJI_SHRUG,     X(COOL), X(TJOY), X(NEVK), XXXXXXX, TELEGRAM_RESTART, OBS_RECORD,  GPU_LATESTVIDEO,
    EMOJI_FIGHT2, EMOJI_PEKA,         EMOJI_ANGRYPEKA, X(EVIL), X(FEAR), X(CLOW), XXXXXXX, EXPLORER_RESTART, RAGE_BUTTON, RTSS
  ),
  [_QWERTY] = LAYOUT_ortho_3x10(
    TD(TD_Q_ESC),    KC_W,               KC_E,           KC_R,  KC_T,               KC_Y,   KC_U,  KC_I,     KC_O,    TD(TD_P_BSPC),
    TD(TD_A_LSHIFT), TD(TD_S_TAB),       KC_D,           KC_F,  KC_G,               KC_H,   KC_J,  KC_K,     KC_L,    TD(TD_SCLN_ENT),
    TD(TD_Z_LCTL),   TD(TD_X_LGUI),      TD(TD_C_LALT),  KC_V,  TD(TD_B_SPACE),     KC_N,   KC_M,  KC_COMM,  KC_DOT,  SFT_T(KC_ENT)
  ),
  [_NUMBERS] = LAYOUT_ortho_3x10(
    KC_1,   KC_2,   KC_3,   KC_4,    KC_5,                KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_F1,  KC_F2,  KC_F3,  KC_F4,   KC_F5,               KC_F6,    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ,
    KC_F7,  KC_F8,  KC_F9,  KC_F10,  LT(_ADJUST,KC_F11),  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT
  ),
  [_SYMBOLS] = LAYOUT_ortho_3x10(
    KC_EXLM,  KC_AT,        KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,     KC_RPRN,
    KC_GRV,   _______,      XXXXXXX,  KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_MINS,  KC_EQL ,  KC_SCLN,     KC_QUOT,
    KC_TILD,  MO(_ADJUST),  XXXXXXX,  KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_UNDS,  KC_PLUS,  S(KC_SCLN),  S(KC_QUOT)
  ),
  [_PLOVER] = LAYOUT_ortho_3x10(
    KC_Q,     KC_W,     KC_E,  KC_R,  KC_1,     KC_U,  KC_I,  KC_O,     KC_P,     KC_LBRC,
    KC_A,     KC_S,     KC_D,  KC_F,  KC_G,     KC_J,  KC_K,  KC_L,     KC_SCLN,  KC_QUOT,
    EXT_PLV,  XXXXXXX,  KC_C,  KC_V,  XXXXXXX,  KC_N,  KC_M,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
  [_ADJUST] = LAYOUT_ortho_3x10(
    RESET,    _______,  _______,  _______,  _______,  QWERTY,   NUMBERS,  SYMBOLS,  PLOVER,    SONGS,
    MUV_DE,   MUV_IN,   MU_ON,    MU_OFF,   _______,  _______,  _______,  _______,  MACSLEEP,  _______,
    BACKLIT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______
  )
};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case AMD_RESTART:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LGUI) "!!rest" SS_DELAY(500) SS_TAP(X_ENT));
        } else {
        // when keycode is released
        }
      break;
	  
	case TELEGRAM_RESTART:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_ESC))) SS_DELAY(500) "tele" SS_TAP(X_DEL) SS_DELAY(350) SS_TAP(X_ENT) SS_DELAY(350) SS_TAP(X_LGUI) "tele" SS_DELAY(350) SS_TAP(X_ENT));
        } else {
        // when keycode is released
        }
      break;

	case EXPLORER_RESTART:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_ESC))) SS_DELAY(500) "expl" SS_TAP(X_DEL) SS_DELAY(350) SS_TAP(X_ENT) SS_DELAY(350) SS_LCTL(SS_TAP(X_R)) SS_DELAY(350) "exp" SS_DELAY(350) SS_TAP(X_DOWN) SS_TAP(X_ENT));
        } else {
        SEND_STRING(SS_UP(X_ENT));
        }
      break;

	case RAGE_BUTTON:
      if (record->event.pressed) {
        SEND_STRING("UUU SUKA!!1" SS_DELAY(25) SS_TAP(X_ENT));
        } else {
        // when keycode is released
        }
      break;	  

	case DISCORD_STREAM:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_DOWN(X_F11));
        } else {
        SEND_STRING(SS_UP(X_LALT) SS_DELAY(50) SS_UP(X_F11));
        }
      break;	

	case DISCORD_MICROPHONE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F2));
        } else {
        // when keycode is released
        }
      break;	
	  
	case OBS_STREAM:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F17));
        } else {
        // when keycode is released
        }
      break;
	  
	case OBS_RECORD:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F16));
        } else {
        // when keycode is released
        }
      break;	
	  
	case GPU_SCREENSHOT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_DOWN(X_F1));
        } else {
        SEND_STRING(SS_UP(X_LALT) SS_DELAY(50) SS_UP(X_F1));
        }
      break;	
	  
	case GPU_LATESTVIDEO:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_DOWN(X_F10));
        } else {
        SEND_STRING(SS_UP(X_LALT) SS_DELAY(50) SS_UP(X_F10));
        }
      break;	
	  
	case RTSS:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_DOWN(X_F12));
        } else {
        SEND_STRING(SS_UP(X_LALT) SS_DELAY(50) SS_UP(X_F12));
        }
      break;	
	  
    case EMOJI_FIGHT1:
	if (record->event.pressed) {
      send_unicode_string("(ง ͠° ͟ل͜ ͡°)ง");
	  } else {
	  }
    return false;

    case EMOJI_FIGHT2:
	if (record->event.pressed) {
      send_unicode_string("(ง'̀-'́)ง");
	  } else {
	  }
    return false;
	
    case EMOJI_EYES:
	if (record->event.pressed) {
      send_unicode_string("(ಠ_ಠ)");
	  } else {
	  }
    return false;
	
    case EMOJI_PEKA:
	if (record->event.pressed) {
      send_unicode_string("(͡° ͜ʖ ͡°)");
	  } else {
	  }
    return false;
	
    case EMOJI_SHRUG:
	if (record->event.pressed) {
      send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
	  } else {
	  }
    return false;
	
    case EMOJI_ANGRYPEKA:
	if (record->event.pressed) {
      send_unicode_string("͠° ͟ل͜ ͡°");
	  } else {
	  }
    return false;


/*
    case COOL_ALT:
	if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(50) SS_DOWN(X_SCLN) SS_DELAY(50) SS_UP(X_LGUI) SS_DELAY(50) SS_UP(X_SCLN) "cool" SS_DOWN(X_ENT) SS_DELAY(50) SS_UP(X_ENT));
	  } else {
      
	  }
    return false; 

    case EVIL_ALT:
	if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(50) SS_DOWN(X_SCLN) SS_DELAY(50) SS_UP(X_LGUI) SS_DELAY(50) SS_UP(X_SCLN) "evil" SS_DOWN(X_ENT) SS_DELAY(50) SS_UP(X_ENT));
	  } else {
      
	  }
    return false; 

    case ROFL_ALT:
	if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(50) SS_DOWN(X_SCLN) SS_DELAY(50) SS_UP(X_LGUI) SS_DELAY(50) SS_UP(X_SCLN) "rofl" SS_TAP(X_RIGHT) SS_DOWN(X_ENT) SS_DELAY(50) SS_UP(X_ENT));
	  } else {
      
	  }
    return false; 

    case FEAR_ALT:
	if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(50) SS_DOWN(X_SCLN) SS_DELAY(50) SS_UP(X_LGUI) SS_DELAY(50) SS_UP(X_SCLN) "fear" SS_DOWN(X_ENT) SS_DELAY(50) SS_UP(X_ENT));
	  } else {
      
	  }
    return false; 

    case SEEN_ALT:
	if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(50) SS_DOWN(X_SCLN) SS_DELAY(50) SS_UP(X_LGUI) SS_DELAY(50) SS_UP(X_SCLN) "see" SS_DOWN(X_ENT) SS_DELAY(50) SS_UP(X_ENT));
	  } else {
      
	  }
    return false;

    case CLOWN_ALT:
	if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(50) SS_DOWN(X_SCLN) SS_DELAY(50) SS_UP(X_LGUI) SS_DELAY(50) SS_UP(X_SCLN) "clown" SS_DOWN(X_ENT) SS_DELAY(50) SS_UP(X_ENT));
	  } else {
      
	  }
    return false;
*/
	  
	  
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case NUMBERS:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistant_default_layer_set(1UL<<_NUMBERS);
      }
      return false;
      break;
    case SYMBOLS:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistant_default_layer_set(1UL<<_SYMBOLS);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(tone_plover);
        #endif
        layer_off(_NUMBERS);
        layer_off(_SYMBOLS);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_plover_gb);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    case MACSLEEP:
      if (record->event.pressed) {
          // ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_POWER);
          register_code(KC_RSFT);
          register_code(KC_RCTL);
          register_code(KC_POWER);
          unregister_code(KC_POWER);
          unregister_code(KC_RCTL);
          unregister_code(KC_RSFT);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    }
    return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_SONG(tone_startup);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif

void matrix_scan_user(void) {
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_Z_LCTL]  = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_LCTL),
  [TD_X_LGUI]  = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_LGUI),
  [TD_C_LALT]  = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_LALT),
  [TD_A_LSHIFT]  = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_LSHIFT),
  [TD_Q_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_S_TAB]  = ACTION_TAP_DANCE_DOUBLE(KC_S, KC_TAB),
  [TD_B_SPACE]  = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_SPACE),
  [TD_P_BSPC]  = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_BSPC),
  [TD_SCLN_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_ENT),
  
  
  
  
};

// don't know what this is doing...
/*
void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    DDRD |= (1 << 5); PORTD &= ~(1 << 5);
  } else {
    DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRB |= (1 << 0); PORTB &= ~(1 << 0);
  } else {
    DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {

  }

}
*/
