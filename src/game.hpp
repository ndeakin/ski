#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

#include "game_object_manager.hpp"
#include "menu.hpp"
#include "skier.hpp"

class Race_course;
class Splash_screen;

class Game {
  public:
    Game();

    enum Game_state {
        UNINITIALIZED, SHOWING_SPLASH, SHOWING_MENU, PLAYING, PAUSED, EXITING
    };

    // TODO: support multiple resolutions
    static const int SCREEN_WIDTH =  1600;
    static const int SCREEN_HEIGHT = 900;

    // currently in the middle of the screen
    static const unsigned SKIER_START_X = 800;
    static const unsigned SKIER_START_Y = 200;

    void Start();
    sf::RenderWindow & Get_window();
  
    const sf::Keyboard::Key & Get_input();
    Game_object_manager & Get_game_object_manager();
    const Game_state Get_game_state();

  protected:
    friend class Game_object_manager;

    // Checks if the skier has missed or collided with a gate,
    // called by g_game_object_manager during update.
    void Update_gate_keeping();

  private:
    bool Is_exiting();
    void Game_loop();
    void Update_game_state( sf::Time current_time, sf::Time delta_time );
    void Render();

    void Show_splash_screen();
    void Done_showing_splash_screen();
    void Show_menu();
    void Done_showing_menu( Menu::Menu_result result);

    void Load_game_objects();
    void Clean_up_game_objects();

    void Handle_gate_missed();
    void Handle_gate_collision();
    void Handle_course_finished();

    void Show_time( sf::Time race_time );

    Game_state          m_game_state;
    sf::RenderWindow    m_main_window;
    Game_object_manager m_game_object_manager;
    bool                m_is_multiplayer;

    Splash_screen *     m_splash_screen;
    bool                m_done_start_splash;
    Menu *              m_menu;

    Skier *             m_skier;
    Race_course *       m_race_course;
    bool                m_course_finished;

    bool                m_game_objects_loaded;
};

#endif // _GAME_HPP
