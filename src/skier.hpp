#ifndef _SKIER_HPP
#define _SKIER_HPP

#include <SFML/System/Time.hpp>

#include "moving_game_object.hpp"

class Skier : public Moving_game_object {
  public:
    Skier( char const * name );
    ~Skier();

    void Update( sf::Time elapsed_time ); 

    sf::Vector2< long double > m_velocity;
    long double  m_terminal_velocity;

  private:
    // Used internally for angle calculations
    struct Sprite_angle;

    // Internal functions to assist in updating
    void Update_velocity( sf::Time elapsed_time );
    void Update_sprite( sf::Time elapsed_time );

    void Normalize_velocity();
};

#endif // _SKIER_HPP
