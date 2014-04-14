#include "menu.hpp"

#include <SFML/Graphics.hpp>

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
    }
}

void Menu::Update( sf::Time elapsed_time ) {
    Update();
}

Menu::Menu_result Menu::Get_result() {
    return m_result;
}
