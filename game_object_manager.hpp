#pragma once

#include "visible_game_object.hpp"

class Game_object_manager {
 public:
  Game_object_manager();
  ~Game_object_manager();

  void Add( std::string name, Visible_game_object * game_object);
  void Remove( std::string name );
  int Get_object_count() const;
  Visible_game_object * Get( std::string name ) const;

  void Draw_all( sf::RenderWindow & render_window );
  void Update_all();

  const static Game_object_manager & Get_object_manager();

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
