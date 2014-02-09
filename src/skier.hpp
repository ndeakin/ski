#ifndef _SKIER_HPP
#define _SKIER_HPP

#include <SFML/System/Time.hpp>

#include "visible_game_object.hpp"

class Skier : public Visible_game_object {
 public:
  Skier();
  ~Skier();

  void Update( sf::Time elapsed_time ); 

 private:
  sf::Vector2f m_velocity;
  float m_terminal_velocity;

  // Internal functions to assist in updating
  void Update_velocity( sf::Time elapsed_time );
  void Update_sprite();

  void Normalize_velocity();
};

#endif // _SKIER_HPP
