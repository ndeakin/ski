#ifndef _MOVING_GAME_OBJECT_HPP
#define _MOVING_GAME_OBJECT_HPP

#include "visible_game_object.hpp"

class Moving_game_object : public Visible_game_object {
  public:
    void Update( sf::Time elapsed_time );
    void Move( float x, float y );
}

#endif // !_MOVING_GAME_OBJECT_HPP
