#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0		// default layer
#define Symbols 1		// symbols
#define Fn 2			// Function numbers
#define Accents 3		// accented letter
#define Navi 4	// navigation
#define MDIA 5			// media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   [  |   {  |   }  |   (  |   =  |      |           |      |   *  |   )  |   +  |   ]  |   !  |   #    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   |    |  ,;  |  ,<  |  .>  |   P  |   Y  |  Meh |           |  Meh |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   @    | A/Gui| O/Alt|E/Shft|U/Ctrl|   I  |------|           |------|   D  |H/Ctrl|T/Shft| N/Alt|S/Gui |   -    |
 * |--------+------+------+------+------+------| Hyper|           | Hyper|------+------+------+------+------+--------|
 * |   $    |  '"  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |   \    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | CAC  |  CAI |       | RESET|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | App  |       |      |      |      |
 *                                 |Enter/| Bck/ |------|       |------|  Tab/|Space/|
 *                                 | Symb | Fn   | Del  |       |  Esc |  Nav |Accent|
 *                                 `--------------------'       `--------------------'
 *
 * CAC = Ctrl Alt Canc	(for Windows)
 * CAP = Ctrl Alt Pause	(for VWMare)
 *
 */
[BASE] = KEYMAP(
        // left hand
		KC_TRNS,	KC_LBRC,		KC_LCBR,		KC_RCBR,		KC_LPRN,		KC_EQL,		KC_TRNS,
		KC_PIPE,	KC_QUOT,		KC_COMM,		KC_DOT,			KC_P,			KC_Y,		MEH_T(KC_NO),
		KC_AT,		GUI_T(KC_A),	ALT_T(KC_O),	SFT_T(KC_E),	CTL_T(KC_U),	KC_I,
		KC_DLR,		KC_QUOT,		KC_Q,			KC_J,			KC_K,			KC_X,		ALL_T(KC_NO),
		KC_TRNS,	KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,
		
																		LALT(LCTL(KC_DEL)),		LALT(LCTL(KC_PAUSE)),
																								ALT_T(KC_APP),
												LT(Symbols, KC_ENT),	LT(Fn, KC_BSPC),		KC_DEL,
        // right hand
		KC_TRNS,		KC_ASTR,	KC_RPRN,		KC_PLUS,		KC_RBRC,		KC_EXLM,		KC_HASH,
		MEH_T(KC_NO),	KC_F,		KC_G,			KC_C,			KC_R,			KC_L,			KC_SLSH,
                        KC_D,		CTL_T(KC_H),	SFT_T(KC_T),	ALT_T(KC_N),	GUI_T(KC_S),	KC_MINS,
		ALL_T(KC_NO),	KC_B,		KC_M,			KC_W,			KC_V,			KC_Z,			KC_BSLS,
									KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,
		
		RESET,			KC_TRNS,
		KC_TRNS,
		KC_ESC,			LT(Navi, KC_TAB),		LT(Accents, KC_SPC)
    ),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   $  |   #  |      |      |           |      |      |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | RGui | RAlt | RShft| RCtrl|   |  |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   ~  |   `  |      |      |           |      |      |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |    . |   =  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[Symbols] = KEYMAP(
       // left hand
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_EXLM,	KC_AT,		KC_DLR,		KC_HASH,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_RGUI,	KC_RALT,	KC_RSHIFT,	KC_RCTRL,	KC_PIPE,
		KC_TRNS,	KC_PERC,	KC_CIRC,	KC_TILD,	KC_GRV,		KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

																	KC_TRNS,	KC_TRNS,
																				KC_TRNS,
														KC_TRNS,	KC_TRNS,	KC_TRNS,
		// right hand
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_7,		KC_8,		KC_9,		KC_ASTR,	KC_TRNS,
					KC_TRNS,	KC_4,		KC_5,		KC_6,		KC_PLUS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_1,		KC_2,		KC_3,		KC_BSLS,	KC_TRNS,
								KC_0,		KC_DOT,		KC_EQL,		KC_TRNS,	KC_TRNS,

		KC_TRNS,	KC_TRNS,
		KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS
	),

/* Keymap 2: Fn Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |  F10 |  F11 |  F12 |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  F7  |  F8  |  F9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | RGui | RAlt | RShft| RCtrl|      |------|           |------|      |  F4  |  F5  |  F6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  F1  |  F2  |  F3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
 [Fn] = KEYMAP(
       // left hand
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,		KC_RGUI,	KC_RALT,	KC_RSHIFT,	KC_RCTRL,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

																		KC_TRNS,	KC_TRNS,
																					KC_TRNS,
															KC_TRNS,	KC_TRNS,	KC_TRNS,
		// right hand
		KC_TRNS,		KC_TRNS,	KC_F10,		KC_F11,		KC_F12,		KC_TRNS,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_F7,		KC_F8,		KC_F9,		KC_TRNS,	KC_TRNS,
						KC_TRNS,	KC_F4,		KC_F5,		KC_F6,		KC_TRNS,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_F1,		KC_F2,		KC_F3,		KC_TRNS,	KC_TRNS,
									KC_TRNS,	KC_DOT,		KC_EQL,		KC_TRNS,	KC_TRNS,

		KC_TRNS,		KC_TRNS,
		KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS
	),



/* Keymap 3: Accents Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   á  |   é  |   ó  |   ú  |   í  |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   à  |   è  |   ò  |   ù  |   ì  |------|           |------|      | RCtrl| RShft| RAlt | RGui |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   ä  |   ë  |   ö  |   ü  |   ï  |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
 [Accents] = KEYMAP(
       // left hand
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,		UC(0xe1),	UC(0xe9),	UC(0xf3),	UC(0xfa),	UC(0xed),	KC_TRNS,
		KC_TRNS,		UC(0xe0),	UC(0xe8),	UC(0xf2),	UC(0xf9),	UC(0xec),
		KC_TRNS,		UC(0xe4),	UC(0xeb),	UC(0xf6),	UC(0xfc),	UC(0xef),	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

																		KC_TRNS,	KC_TRNS,
																					KC_TRNS,
															KC_TRNS,	KC_TRNS,	KC_TRNS,
		// right hand
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
						KC_TRNS,	KC_RCTRL,	KC_RSHIFT,	KC_RALT,	KC_RGUI,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
									KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

		KC_TRNS,		KC_TRNS,
		KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS
	),



/* Keymap 4: Navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | RGui | RAlt | RShft| RCtrl|      |------|           |------|      | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Home |  End | PgUp |PgDown|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
 [Navi] = KEYMAP(
       // left hand
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,		KC_RGUI,	KC_RALT,	KC_RSHIFT,	KC_RCTRL,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

																		KC_TRNS,	KC_TRNS,
																					KC_TRNS,
															KC_TRNS,	KC_TRNS,	KC_TRNS,
		// right hand
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_UP,		KC_TRNS,	KC_TRNS,	KC_TRNS,
						KC_TRNS,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_TRNS,	KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_HOME,	KC_END,		KC_PGUP,	KC_PGDN,	KC_TRNS,
									KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

		KC_TRNS,		KC_TRNS,
		KC_TRNS,
		KC_TRNS,		KC_TRNS,	KC_TRNS
	),








	
	/* Keymap 5: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
		case 5:
			ergodox_right_led_1_on();
			ergodox_right_led_3_on();
			break;
		default:
            // none
            break;
    }

};
