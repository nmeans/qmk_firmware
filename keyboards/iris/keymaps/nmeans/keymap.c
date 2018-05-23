#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;
#define _BASE 0
#define _XTRA 1

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_LCTP CTL_T(KC_ESC)
#define KC_RSTP SFT_T(KC_RGHT)
#define TAPPING_TOGGLE 2

#define KC_XTRA TT(_XTRA)
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_RPLN RGB_M_P
#define KC_RGRD RGB_M_G

// Tap Dance Stuff
enum {
  TD_MAGIC_MODIFIER = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MAGIC_MODIFIER] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LALT)
};
#define KC_MMOD TD(TD_MAGIC_MODIFIER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     EQL , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTP, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,MMOD,     MMOD, N  , M  ,COMM,DOT ,SLSH,RSTP,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XTRA,BSPC,DEL ,        ENT, SPC,  XTRA 
  //                  `----+----+----'        `----+----+----'
  ),

  [_XTRA] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,VOLD,MUTE,VOLU,GRV ,                   , 7  , 8  , 9  ,RVAI,RMOD,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,MRWD,MPLY,MFFD,LBRC,               RBRC, 4  , 5 ,  6  ,RVAD,RPLN,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,LEFT,DOWN, UP ,RGHT,LCBR,    ,         ,RCBR, 1  , 2  , 3  ,RTOG,RGRD,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XTRA,    ,    ,             , 0  ,XTRA 
  //                  `----+----+----'        `----+----+----'
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
  case _XTRA:
    rgblight_mode(32);
    break;
  default:
    rgblight_mode(25);
    break;
  }
  return state;
}
