#include "menu.hpp"

#include <SFML/Graphics.hpp>

// Button positions

static const int PLAY_LEFT = 100;
static const int PLAY_RIGHT = 380;
static const int PLAY_TOP = 100;
static const int PLAY_BOTTOM = 225;

static const int EXIT_LEFT = 100;
static const int EXIT_RIGHT = 380;
static const int EXIT_TOP = 226;
static const int EXIT_BOTTOM = 340;

Menu::Menu( Game * game, std::string name )
    : Visible_game_object( game, name ),
      m_result( UNDECIDED )
{}

void Menu::Show_in( sf::RenderWindow & render_window ) {
    Load( "images/menu.png" );
}

void Menu::Update() {
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) ) {
        m_result = PLAY;
    } else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) ) {
        m_result = EXIT;
    } else if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) {
        sf::Vector2i position = sf::Mouse::getPosition();
        if( position.x > PLAY_LEFT && position.x < PLAY_RIGHT &&
            position.y > PLAY_TOP && position.y < PLAY_BOTTOM )
        {
            m_result = PLAY;
        
        } else if( position.x > EXIT_LEFT && position.x < EXIT_RIGHT &&
                   position.y > EXIT_TOP && position.y < EXIT_BOTTOM )
        {
            m_result = EXIT;
        }
    } else {
        // TODO: add some sort of animation to indicate if a button is being hovered over
    }
}

void Menu::Update( sf::Time elapsed_time ) {
    Update();
}

Menu::Menu_result Menu::Get_result() {
    return m_result;
}
