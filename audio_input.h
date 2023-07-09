#ifndef AUDIO_INPUT_H
#define AUDIO_INPUT_H

class audio_input
{
private:
  unsigned short m_read_pin;
  unsigned long m_last_above_threshold_millis;
  bool m_is_high;

public:
  audio_input( short READ_PIN );
  float read_value();
  unsigned long last_above_threshold_millis() { return this->m_last_above_threshold_millis; }
  void last_above_threshold_millis( unsigned long value ) { this->m_last_above_threshold_millis = value; }
  bool is_high();
  
  void beat();


private:
    audio_input( const audio_input& );             // disable copy ctor
    audio_input& operator=( const audio_input& );  //disable assignment op

};

#endif // AUDIO_INPUT_H