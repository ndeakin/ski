#ifndef _MOVING_GAME_OBJECT_HPP
#define _MOVING_GAME_OBJECT_HPP

#include "visible_game_object.hpp"

class Moving_game_object : public Visible_game_object {
  public:
    Moving_game_object();

    // Called with the elapsed time since the previous call.
    virtual void Update( sf::Time elapsed_time );

    // Move x and y away from current position.
    void Move( float x, float y );
};

#endif // !_MOVING_GAME_OBJECT_HPP
