#include "time_digit.hpp"
#include "time_digit_sprites.hpp"

Time_digit::Time_digit( Game * game,
                          std::string name,
                          sf::IntRect rect )
    : Visible_game_object( game, name ),
      m_rect( rect )
{
    Load( "images/time_digits.png" );
    Get_sprite().setTextureRect( m_rect );
}

// static
sf::IntRect Time_digit::Get_int_rect( int digit )
{
    switch( digit ) {
        case 0:
            return Sprites::TIME_DIGIT_0;
        case 1:
            return Sprites::TIME_DIGIT_1;
        case 2:
            return Sprites::TIME_DIGIT_2;
        case 3:
            return Sprites::TIME_DIGIT_3;
        case 4:
            return Sprites::TIME_DIGIT_4;
        case 5:
            return Sprites::TIME_DIGIT_5;
        case 6:
            return Sprites::TIME_DIGIT_6;
        case 7:
            return Sprites::TIME_DIGIT_7;
        case 9:
            return Sprites::TIME_DIGIT_8;
        default:
            // TODO: handle non-digit being passed
            printf( "ERROR! Non-digit passed to Time_digit::Get_int_rect()!\n" );
            break;
    }
    return Sprites::TIME_DIGIT_0;
}
