/*
 * Author: Josue Galeas
 * Last Edit: 2018.03.16
 */

#include <stdint.h>
#include <stdbool.h>

#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

#define KEYMAP(K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017, K018, K019, K020, \
		K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117, K118, K119, K120, \
		K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, K217, K218, K219, K220, \
		K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, K316, K317, K318, K319, K320, \
		K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, K415, K416, K417, K418, K419, K420) {\
	{KC_##K000, KC_##K001, KC_##K002, KC_##K003, KC_##K004, KC_##K005, KC_##K006, KC_##K007, KC_##K008, KC_##K009, KC_##K010, KC_##K011, KC_##K012, KC_##K013, KC_##K014, KC_##K015, KC_##K016, KC_##K017, KC_##K018, KC_##K019, KC_##K020}, \
	{KC_##K100, KC_##K101, KC_##K102, KC_##K103, KC_##K104, KC_##K105, KC_##K106, KC_##K107, KC_##K108, KC_##K109, KC_##K110, KC_##K111, KC_##K112, KC_##K113, KC_##K114, KC_##K115, KC_##K116, KC_##K117, KC_##K118, KC_##K119, KC_##K120}, \
	{KC_##K200, KC_##K201, KC_##K202, KC_##K203, KC_##K204, KC_##K205, KC_##K206, KC_##K207, KC_##K208, KC_##K209, KC_##K210, KC_##K211, KC_##K212, KC_##K213, KC_##K214, KC_##K215, KC_##K216, KC_##K217, KC_##K218, KC_##K219, KC_##K220}, \
	{KC_##K300, KC_##K301, KC_##K302, KC_##K303, KC_##K304, KC_##K305, KC_##K306, KC_##K307, KC_##K308, KC_##K309, KC_##K310, KC_##K311, KC_##K312, KC_##K313, KC_##K314, KC_##K315, KC_##K316, KC_##K317, KC_##K318, KC_##K319, KC_##K320}, \
	{KC_##K400, KC_##K401, KC_##K402, KC_##K403, KC_##K404, KC_##K405, KC_##K406, KC_##K407, KC_##K408, KC_##K409, KC_##K410, KC_##K411, KC_##K412, KC_##K413, KC_##K414, KC_##K415, KC_##K416, KC_##K417, KC_##K418, KC_##K419, KC_##K420}}

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
	/* Default Layer */
	KEYMAP(GRV, PSLS, PAST, PMNS, ESC, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, EQL, BSPC, PSCR, SLCK, PAUS, \
			P7, P8, P9, PPLS, TAB, Q, W, E, R, T, Y, U, I, O, P, LBRC, RBRC, BSLS, INS, HOME, PGUP, \
			P4, P5, P6, NO, CAPS, A, S, D, F, G, H, J, K, L, SCLN, QUOT, NO, ENT, DELETE, END, PGDN, \
			P1, P2, P3, PENT, LSFT, Z, X, C, V, B, N, M, COMM, DOT, SLSH, NO, RSFT, NO, FN1, UP, FN2, \
			P0, NO, PDOT, NO, LCTL, LGUI, LALT, NO, NO, SPC, NO, NO, NO, RALT, RGUI, NO, FN0, RCTL, LEFT, DOWN, RGHT),

	/* FN Layer */
	KEYMAP(NLCK, TRNS, TRNS, TRNS, TRNS, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, TRNS, TRNS, TRNS, TRNS, \
			TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
			TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
			TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
			TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),

	/* Lower Layer */
	KEYMAP(TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, SLEP, WAKE, PWR, \
			TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, MUTE, VOLD, VOLU, \
			TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, MPRV, MPLY, MNXT, \
			TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
			TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),

	/* Upper Layer */
	KEYMAP(TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
			TRNS, TRNS, TRNS, TRNS, TRNS, BTN1, MS_U, BTN2, TRNS, WH_U, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
			TRNS, TRNS, TRNS, TRNS, TRNS, MS_L, MS_D, MS_R, WH_L, WH_D, WH_R, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
			TRNS, TRNS, TRNS, TRNS, TRNS, BTN3, BTN4, BTN5, ACL0, ACL1, ACL2, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
			TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),
};

const action_t PROGMEM fn_actions[] =
{
	ACTION_LAYER_MOMENTARY(1), // FN
	ACTION_LAYER_MOMENTARY(2), // Lower
	ACTION_LAYER_MOMENTARY(3), // Upper
};