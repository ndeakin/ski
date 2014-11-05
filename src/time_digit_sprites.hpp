#ifndef _TIME_DIGIT_SPRITES_HPP
#define _TIME_DIGIT_SPRITES_HPP

// Note: The origin on the image is the top left corner.

namespace Sprites {
    // Time_digit class sprite locations

    // Format:
    // sf::IntRect TIME_DIGIT_#(  Left, Top, Width, Height );
    //
    // All argument values to the IntRect constructor are in pixels.

    const sf::IntRect TIME_DIGIT_0(        0,  0,  60, 75 );
    const sf::IntRect TIME_DIGIT_1(       65,  0,  55, 75 );
    const sf::IntRect TIME_DIGIT_2(      120,  0,  60, 75 );
    const sf::IntRect TIME_DIGIT_3(      175,  0,  60, 75 );
    const sf::IntRect TIME_DIGIT_4(      238,  0,  60, 75 );
    const sf::IntRect TIME_DIGIT_5(      295,  0,  60, 75 );
    const sf::IntRect TIME_DIGIT_6(      358,  0,  60, 75 );
    const sf::IntRect TIME_DIGIT_7(      419,  0,  60, 75 );
    const sf::IntRect TIME_DIGIT_8(      478,  0,  60, 75 );
    const sf::IntRect TIME_DIGIT_9(      538,  0,  60, 75 );
    const sf::IntRect TIME_DIGIT_PERIOD( 600,  0,  22, 75 );
    const sf::IntRect TIME_DIGIT_COLON(  632,  0,  23, 75 );
}

#endif // !_TIME_DIGIT_SPRITES_HPP
