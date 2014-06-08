#ifndef _SKIER_HPP
#define _SKIER_HPP

#include <SFML/System/Time.hpp>

#include "moving_game_object.hpp"

class Skier : public Moving_game_object {
  public:
    Skier( char const * name );
    ~Skier();

    sf::Time Get_run_time();
    void Update( sf::Time elapsed_time ); 

  private:
    sf::Vector2< long double > m_velocity;
    long double m_terminal_velocity;
    sf::Time    m_run_time;

    // Used internally for angle calculations
    struct Sprite_angle;

    // Internal functions to assist in updating
    void Update_velocity( sf::Time elapsed_time );
    void Update_sprite( sf::Time elapsed_time );

    void Normalize_velocity();
};

#endif // _SKIER_HPP
