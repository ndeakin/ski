#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

#include "game_object_manager.hpp"
#include "skier.hpp"

class Game {
  public:
    enum Game_state {
        UNINITIALIZED, SHOWING_SPLASH, SHOWING_MENU, PLAYING, PAUSED, EXITING
    };

    static void Start();
    static sf::RenderWindow & Get_window();
  
    const static sf::Keyboard::Key & Get_input();
    const static Game_object_manager & Get_game_object_manager();
    const static Game_state Get_game_state();

    const static int SCREEN_WIDTH =  1600;
    const static int SCREEN_HEIGHT = 900;

  private:
    static bool Is_exiting();
    static void Game_loop();
    static void Update_game_state( sf::Time current_time, sf::Time delta_time );
    static void Render();

    static void Show_splash_screen();
    static bool Show_menu();

    static void Create_players();

    static Game_state           g_game_state;
    static sf::RenderWindow     g_main_window;
    static Game_object_manager  g_game_object_manager;
    static bool                 g_is_multiplayer;
};

#endif // _GAME_HPP
