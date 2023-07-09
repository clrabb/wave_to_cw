#include <Arduino.h>
#include "constants.h"
#include "heartbeat.h"
#include "audio_input.h"
#include "singleton_t.h"
#include "key.h"

void init_singletons()
{
  singleton_t< heartbeat > hb( new heartbeat( LED_BUILTIN, 1000, 1000 ) );
  singleton_t< audio_input > ai( new audio_input( AUDIO_INPUT_PIN ) );
  singleton_t< key > k( new key( KEY_DEBOUNCE_MILLIS ) );
  //singleton_t< key > k( new key() );
}


void setup() 
{
  init_singletons();
  Serial.begin( 9600 );
}

void loop()
{
  heartbeat& hb = singleton_t< heartbeat >::instance();
  key& k = singleton_t< key >::instance();
  audio_input& ai = singleton_t< audio_input >::instance();
  k.beat();
  hb.beat();
  ai.beat();

}
