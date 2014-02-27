#ifndef _MOVING_GAME_OBJECT_MANAGER_HPP
#define _MOVING_GAME_OBJECT_MANAGER_HPP

#include "game_object_manager.hpp"
#include "moving_game_object.hpp"

class Moving_game_object_manager : public Game_object_manager {
  private:
    Moving_game_object *    m_focused_object;
  
  public:
    Moving_game_object_manager();
    ~Moving_game_object_manager();

    // Get and set the object that will be focused;
    void Set_focused_object( Moving_game_object * focus_object );
    Moving_game_object const *  Get_focused_object() const;
};

#endif // !_MOVING_GAME_OBJECT_MANAGER_HPP
