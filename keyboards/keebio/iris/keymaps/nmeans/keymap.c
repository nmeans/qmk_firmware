#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;
#define _BASE 0
#define _XTRA 1

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_LCTP CTL_T(KC_ESC)
#define KC_RSTP RSFT_T(KC_RGHT)

#define KC_XTRA MO(_XTRA)
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_RPLN RGB_M_P
#define KC_RGRD RGB_M_G

#define PERMISSIVE_HOLD

// Tap Dance Stuff
enum {
  TD_MAGIC_MODIFIER = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MAGIC_MODIFIER] = ACTION_TAP_DANCE_DOUBLE(KC_LCMD, KC_LALT)
};
#define KC_MMOD TD(TD_MAGIC_MODIFIER)

// Chrome Dev Tools
// We send 'L' here instead of 'I' because I use Colemak on the OS level, not the keyboard level
#define KC_DTLS LGUI(LALT(KC_L))
// Zoom Mic Mute
// We send 'A' here as the keys are in the same spot in Colemak and QWERTY
#define KC_ZMUT LGUI(LSFT(KC_A))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     EQL , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTP, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  , DEL,     ENT , N  , M  ,COMM,DOT ,SLSH,RSTP,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XTRA,MMOD,BSPC,         SPC ,MMOD,XTRA 
  //                  `----+----+----'        `----+----+----'
  ),

  [_XTRA] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TILD,    ,    ,VOLU,    ,    ,               DTLS,    , UP ,    ,    ,RVAI,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     GRV ,    ,MRWD,MPLY,MFFD,    ,                   ,LEFT,DOWN,RGHT,    ,RVAD,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     CAPS,    ,    ,VOLD,    ,    ,    ,     ZMUT,    ,LCBR,RCBR,LBRC,RBRC,RTOG,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XTRA,    ,    ,        MUTE,     ,XTRA 
  //                  `----+----+----'        `----+----+----'
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
  case _XTRA:
    rgblight_mode_noeeprom(32);
    break;
  default:
    rgblight_mode_noeeprom(25);
    break;
  }
  return state;
}
