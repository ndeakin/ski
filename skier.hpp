#pragma once

#include "visible_game_object.hpp"

class Skier : public Visible_game_object {
 public:
  Skier();
  ~Skier();

  void Update( float elapsed_time );
  void Draw( sf::RenderWindow & rw );

  float Get_velocity() const;

 privat:
  float m_velocity; // -- left ++ right
  float m_terminal_velocity;
};
