#ifndef _GATE_HPP
#define _GATE_HPP

#include <SFML/System/Time.hpp>

#include "moving_game_object.hpp"

class Gate : public Moving_game_object {
  public:
    enum Colour {
        RED,
        BLUE
    };

    Gate( std::string name, Colour color, float x, float y );
    virtual ~Gate();

    virtual void Update( sf::Time elapsed_time );
};

#endif // !_GATE_HPP
