#ifndef _GAME_OBJECT_MANAGER_HPP
#define _GAME_OBJECT_MANAGER_HPP

#include <SFML/System/Time.hpp>

#include "visible_game_object.hpp"

class Game_object_manager {
  public:
    Game_object_manager();
    ~Game_object_manager();

    void Add( std::string name, Visible_game_object * game_object );
    void Remove( std::string name );
    Visible_game_object * Get( std::string name ) const;

    void Draw_all( sf::RenderWindow & render_window );
    void Update_all( sf::Time delta_time );

    const static Game_object_manager & Get_game_object_manager();

  private:
    std::map< std::string, Visible_game_object * > m_game_objects;

    struct Game_object_deallocator {
        void operator()( const std::pair< std::string,
                                          Visible_game_object * > & p ) const
        {
            delete p.second;
        }
    };
};

#endif  // _GAME_OBJECT_MANAGER_HPP
