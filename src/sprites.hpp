#ifndef _SPRITES_HPP
#define _SPRITES_HPP

#include <SFML/Graphics.hpp>

namespace Sprites {

    // Global sprite sheet resource (so multiple sprites don't load the sprite
    // sheet multiple times).
    extern sf::Texture Ski_sprite_sheet;

    // Must be called before using the above.
    void Initialize_sprite_sheet();

} // namespace Sprites

#endif // !_SPRITES_HPP
