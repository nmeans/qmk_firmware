#include "chocopad.h"

#define _BASE 0

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_HYPA HYPR(KC_A)
#define KC_HYPB HYPR(KC_B)
#define KC_HYPC HYPR(KC_C)
#define KC_HYPD HYPR(KC_G) // QWERTY G == COLEMAK D
#define KC_HYPE HYPR(KC_K) // QWERTY K == COLEMAK E
#define KC_HYPF HYPR(KC_E) // QWERTY E == COLEMAK F
#define KC_HYPG HYPR(KC_T) // QWERTY T == COLEMAK G
#define KC_HYPH HYPR(KC_H)
#define KC_HYPI HYPR(KC_L) // QWERTY L == COLEMAK I
#define KC_HYPJ HYPR(KC_Y) // QWERTY Y == COLEMAK J
#define KC_HYPK HYPR(KC_N) // QWERTY N == COLEMAK K
#define KC_HYPL HYPR(KC_I) // QWERTY I == COLEMAK L

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = KC_KEYMAP(
  //,----+----+----+----.
     RTOG,RVAI,RVAD,RMOD,
  //|----+----+----+----|
     HYPI,HYPJ,HYPK,HYPL,
  //|----+----+----+----|
     HYPE,HYPF,HYPG,HYPH,
  //|----+----+----+----|
     HYPA,HYPB,HYPC,HYPD 
  //`----+----+----+----'
  )
};
