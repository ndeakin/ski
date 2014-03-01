#include "gate.hpp"
#include "gate_sprites.hpp"

Gate::Gate( Colour colour, float x, float y ) {
    Load( "images/skiing_sprite_sheet.png" );
    switch( colour ) {
        case RED:
            Get_sprite().setTextureRect( Sprites::GATE_RED_NORMAL );
            break;

        case BLUE:
            Get_sprite().setTextureRect( Sprites::GATE_BLUE_NORMAL );
            break;
    }
    Set_position( x, y );
}

Gate::~Gate() {

}

void Gate::Update( sf::Time elapsed_time ) {
    
}
