/* Copyright 2021 Regan Palmer
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

enum combos {
  COMBO_BSP,
  COMBO_DEL,
  COMBO_NBS,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_ENT
};

#define LOWER  LT(1, KC_BSPC)
#define RAISE  LT(2, KC_SPC)
#define KC_SZ  LSFT_T(KC_Z)
#define KC_SSLSH  LSFT_T(KC_SLSH)
#define KC_SSC  LSFT_T(KC_SCLN)
#define KC_RSZ RSFT_T(KC_Z)
#define KC_GES LGUI_T(KC_ESC)
#define KC_AEN RALT_T(KC_ENT)
#define KC_CQT LCTL_T(KC_QUOT)
#define KC_CSL RCTL_T(KC_SLSH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
		KC_SZ, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SSLSH,
		KC_NO, KC_CQT, KC_GES, LOWER, KC_NO, KC_NO, RAISE, KC_AEN, KC_CSL, KC_NO),


	// LAYOUT(
	// 	KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L,
	// 	KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S,
	// 	KC_SSC, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_RSZ,
	// 	KC_NO, KC_CQT, KC_GES, LOWER, KC_NO, KC_NO, RAISE, KC_AEN, KC_CSL, KC_NO),

	LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_GRV, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PSCR,
		KC_MINS, KC_EQL, KC_LPRN, KC_RPRN, KC_BSLS, KC_INS, KC_HOME, KC_PGUP, KC_PGDN, KC_END,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS),

	LAYOUT(
		KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_F11, KC_F12,
		KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
		KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

const uint16_t PROGMEM combo_bsp[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_nbs[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_L, KC_SCLN, COMBO_END};
// const uint16_t PROGMEM combo_bsp[] = {KC_R, KC_L, COMBO_END};
// const uint16_t PROGMEM combo_del[] = {KC_C, KC_R, COMBO_END};
// const uint16_t PROGMEM combo_nbs[] = {KC_9, KC_0, COMBO_END};
// const uint16_t PROGMEM combo_tab[] = {KC_O, KC_E, COMBO_END};
// const uint16_t PROGMEM combo_esc[] = {KC_QUOT, KC_COMM, COMBO_END};
// const uint16_t PROGMEM combo_ent[] = {KC_N, KC_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSP] = COMBO(combo_bsp,KC_BSPC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  [COMBO_NBS] = COMBO(combo_nbs,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
};