#include "error.hpp"
#include "game.hpp"
#include "gate.hpp"
#include "moving_game_object_manager.hpp"
#include "race_course.hpp"
#include "skier.hpp"
#include "splash_screen.hpp"
#include "sprites.hpp"
#include "time_digit.hpp"
#include "time_digit_sprites.hpp"

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>

Game::Game()
    : m_game_state( UNINITIALIZED ),
      m_is_multiplayer( false ),
      m_splash_screen( NULL ),
      m_menu( NULL ),
      m_skier( NULL ),
      m_race_course( NULL ),
      m_course_finished( false ),
      m_game_objects_loaded( false ),
      m_time_present( false )
{
    for( int i = 0; i < 9; i++ ) {
        m_time_digits[i] = NULL;
    }
}

void Game::Start() {
    if( m_game_state != UNINITIALIZED ) {
        return;
    }

    Moving_game_object_manager::Initialize( this );

    // The 0th entry of the array-like object returned by getFullscreenModes()
    // is always the video mode with the best resolution and colour depth:
    //     sf::VideoMode::getFullscreenModes()[0]
    //
    // This may be useful in the future for supporting multiple resolutions

    m_main_window.create( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ),
                          "Ski!",
                          sf::Style::Fullscreen );

    m_game_state = SHOWING_SPLASH;
    Game_loop();
  
    Clean_up_game_objects();
    m_main_window.close();
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
    return m_main_window;
}

Game_object_manager & Game::Get_game_object_manager() {
    return m_game_object_manager;
}

const Game::Game_state Game::Get_game_state() {
    return m_game_state;
}

bool Game::Is_exiting() {
    return m_game_state == Game::EXITING;
}

