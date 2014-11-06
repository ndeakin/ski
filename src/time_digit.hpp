#ifndef _TIME_DIGIT_HPP
#define _TIME_DIGIT_HPP

#include "visible_game_object.hpp"

#include <SFML/Graphics.hpp>

class Game;

class Time_digit : public Visible_game_object {
  public:
    Time_digit( Game * game,
                std::string name,
                sf::IntRect rect );

    // Get the rect corresponding to the digit passed.
    // ONLY call with a value in the range [0, 9].
    static sf::IntRect Get_int_rect( int digit );

  private:
    sf::IntRect m_rect;
};

#endif // !_TIME_DIGIT_HPP
