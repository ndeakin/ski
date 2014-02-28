#ifndef _SKIER_HPP
#define _SKIER_HPP

#include <SFML/System/Time.hpp>

#include "moving_game_object.hpp"

class Skier : public Moving_game_object {
  public:
    Skier();
    ~Skier();

    void Update( sf::Time elapsed_time ); 

    // TODO ndeakin: explain this.
    struct Sprite_angle {
        static float const SLOPE_157_5 = 2.414213;
        static float const SLOPE_172_5 = 7.595754;
        // 180 - straight left
        static float const SLOPE_187_5 = -7.595754;
        static float const SLOPE_202_5 = -2.414213;
        static float const SLOPE_207_5 = -1.303225;
        static float const SLOPE_247_5 = -0.414213;
        // 270 - straight down
        static float const SLOPE_292_5 = 0.414213;
        static float const SLOPE_322_5 = 1.303225;
        static float const SLOPE_337_5 = 2.414213;
        static float const SLOPE_352_5 = 7.595754;
        // 0/360 - straight right
        static float const SLOPE_7_5 =   -7.595754;
        static float const SLOPE_22_5 =  -2.414213;
    };

    sf::Vector2< long double > m_velocity;
    long double  m_terminal_velocity;
  private:

    // Internal functions to assist in updating
    void Update_velocity( sf::Time elapsed_time );
    void Update_sprite( sf::Time elapsed_time );

    void Normalize_velocity();
};

#endif // _SKIER_HPP
