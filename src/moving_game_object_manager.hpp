#ifndef _MOVING_GAME_OBJECT_MANAGER_HPP
#define _MOVING_GAME_OBJECT_MANAGER_HPP

#include "game_object_manager.hpp"

class Game;
class Moving_game_object;

class Moving_game_object_manager : public Game_object_manager {
  private:
    Moving_game_object *    m_focused_object;
    unsigned int            m_focused_object_y;
    std::vector< Moving_game_object * > m_objects;
  
  protected:
    friend class Game;
    friend class Moving_game_object;
    static Moving_game_object_manager * Instance();
    void Register_object( Moving_game_object * object );
    void Deregister_object( Moving_game_object * object );
    void Handle_object_move( Moving_game_object * object, float x, float y );

  public:
    Moving_game_object_manager();
    ~Moving_game_object_manager();

    // Get and set the object that will be focused;
    void Set_focused_object( Moving_game_object * focus_object );
    void Set_focused_object_y( unsigned int focused_object_y );
    Moving_game_object const *  Get_focused_object() const;
};

#endif // !_MOVING_GAME_OBJECT_MANAGER_HPP
