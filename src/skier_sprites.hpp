#ifndef _SKIER_SPRITES_HPP
#define _SKIER_SPRITES_HPP

// Note: The origin on the image is the top left corner.

namespace Sprites {
    // Skier class sprite locations

    // Format:
    //
    // sf::IntRect SKIER_<TYPE>_?#(  Left, Top, Width, Height );
    //                          ^ is 'n' for negative angle, empty otherwise
    // '#' is the angle the skier is facing on a cartesion grid; 0 is straight right,
    // 90 would be straight up, 180 is straight left, and 270 is straight down.
    //
    //  All argument values to the IntRect constructor are in pixels.

    // Type is CARVE - slower carving series of skiers
    sf::IntRect SKIER_CARVE_150(  295,  120,  48,   41 );
    sf::IntRect SKIER_CARVE_165(  238,  122,  52,   39 );
    sf::IntRect SKIER_CARVE_180(  174,  125,  53,   37 );
    sf::IntRect SKIER_CARVE_195(  118,  120,  51,   41 );
    sf::IntRect SKIER_CARVE_210(  62,   119,  49,   42 );
    sf::IntRect SKIER_CARVE_225(  18,   120,  40,   42 );
    sf::IntRect SKIER_CARVE_270(  502,  70,   42,   43 );
    sf::IntRect SKIER_CARVE_315(  455,  72,   37,   41 );
    sf::IntRect SKIER_CARVE_330(  398,  71,   49,   42 );
    sf::IntRect SKIER_CARVE_345(  343,  73,   51,   41 );
    sf::IntRect SKIER_CARVE_0(    279,  76,   52,   37 );
    sf::IntRect SKIER_CARVE_15(   222,  74,   51,   40 );
    sf::IntRect SKIER_CARVE_30(   166,  71,   49,   42 );


    // don't need right now; will be part of some "pushing" set
    // sf::IntRect SKIER_PUSH_45( 60, 65, 55, 50 );
}

#endif // !_SKIER_SPRITES_HPP
