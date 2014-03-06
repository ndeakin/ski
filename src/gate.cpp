#include "gate.hpp"
#include "gate_sprites.hpp"

Lone_gate::Lone_gate( std::string name, Colour::Colour colour, float x, float y,
           bool x_coord_is_left_side )
    : Moving_game_object( name ),
      m_colour( colour ),
      m_x_coord_is_left_side( x_coord_is_left_side )
{
    Load();
    switch( colour ) {
        case Colour::RED:
            Get_sprite().setTextureRect( Sprites::GATE_RED_NORMAL );
            break;

        case Colour::BLUE:
            Get_sprite().setTextureRect( Sprites::GATE_BLUE_NORMAL );
            break;
    }
    Set_position( x, y );
}

Lone_gate::~Lone_gate() {

}

void Lone_gate::Update( sf::Time elapsed_time ) {

}

Gate::Gate( std::string name, Colour::Colour colour, float x, float y,
            bool x_coord_is_left_side )
    : Moving_game_object( name ),
      m_left_gate_x( x_coord_is_left_side ? x : x - GATE_WIDTH ),
      m_right_gate_x( x_coord_is_left_side ? x + GATE_WIDTH : x ),
      m_left_gate( name.append( " left gate" ), colour,
                   m_left_gate_x, y, x_coord_is_left_side ),
      m_right_gate( name.append( " right gate" ), colour,
                    m_right_gate_x, y, x_coord_is_left_side ),
      m_colour( colour ),
      m_x_coord_is_left_side( x_coord_is_left_side )
{}

Gate::~Gate() {

}

void Gate::Set_position( float x, float y ) {
    m_left_gate.Set_position( m_x_coord_is_left_side ? x : x - GATE_WIDTH, y );
    m_right_gate.Set_position( m_x_coord_is_left_side ? x + GATE_WIDTH : x, y );
}

void Gate::Update( sf::Time elapsed_time ) {
    
}
