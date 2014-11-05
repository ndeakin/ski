#include "time_digit.hpp"

#include <SFML/Graphics.hpp>

Time_sprite::Time_sprite( Game * game,
                          std::string name,
                          sf::IntRect rect )
    : Visible_game_object( game, name ),
      m_rect( rect )
{
    Load( "images/time_digits.png" );
    Get_sprite().setTextureRect( m_rect );
}
