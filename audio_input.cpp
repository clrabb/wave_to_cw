#include <arduino.h>
#include "audio_input.h"
#include "constants.h"


audio_input::audio_input( short read_pin )
:
  m_read_pin( read_pin ),
  m_is_high( false ),
  m_last_above_threshold_millis( 0 )
{
  pinMode( this->m_read_pin, INPUT );
}

float
audio_input::read_value()
{
  float value = analogRead( this->m_read_pin );
  return value;
}

bool
audio_input::is_high()
{
  unsigned long current_millis = millis();
  unsigned long time_since_high_millis = current_millis - this->last_above_threshold_millis();

  return time_since_high_millis < AUDIO_DEBOUNCE_MILLIS;
}

void
audio_input::beat()
{
  float value = this->read_value();
  if ( value > AUDIO_KEY_THRESHOLD )
  {
    this->last_above_threshold_millis( millis() );
  }
}