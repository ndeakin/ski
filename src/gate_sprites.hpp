#ifndef _GATE_SPRITES_HPP
#define _GATE_SPRITES_HPP

namespace Sprites {

    // Gate class sprite locations

    // Format:
    //
    // sf::IntRect GATE_<COLOUR>_<TYPE>(  Left, Top, Width, Height );
    //
    //  All argument values to the IntRect constructor are in pixels.

    const sf::IntRect GATE_RED_NORMAL(  6,    1073,   33,   50 );
    const sf::IntRect GATE_BLUE_NORMAL( 246,  1073,   33,   50 );

} // namespace Sprites

#endif // !_GATE_SPRITES_HPP
