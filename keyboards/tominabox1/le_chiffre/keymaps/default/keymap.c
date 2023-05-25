/* Copyright 2020 tominabox1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV,
  _EMACS
};

/* enum combo_events { */
/*   COMBO_BSPC, */
/*   COMBO_ENT, */
/*   COMBO_TAB, */
/*   COMBO_ESC, */
/*   COMBO_DEL, */
/* }; */

enum custom_keycodes {
    EMACS_SAVE = SAFE_RANGE,
};

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_NAV_SPC LT(_NAV, KC_SPC)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,   KC_MPLY,  KC_Y,       KC_U,    KC_I,    KC_O,   KC_P,
    KC_A,   KC_S,   KC_CD,  KC_SF,   KC_G,             KC_H,       KC_SJ,   KC_CK,   KC_L,   KC_SCLN,
    KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,             KC_N,       KC_M,    KC_COMM, KC_DOT, KC_SLSH,
                            KC_LGUI, KC_NAV_SPC,       KC_NUM_SPC, KC_LALT
  ),

  [_NUM_SYM] = LAYOUT(
    KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,  KC_6,     KC_7,     KC_8,      KC_9,     KC_0,
    XXXXXXX,  XXXXXXX, KC_LCTL, KC_F,    KC_G,              KC_CIRC,  KC_MINS,  KC_EQUAL,  KC_LBRC,  KC_RBRC,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,  KC_QUOT,  KC_BSLS,   KC_GRV,   XXXXXXX,
                                KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS
  ),

  [_NAV] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TRNS,  XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,            XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS
  ),

  [_EMACS] = LAYOUT(
    XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  EMACS_SAVE,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                     XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

#ifdef COMBO_ENABLE
/* const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END}; */
/* const uint16_t PROGMEM combo_ent[] = {KC_L, KC_SCLN, COMBO_END}; */
/* const uint16_t PROGMEM combo_tab[] = {KC_W, KC_E, COMBO_END}; */
/* const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END}; */
/* const uint16_t PROGMEM combo_del[] = {KC_I, KC_O, COMBO_END}; */

/* combo_t key_combos[COMBO_COUNT] = { */
/*   [COMBO_BSPC] = COMBO(combo_bspc, KC_BSPC), */
/*   [COMBO_ENT] = COMBO(combo_ent, KC_ENT), */
/*   [COMBO_TAB] = COMBO(combo_tab, KC_TAB), */
/*   [COMBO_ESC] = COMBO(combo_esc, KC_ESC), */
/*   [COMBO_DEL] = COMBO(combo_del, KC_DEL), */

/* }; */
#endif

#ifdef OLED_ENABLE  //Special thanks to Sickbabies for this great OLED widget!
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;  // rotates for proper orientation
}

void render_lechiffre_logo(void) {
    static const char PROGMEM lechiffre_logo[] = {
	// 'lechiffre_logo', 32x20px
   0x00, 0x3e, 0x20, 0x20, 0x00, 0x18, 0x2c, 0xa8, 0x80, 0x00, 0x1c, 0x22, 0x22, 0x00, 0x3e, 0x08,
0x30, 0x00, 0x34, 0x00, 0x3c, 0x0a, 0x00, 0xbc, 0x8a, 0x00, 0x38, 0x08, 0x00, 0x18, 0x2c, 0x28,
0x00, 0xb6, 0xb6, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00,
0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xb6, 0xb6, 0x00,
0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00,
0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00
};

  oled_write_raw_P(lechiffre_logo, sizeof(lechiffre_logo));
}


static void render_layer_status(void) {
    oled_write_P(PSTR("-----"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _NUM_SYM:
            oled_write_ln_P(PSTR(" SYM"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR(" NAV"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
}

void render_keylock_status(led_t led_state) {
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("C"), led_state.caps_lock);
	oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
	oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), led_state.scroll_lock);
    //oled_write_ln_P(PSTR(" "), false);
}

void render_mod_status(uint8_t modifiers) {
       oled_write_P(PSTR("-----"), false);
    oled_write_ln_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_ln_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
    oled_write_ln_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));
    oled_write_ln_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
}

bool oled_task_user(void) {
    render_lechiffre_logo();
    oled_set_cursor(0,3);
    render_layer_status();	// Renders the current keyboard state (layer, lock, caps, scroll, etc)
	render_mod_status(get_mods()|get_oneshot_mods());
	render_keylock_status(host_keyboard_led_state());

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EMACS_SAVE:
        if (record->event.pressed) {
	  // emacs write buffer
	  SEND_STRING(SS_LCTL("x") SS_LCTL("s"));
        }
        break;
    }

    return true;
  }
#endif

#ifdef LEADER_ENABLE
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_X, KC_S) {
      // Emacs save
      SEND_STRING(SS_LCTL("x") SS_LCTL("s"));
    }
    SEQ_TWO_KEYS(KC_X, KC_B) {
      // Emacs buffer list
      SEND_STRING(SS_LCTL("x") "b");
    }
    SEQ_TWO_KEYS(KC_COMMA, KC_M) {
      // Emacs top of doc
      SEND_STRING(SS_LALT(SS_LSFT(",")));
    }
    SEQ_TWO_KEYS(KC_COMMA, KC_DOT) {
      // Emacs top of doc
      SEND_STRING(SS_LALT(SS_LSFT(".")));
    }
    SEQ_ONE_KEY(KC_COMMA) {
      // Toggle console
      SEND_STRING(SS_LCTL("`"));
    }
  }
}
#endif
