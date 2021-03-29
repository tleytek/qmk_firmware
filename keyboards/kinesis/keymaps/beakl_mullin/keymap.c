#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BL 0 // Beakl layer
#define _QW 1 // Qwerty layer
#define _GM 2 // Gaming Layer

#define _SF 3 // Custom Shift Layer
#define _SY 4 // Symbol Layer
#define _MV 5 // Movement Layer

#define _KP 6 // Keypad + Media Layer

#define _CT 16 // Central layer of all keymaps (QWERTY, BEAKL, GAMING

enum custom_keycodes {
    BEAKL = SAFE_RANGE,
    QWERTY,
    GAMING,
};

// Macro name shortcuts
#define SfTab S(KC_TAB)
#define MT_LGUI MT(MOD_LGUI, OSM(MOD_LGUI))
#define MT_LCTL MT(MOD_LCTL, OSM(MOD_LCTL))
#define MT_LSFT MT(MOD_LSFT, OSM(MOD_LSFT))
#define MT_LALT MT(MOD_LALT, OSM(MOD_LALT))

#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define SELALL LCTL(KC_A)
#define REDO LCTL(KC_Y)

/*

        Function Keys on All Layers (Keypad toggles):
        ,---------------------------------------------------------------.
        |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8   |
        `---------------------------------------------------------------'
        ,---------------------------------------------------------------.
        |  F9  |  F10 |  F11 |  F12 | PSCR | SCLK | PSBK | KYPD | RESET |
        `---------------------------------------------------------------'

        L0 BEAKL layer:
        ,-------------------------------------------.   ,-------------------------------------------.
        |        |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  |        |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        | CapsLck|   Q  |   H  |   O  |   U  |   X  |   |   G  |   C  |   R  |   F  |   Z  |        |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |    -   |   Y  |   I  |   E  |   A  |   .  |   |   D  |   S  |   T  |   N  |   B  |   ;    |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        | SftLyr |   J  |   /  |   ,  |   K  |   '  |   |   W  |   M  |   L  |   P  |   V  | SftLyr |
        `--------+------+------+------+------+------'   `------+------+------+------+------+--------'
                 | LGui | LCtl | LSft | LAlt |                 | RAlt | RSft | RCtl | RGui |
                 `---------------------------'                 `---------------------------'
                                   ,----------------.   ,----------------.
                                   |  Esc  |        |   |        |       |
                           ,-------|-------|--------|   |--------+-------+-------.
                           | Space |       |        |   |        |       |  Bksp |
                           |   /   |  Del  |--------|   |--------| Enter |   /   |
                           | Mvmnt |       |        |   |        |       |  Symb |
                           `------------------------'   `------------------------'

        L1 QWERTY layer:
        ,-------------------------------------------.   ,-------------------------------------------.
        |    =   |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  |   -    |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        | Tab    |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  |   \    |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        | CapLck |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |   '    |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        | LShift |   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  | RShift |
        `--------+------+------+------+------+------'   `------+------+------+------+------+--------'
                 |   `  |   \  | Left | Rght |                 |  Up  |  Dn  |   [  |   ]  |
                 `---------------------------'                 `---------------------------'
                                   ,----------------.   ,----------------.
                                   | LCtl  |  LAlt  |   |  RAlt  | RCtl  |
                           ,-------|-------|--------|   |--------+-------+-------.
                           |       |       |  LGUI  |   |  RGUI  |       |       |
                           | Space |  Del  |--------|   |--------| Enter | Bksp  |
                           |       |       | MO(L1) |   | MO(L2) |       |       |
                           `------------------------'   `------------------------'

        L2 QWERTY Gaming layer:
        ,-------------------------------------------.   ,-------------------------------------------.
        |    5   |   =  |   1  |   2  |   3  |   4  |   |   6  |   7  |   8  |   9  |   0  |   -    |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |    T   | Tab  |   Q  |   W  |   E  |   R  |   |   Y  |   U  |   I  |   O  |   P  |   =    |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |    G   | LShft|   A  |   S  |   D  |   F  |   |   H  |   J  |   K  |   L  |   ;  |   '    |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |    B   | LCtrl|   Z  |   X  |   C  |   V  |   |   N  |   M  |   ,  |   .  |   /  | RShift |
        `--------+------+------+------+------+------'   `------+------+------+------+------+--------'
                 |   `  |   [  | Left | Rght |                 |  Up  |  Dn  |   ]  |   \  |
                 `---------------------------'                 `---------------------------'
                                  ,-----------------.   ,-----------------.
                                  | LCtl  |   LAlt  |   |  LAlt   | RCtl  |
                          ,-------|-------|---------|   |---------+-------+-------.
                          |       |       |   RGUI  |   |  RGUI   |       |       |
                          | Space | LShft |---------|   |---------| Enter | Bksp  |
                          |       |       | MO(L16) |   | MO(L16) |       |       |
                          `-------------------------'   `-------------------------'

        L4 Symbol layer:
        ,-------------------------------------------.   ,-------------------------------------------.
        |        |      |      |      |      |      |   |      |      |      |      |      |        |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |        |      |   <  |   $  |   >  |      |   |      |   [  |   _  |   ]  |      |        |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |        |   \  |   (  |   "  |   )  |   #  |   |   %  |   {  |   =  |   }  |   |  |        |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |        |      |   :  |   *  |   +  |      |   |      |   &  |   ^  |   ~  |      |        |
        `--------+------+------+------+------+------'   `------+------+------+------+------+--------'
                 |      |      |      |      |                 |      |      |      |      |
                 `---------------------------'                 `---------------------------'
                                  ,-----------------.   ,-----------------.
                                  |       |         |   |         |       |
                          ,-------|-------|---------|   |---------+-------+-------.
                          |       |       |         |   |         |       |       |
                          |       |       |---------|   |---------|       |       |
                          |       |       |         |   |         |       |       |
                          `-------------------------'   `-------------------------'

        L5 Movement layer:
        ,-------------------------------------------.   ,-------------------------------------------.
        |        |      |      |      |      |      |   |      |      |      |      |      |        |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |        |      | STab |      |  Tab |      |   | STab | PgUp |  Up  | PgDn |      |        |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |        | LGui | LCtl | LSft | LAlt |      |   |      | Left |  Dn  | Rght |      |        |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |        | Undo |  Cut | Copy | Pste |SelAll|   |  Tab | Home |      |  End | Redo |        |
        `--------+------+------+------+------+------'   `------+------+------+------+------+--------'
                 |      |      |      |      |                 |      |      |      |      |
                 `---------------------------'                 `---------------------------'
                                  ,-----------------.   ,-----------------.
                                  |       |         |   |         |       |
                          ,-------|-------|---------|   |---------+-------+-------.
                          |       |       |         |   |         |       |       |
                          |       |       |---------|   |---------|       |       |
                          |       |       |         |   |         |       |       |
                          `-------------------------'   `-------------------------'

        L6 Keypad + Media layer:
        ,-------------------------------------------.   ,-------------------------------------------.
        |        |      |      |      |      |      |   |      | NmLk | KP = | KP / | KP * |        |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |        |      | Mute | Vol- | Vol+ |      |   |      | KP 7 | KP 8 | KP 9 | KP - |        |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |        | Stop | Prev | Play | Next | Sel  |   |      | KP 4 | KP 5 | KP 6 | KP + |        |
        |--------+------+------+------+------+------|   |------+------+------+------+------+--------|
        |        |      |      |      |      |      |   |      | KP 1 | KP 2 | KP 3 |KP Ent|        |
        `--------+------+------+------+------+------'   `------+------+------+------+------+--------'
                 |      |      |      |      |                 |   (  |   )  | KP . |KP Ent|      |
                 `---------------------------'                 `----------------------------------'
                                   ,----------------.   ,----------------.
                                   |       |        |   |        |       |
                            ,------|-------|--------|   |--------+-------+-------.
                            |      |       |        |   |        |       |       |
                            |      |       |--------|   |--------|KP Entr| KP 0  |
                            |      |       |        |   |        |       |       |
                            `-----------------------'   `------------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BL] = LAYOUT(
           // Left Hand
           KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
           _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
           KC_CAPS,  KC_Q,    KC_H,    KC_O,    KC_U,    KC_X,
           KC_MINS,  KC_Y,    KC_I,    KC_E,    KC_A,    KC_DOT,
           MO(_SF),  KC_J,    KC_SLSH, KC_COMM, KC_K,    KC_QUOT,
                     KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT,

           // Left Thumb
                              KC_ESC,           _______,
                                                _______,
           LT(_MV, KC_BSPC),  LT(_KP, KC_DEL),  MO(_KP),

           // Right Hand
           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, TO(_KP),  RESET,
           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
           KC_G,    KC_C,    KC_R,    KC_F,    KC_Z,    _______,
           KC_D,    KC_S,    KC_T,    KC_N,    KC_B,    KC_SCLN,
           KC_W,    KC_M,    KC_L,    KC_P,    KC_V,    MO(_SF),
                    KC_RALT, KC_RSFT, KC_RCTL, KC_RGUI,

           // Right Thumb
           _______, KC_ESC,
           _______,
           MO(_KP), KC_ENT,  LT(_SY, KC_SPC)
    ),

[_QW] = LAYOUT(
           // Left Hand
           KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
           KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
           KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
           KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
           KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                    KC_TILD, KC_LBRC, KC_LEFT, KC_RGHT,
           // Left Thumb
                    KC_LCTL, KC_LALT,
                             KC_LGUI,
           KC_SPC,  KC_DEL,  MO(_KP),

           // Right Hand
           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, TO(_KP),  RESET,
           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,
           // Right Thumb
           KC_RALT, KC_RCTL,
           KC_RGUI,
           MO(_KP), KC_ENT, KC_BSPC
    ),

[_GM] = LAYOUT(
           // Left Hand
           KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
           KC_5,    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,
           KC_T,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,
           KC_G,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,
           KC_B,    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,
                    KC_TILD, KC_LBRC, KC_LEFT, KC_RGHT,
           // Left Thumb
                    KC_ESC,  KC_LALT,
                             KC_LGUI,
           KC_SPC,  KC_DEL,  MO(_KP),

           // Right Hand
           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, TO(_KP),  RESET,
           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,

                    KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,
           // Right Thumb
           KC_RALT, KC_RCTL,
           KC_RGUI,
           MO(_KP), KC_ENT, KC_BSPC
    ),

[_SY] = LAYOUT(
           // Left Hand
           KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
           _______, _______, _______, _______, _______, _______,
           _______, _______, KC_LABK, KC_DLR,  KC_RABK, _______,
           _______, KC_BSLS, KC_LPRN, KC_DQUO, KC_RPRN, KC_HASH,
           _______, _______, KC_COLN, KC_ASTR, KC_PLUS, _______,
                    _______, _______, _______, _______,
           // Left Thumb
                      _______,   _______,
                                 _______,
           _______,   _______,   _______,

           // Right Hand */
           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, TO(_KP),  RESET,
           _______, _______, _______, _______, _______, _______,
           _______, KC_LBRC, KC_UNDS, KC_RBRC, _______, _______,
           _______, KC_RCBR, KC_EQL,  KC_LCBR, KC_PIPE, _______,
           _______, KC_AMPR, KC_CIRC, KC_TILD, _______, _______,
                    _______, _______, _______, _______,
           // Right Thumb
           _______,   _______,
           _______,
           _______,   _______, _______
    ),