void Game::Update_game_state( sf::Time current_time, sf::Time delta_time ) {
    sf::Event current_event;
    m_main_window.pollEvent( current_event );

    switch( m_game_state ) {
        case SHOWING_MENU: {
            Show_menu();

            if( m_menu != NULL ) {
                m_menu->Update();

                Menu::Menu_result result = m_menu->Get_result();
                if( result != Menu::UNDECIDED ) {
                    Done_showing_menu( result );
                }
            }

            break;
        }
        case SHOWING_SPLASH: {
            Show_splash_screen();

            if( !m_game_objects_loaded ) {
                Load_game_objects();
            }

            if( m_splash_screen != NULL ) {
                m_splash_screen->Update();

                if( m_splash_screen->Is_finished() ) {
                    Done_showing_splash_screen();
                    m_done_start_splash = true;
                }
            }
            break;
        }
        case PLAYING: {
            m_main_window.clear( sf::Color( 0xFF, 0xFF, 0xFF ) );

            m_game_object_manager.Update_all( *this, delta_time );

            if( current_event.type == sf::Event::Closed ) {
                m_game_state = EXITING;
            }
      
            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) ) {
                m_game_state = SHOWING_MENU;
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
    m_game_object_manager.Draw_all( m_main_window );
    m_main_window.display();
}

void Game::Show_splash_screen() {
    if( m_splash_screen == NULL ) {
        m_splash_screen = new Splash_screen( this, "Splash Screen" );
        // TODO: maybe fix this hacky thing where everything is a splash scrren?
        if( !m_done_start_splash ) {
            m_splash_screen->Show();
        } else {
            if( m_course_finished ) {
                m_splash_screen->Show( "images/race_finished.png" );
            } else {
                m_splash_screen->Show( "images/disqualified.png" );
            }
        }
    }
}

void Game::Done_showing_splash_screen() {
    if( m_done_start_splash ) {
        // Set up for next race
        Clean_up_game_objects();
        Load_game_objects();
    }

    if( m_time_present ) {
        for( int i = 0; i < 9; i++ ) {
            delete m_time_digits[i];
            m_time_digits[i] = NULL;
        }
        m_time_present = false;
    }

    delete m_splash_screen;
    m_splash_screen = NULL;

    m_game_state = SHOWING_MENU;
}

void Game::Show_menu() {
    if( m_menu == NULL ) {
        m_menu = new Menu( this, "Menu" );
    }
}

void Game::Done_showing_menu( Menu::Menu_result result ) {
    switch( result ) {
        case Menu::PLAY:
            m_game_state = PLAYING;
            break;
        case Menu::EXIT:
            m_game_state = EXITING;
            break;
        case Menu::UNDECIDED:
            return;
            break;
    }
    delete m_menu;
    m_menu = NULL;
}

void Game::Load_game_objects() {
    Sprites::Initialize_sprite_sheet();

    delete m_skier;
    m_skier = new Skier( "Skier" );
    Assert( m_skier != NULL, FE_OUT_OF_MEMORY );

    m_skier->Set_position( SKIER_START_X, SKIER_START_Y );
    Moving_game_object_manager::Instance()->Set_focused_object( m_skier );
    Moving_game_object_manager::Instance()->Set_focused_object_y( SKIER_START_Y );

    delete m_race_course;
    m_race_course = new Race_course();
    Assert( m_race_course != NULL, FE_OUT_OF_MEMORY );
    m_race_course->Set_course_length( 10 );
    m_course_finished = false;

    m_game_objects_loaded = true;
}

void Game::Clean_up_game_objects() {
    delete m_skier;
    m_skier = NULL;
    delete m_race_course;
    m_race_course = NULL;
}

void Game::Update_gate_keeping() {
    static sf::Vector2f last_skier_position = sf::Vector2f( SKIER_START_X,
                                                            SKIER_START_Y );

    if( m_skier == NULL || m_race_course == NULL ) {
        Assert( false, EC_GAME_ATTEMPTED_GATE_KEEPING_WITHOUT_SKIER_OR_COURSE );
        return;
    }
    
    sf::Vector2f    skier_position = m_skier->Get_position();
    Gate const *    next_gate = m_race_course->Get_next_gate();

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
    
    last_skier_position = skier_position;

    if( m_race_course->Increment_next_gate() ) {
        Handle_course_finished();
    }
}

void Game::Handle_gate_missed() {
    m_game_state = SHOWING_SPLASH;
}

void Game::Handle_gate_collision() {
    // TODO: implement Game::Handle_gate_collision()
}

void Game::Handle_course_finished() {
    m_course_finished = true;
    m_game_state = SHOWING_SPLASH;

    Show_time( m_skier->Get_run_time() );
}

void Game::Show_time( sf::Time sf_race_time ) {
    // TODO: show the skier's time at the end of a race
    //       to be called in Handle_course_finished()
    // 790 left
    // 585 top

    m_time_present = true;

    long int race_time = sf_race_time.asMilliseconds();

    long int time_minutes = race_time / (1000 * 60);
    long int time_seconds = race_time / 1000;
    long int time_ms = race_time % 1000;

    // Where the digits should be placed
    float left_position = 790.0;
    float top_position = 585.0;

    m_time_digits[0] = new Time_digit( this,
                            "time_minute_1",
                            Time_digit::Get_int_rect( time_minutes / 10 ) );
    m_time_digits[0]->Set_position( left_position, top_position );
    left_position += m_time_digits[0]->Get_width();

    m_time_digits[1] = new Time_digit( this,
                            "time_minute_2",
                            Time_digit::Get_int_rect( time_minutes % 10 ) );
    m_time_digits[1]->Set_position( left_position, top_position );
    left_position += m_time_digits[1]->Get_width();

    m_time_digits[2] = new Time_digit( this,
                            "time_colon",
                            Sprites::TIME_DIGIT_COLON );
    m_time_digits[2]->Set_position( left_position, top_position );
    left_position += m_time_digits[2]->Get_width();

    m_time_digits[3] = new Time_digit( this,
                            "time_second_1",
                            Time_digit::Get_int_rect( time_seconds / 10 ) );
    m_time_digits[3]->Set_position( left_position, top_position );
    left_position += m_time_digits[3]->Get_width();

    m_time_digits[4] = new Time_digit( this,
                            "time_second_2",
                            Time_digit::Get_int_rect( time_seconds % 10 ) );
    m_time_digits[4]->Set_position( left_position, top_position );
    left_position += m_time_digits[4]->Get_width();

    m_time_digits[5] = new Time_digit( this,
                            "time_period",
                            Sprites::TIME_DIGIT_PERIOD );
    m_time_digits[5]->Set_position( left_position, top_position );
    left_position += m_time_digits[5]->Get_width();

    m_time_digits[6] = new Time_digit( this,
                            "time_ms_1",
                            Time_digit::Get_int_rect( (time_ms / 100) % 10 ) );
    m_time_digits[6]->Set_position( left_position, top_position );
    left_position += m_time_digits[6]->Get_width();

    m_time_digits[7] = new Time_digit( this,
                            "time_ms_2",
                            Time_digit::Get_int_rect( (time_ms / 10) % 10 ) );
    m_time_digits[7]->Set_position( left_position, top_position );
    left_position += m_time_digits[7]->Get_width();

    m_time_digits[8] = new Time_digit( this,
                            "time_ms_3",
                            Time_digit::Get_int_rect( time_ms % 10 ) );
    m_time_digits[8]->Set_position( left_position, top_position );
}
