#ifndef KEY_H
#define KEY_H


class key
{
private:
  unsigned long m_last_state_changed_millis;
  unsigned long m_debounce_millis;
  bool  m_is_key_down;
  float m_threshold = 25.0;

public:
  key( unsigned long debounce_millis );


public:
  bool enough_time_passed();
  bool not_enough_time_passed();
  unsigned long time_since_last_state_change();

  unsigned long last_state_changed_millis() { return m_last_state_changed_millis; }
  void last_state_changed_millis( unsigned long millis ) { m_last_state_changed_millis = millis; }
  unsigned long debounce_millis() { return this->m_debounce_millis; }

private:
  void press_key_down();
  void pop_key_up();

public:
  void beat();

private:
  // disable ctors 
  //
  key( const key& );
  key& operator=( const key& );
}
;

#endif // KEY_H