[_MV] = LAYOUT(
           // Left Hand
           KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
           _______, _______, _______, _______, _______, _______,
           _______, _______, SfTab,   _______, KC_TAB,  _______,
           _______, MT_LGUI, MT_LCTL, MT_LSFT, MT_LALT, _______,
           _______, UNDO,    CUT,     COPY,    PASTE,   SELALL,
                    _______, _______, _______, _______,
           // Left Thumb
                      _______,   _______,
                                 _______,
           _______,   _______,   _______,

           // Right Hand */
           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, TO(_KP),  RESET,
           _______, _______, _______, _______, _______, _______,
           SfTab,   KC_PGUP, KC_UP,   KC_PGDN, _______, _______,
           _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
           KC_TAB,  KC_HOME, _______, KC_END,  REDO,    _______,
                    _______, _______, _______, _______,
           // Right Thumb
           _______, _______,
           _______,
           _______, _______, _______
    ),

[_KP] = LAYOUT(
           // Left Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,
           _______, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSEL,
           _______, _______, BEAKL,   QWERTY,  GAMING,  _______,
                    _______, _______, _______, _______,
           // Left Thumb
                    _______, _______,
                             _______,
           _______, _______, _______,

           // Right Hand */
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, KC_NLCK, KC_PEQL, KC_PSLS, KC_PAST, _______,
           _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
           _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
           _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
                    KC_LPRN, KC_RPRN, KC_PDOT, KC_PENT,
           // Right Thumb
           _______, _______,
           _______,
           _______, KC_PENT, KC_P0
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// {
//     switch(id) {
//     case _BL:
//       if (record->event.pressed) {
//         persistent_default_layer_set(1UL<<_BL);
//       }
//       break;
//     case _QW:
//       if (record->event.pressed) {
//         persistent_default_layer_set(1UL<<_QW);
//       }
//       break;
//     }
//     return MACRO_NONE;
// };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BEAKL:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BL);
      }

      return false;

      break;

    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QW);
      }

      return false;

      break;
    case GAMING:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GM);
      }

      return false;

      break;
  }

  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};
