#ifndef _SKIER_HPP
#define _SKIER_HPP

#include "visible_game_object.hpp"

class Skier : public Visible_game_object {
 public:
  Skier();
  ~Skier();

  void Update( float elapsed_time );

  float Get_velocity() const;

 private:
  float m_velocity; // -- left ++ right
  float m_terminal_velocity;
};

#endif // _SKIER_HPP
