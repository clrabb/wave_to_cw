#include "key.h"
#include "audio_input.h"
#include "singleton_t.h"
#include "constants.h"
#include <Arduino.h>

key::key(unsigned long debounce_millis)
  : m_last_state_changed_millis(0),
    m_debounce_millis(debounce_millis) 
    {
      pinMode( KEY_PIN, OUTPUT );
      digitalWrite( KEY_PIN, LOW );
    }

bool key::enough_time_passed() {
  return this->time_since_last_state_change() > this->debounce_millis();
}

bool key::not_enough_time_passed() {
  return !(this->enough_time_passed());
}

unsigned long
key::time_since_last_state_change() {
  return millis() - this->last_state_changed_millis();
}

void
key::press_key_down()
{
  digitalWrite( KEY_PIN, HIGH );
}

void
key::pop_key_up()
{
  digitalWrite( KEY_PIN, LOW );
}

void key::beat() {
  if (not_enough_time_passed())
    return;

  audio_input& input = singleton_t< audio_input >::instance();
  if ( input.is_high() )
  {
    this->pop_key_up();
  } 
  else 
  {
    this->press_key_down();
  }
}