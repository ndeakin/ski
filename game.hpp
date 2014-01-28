#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "game_object_manager.hpp"
#include "skier.hpp"

class Gane {
 public:
  static void Start();
  static sf::RenderWindow & GetWindow();
  
  const static sf::Input & GetInput();
  const statuc Game_object_manager & Game::Get_game_object_manager();
  
  const static int SCREEN_WIDTH =  1600;
  const static int SCREEN_HEIGHT = 900;

 private:
  static bool Is_exiting();
  static void Game_loop();

  static void Show_splash_screen();
  static bool Show_menu();

  static void Create_players();

  enum Game_state {
    UNINITIALIZED, SHOWING_SPLASH, SHOWING_MENU, PLAYING, PAUSED, EXITING
  };
  
  static Game_state           g_game_state;
  static sf::RenderWindow     g_main_window;
  static Game_object_manager  g_game_object_manager;
};

#endif // _GAME_HPP
