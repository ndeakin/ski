#include "error.hpp"
#include "sprites.hpp"

namespace Sprites {

sf::Texture Ski_sprite_sheet = sf::Texture();

void Initialize_sprite_sheet()
{
    Assert( Ski_sprite_sheet.loadFromFile( "images/skiing_sprite_sheet.png" ),
            FE_SPRITE_SHEET_LOAD_FAILURE );
}

} // namespace Sprites
