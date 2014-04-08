#include "error.hpp"
#include "game.hpp"
#include "gate.hpp"
#include "moving_game_object_manager.hpp"
#include "race_course.hpp"
#include "skier.hpp"
//#include "splash_screen.hpp"
#include "sprites.hpp"

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>

Game::Game_state    Game::g_game_state = UNINITIALIZED;
sf::RenderWindow    Game::g_main_window;
Game_object_manager Game::g_game_object_manager;
bool                Game::g_is_multiplayer = false;

Skier *             Game::g_skier = NULL;
Race_course *       Game::g_race_course = NULL;

// TODO: create Is_multiplayer() and Set_multiplayer( bool ) functions

void Game::Start() {
    if( Game::g_game_state != Game::UNINITIALIZED ) {
        return;
    }

    // The 0th entry of the array-like object returned by getFullscreenModes()
    // is always the video mode with the best resolution and colour depth.
    g_main_window.create( sf::VideoMode::getFullscreenModes()[0],
                          "Ski!",
                          sf::Style::Fullscreen );

    Load_game_objects();

    g_game_state = Game::PLAYING;
    // Skip Splash for now
    //g_game_state = Game::SHOWING_MENU;
    //g_game_state = Game::SHOWING_SPLASH; 
    Game_loop();
  
    Clean_up_game_objects();
    g_main_window.close();
}

void Game::Game_loop() {
    sf::Time dt = sf::seconds( 1.0f / 60.0f );
    sf::Clock clock;

    sf::Time current_time = clock.getElapsedTime();
    sf::Time new_time = clock.getElapsedTime();
    sf::Time frame_time = new_time - current_time;
    while( !Is_exiting() ) {
        new_time = clock.getElapsedTime();
        frame_time = new_time - current_time;
        current_time = new_time;

        for( int i = 0; frame_time > sf::microseconds( 0 ) && i < 3 && !Is_exiting(); ++i ) {
            // delta time is the lower of frame_time and dt
            sf::Time delta_time = (( frame_time > dt ) ? dt : frame_time);

            frame_time -= delta_time;

            Update_game_state( current_time, delta_time );
        }
    
        Render();
    }
}

sf::RenderWindow & Game::Get_window() {
    return g_main_window;
}

Game_object_manager & Game::Get_game_object_manager() {
    return g_game_object_manager;
}

const Game::Game_state Game::Get_game_state() {
    return g_game_state;
}

bool Game::Is_exiting() {
    if( g_game_state == Game::EXITING ) {
        return true;
    } else {
        return false;
    }
}

void Game::Update_game_state( sf::Time current_time, sf::Time delta_time ) {
    sf::Event current_event;
    g_main_window.pollEvent( current_event );

    switch( g_game_state ) {
        case Game::SHOWING_MENU: {
            // TODO: See note at Game::Show_menu defintion
            if( Show_menu() ) {
                // TODO: move Load_game_objects() call to here once menu is used
            }
            break;
        }
        case Game::SHOWING_SPLASH: {
            // TODO: Show_splash_screen doesn't actually do anything currently,
            //       other than change the game state to the menu
            Show_splash_screen();
            break;
        }
        case Game::PLAYING: {
            g_main_window.clear( sf::Color( 0xFF, 0xFF, 0xFF ) );

            g_game_object_manager.Update_all( delta_time );

            if( current_event.type == sf::Event::Closed ) {
                g_game_state = Game::EXITING;
            }
      
            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) ) {
                g_game_state = EXITING;

                // TODO: should open a menu instead of exiting
                // NOTE: make sure to stop objects from moving while game is paused
            }
            break;
        }
        default: {
            // shoudln't normally get here.
            Assert( false, FE_GAME_IN_UNKNOWN_GAME_STATE );
            break;
        }
    }
}

void Game::Render() {
    g_game_object_manager.Draw_all( g_main_window );
    g_main_window.display();
}

void Game::Show_splash_screen() {
    // TODO: implement class Splash_screen
    // Splash_screen splash_screen;
    // splash_screen.Show( g_main_window );
    g_game_state = Game::SHOWING_MENU;
}

// TODO: Fix the implementation of Show_menu (returns bool? not very intuitive).
bool Game::Show_menu() {
    if( g_game_state == Game::SHOWING_MENU ) {
        return true;
    } else {
        return false;
    }
}

void Game::Load_game_objects() {
    Sprites::Initialize_sprite_sheet();

    g_skier = new Skier( "Skier" );
    g_skier->Set_position( SKIER_START_X, SKIER_START_Y );
    Moving_game_object_manager::Instance()->Set_focused_object( g_skier );
    Moving_game_object_manager::Instance()->Set_focused_object_y( SKIER_START_Y );

    g_race_course = new Race_course();
}

void Game::Clean_up_game_objects() {
    delete g_skier;
    delete g_race_course;
}

void Game::Update_gate_keeping() {
    static sf::Vector2f last_skier_position = sf::Vector2f( SKIER_START_X,
                                                            SKIER_START_Y );

    if( g_skier == NULL || g_race_course == NULL ) {
        Assert( false, EC_GAME_ATTEMPTED_GATE_KEEPING_WITHOUT_SKIER_OR_COURSE );
        return;
    }
    
    sf::Vector2f skier_position = g_skier->Get_position();
    Gate const *    next_gate = g_race_course->Get_next_gate();

    if( skier_position.y < next_gate->Get_height() ) {
        last_skier_position = skier_position;
        return;
    }

    if( skier_position.x > next_gate->Get_right_gate_position().x ||
        skier_position.x < next_gate->Get_left_gate_position().x )
    {
        Handle_gate_missed();
    }

    // TODO: detect and then handle gate collisions

    g_race_course->Increment_next_gate();
    last_skier_position = skier_position;
}

void Game::Handle_gate_missed() {
    g_game_state = EXITING;
}

void Game::Handle_gate_collision() {
    // TODO: implement Game::Handle_gate_collision()
}
