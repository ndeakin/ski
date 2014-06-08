#include <math.h>

#include "math_util.hpp"
#include "skier.hpp"
#include "skier_sprites.hpp"
#include "visible_game_object.hpp" 

Skier::Skier( char const * name )
    : Moving_game_object( name ),
      m_velocity( 0.0f, 0.0f ),
      // TODO: verify a value for terminal velocity, and impliment
      // some sort of wind resisitance in the form of approaching
      // terminal velocity.
      m_terminal_velocity( 0.55f ),
      m_run_time( sf::seconds( 0.0f ) )
{
    Load();
    Get_sprite().setTextureRect( Sprites::SKIER_CARVE_270 );
}

Skier::~Skier() {}

sf::Time Skier::Get_run_time() {
    return m_run_time;
}

void Skier::Update( sf::Time elapsed_time ) {
    m_run_time += elapsed_time;

    Update_velocity( elapsed_time );
    Update_sprite( elapsed_time );
}

void Skier::Update_velocity( sf::Time elapsed_time ) {
  
    // This multiplier acts as a general physics speed modifier.
    // All other similar multiplying values behave as relative intensities
    // compared to other physics effects
    long double amount = elapsed_time.asMicroseconds() / 10000.0f;

    // increase lateral velocity by 'amount' if the right or left arrow key
    // is being pressed.  Decrease vertical (downward) velocity by amount
    // if the up arrow is pressed.

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) ) {
        // turn right
        m_velocity += Util::Get_perpendicular_v2f( m_velocity, amount / 30.0f );
    } else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) ) {
        // turn left.
        m_velocity -= Util::Get_perpendicular_v2f( m_velocity, amount / 30.0f );
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) ) {
        // slow down...
        m_velocity.y /= 1.0f + amount / 20.0f;
    
        // ... but not too much
        if( m_velocity.y < 0.0f ) {
            m_velocity.y = 0.0f;
        }
        // friction:
        m_velocity.x /= 1.0f + amount / 20.0f;
    }
    #if 0
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) ) {
        // Nothing curently
    }
    #endif

    // gravity
    m_velocity.y += amount * 2 / 980.6f;

    Normalize_velocity();
}

void Skier::Normalize_velocity() {
    long double velocity_squared = pow( m_velocity.x, 2 ) + pow( m_velocity.y, 2 ); 
    if( velocity_squared > pow( m_terminal_velocity, 2 ) ) {
        float v_ratio = pow( m_terminal_velocity, 2 ) / velocity_squared;
        m_velocity.x *= v_ratio;
        m_velocity.y *= v_ratio;
    }
}

// Each of the Sprite_angle enum values is equal to:
//          tan( velocity.x / velocity.y )
// for velocity corresponding to a vector with the angle in the
// Sprite_angle's name.
//  Ex. If placed with its tail at the origin of a typical cartesian grid,
//      the head of the vector that correspond to SLOPE_7_5 would be just
//      above the positive X-axis. The  head of SLOPE_187_5 would be just
//      below the negative X-axis.
//
// The exact values of the enum are different from what one might expect
// since x and y values in SFML correspond to an offset from the top left
// corner of the object or image in question. Therefore, the actual
// cartesian grid overlaid on an image in 'SFML space' is that of a typical
// cartesian grid mirrored about its X-axis:
//
//                  negative y
//
//                      |
//                      |
//                      |
//    negative x  ------+------  positive x
//                      |
//                      |
//                      |
//
//                  positive y
//
struct Skier::Sprite_angle {
    static float const SLOPE_157_5 = 2.414213;
    static float const SLOPE_172_5 = 7.595754;
    // 180 - straight left
    static float const SLOPE_187_5 = -7.595754;
    static float const SLOPE_202_5 = -2.414213;
    static float const SLOPE_217_5 = -1.303225;
    static float const SLOPE_247_5 = -0.414213;
    // 270 - straight down
    static float const SLOPE_292_5 = 0.414213;
    static float const SLOPE_322_5 = 1.303225;
    static float const SLOPE_337_5 = 2.414213;
    static float const SLOPE_352_5 = 7.595754;
    // 0/360 - straight right
    static float const SLOPE_7_5 =   -7.595754;
    static float const SLOPE_22_5 =  -2.414213;
};

void Skier::Update_sprite( sf::Time elapsed_time ) {
    // Note: This math is a little weird due to our sprite angles
    //       being based on a typical cartesian grid whereas SFML's
    //       image grid being a typical grid mirrored about the X-axis.
  
    if( m_velocity.y == 0 ) {
        if( m_velocity.x > 0 ) {
            // Facing straight right
            Get_sprite().setTextureRect( Sprites::SKIER_CARVE_0 );
        } else if( m_velocity.x < 0 ){
            // Facing straight left
            Get_sprite().setTextureRect( Sprites::SKIER_CARVE_180 );
        }
    } else {
        float slope = m_velocity.x / m_velocity.y;

        if( m_velocity.y >= 0 ) {
            // Angle is between 180 and 360 on normal cartesion grid

            if( slope >= Sprite_angle::SLOPE_352_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_0 );
            } else if( slope >= Sprite_angle::SLOPE_337_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_345 );
            } else if( slope >= Sprite_angle::SLOPE_322_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_330 );
            } else if( slope >= Sprite_angle::SLOPE_292_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_315 );
            } else if( slope <= Sprite_angle::SLOPE_187_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_180 );
            } else if( slope <= Sprite_angle::SLOPE_202_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_195 );
            } else if( slope <= Sprite_angle::SLOPE_217_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_210 );
            } else if( slope <= Sprite_angle::SLOPE_247_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_225 );
            } else {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_270 );
            }
        } else {
            // Angle is between 0 and 180 on normal cartesian grid
    
            if( slope >= Sprite_angle::SLOPE_172_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_180 );
            } else if( slope >= Sprite_angle::SLOPE_157_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_165 );
            } else if( slope <= Sprite_angle::SLOPE_7_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_0 );
            } else if( slope <= Sprite_angle::SLOPE_22_5 ) {
                Get_sprite().setTextureRect( Sprites::SKIER_CARVE_15 );
            } else {
                // Already took care of cases where slope = 0
                if( slope > 0.0f ) {
                    Get_sprite().setTextureRect( Sprites::SKIER_CARVE_150 );
                } else {
                    Get_sprite().setTextureRect( Sprites::SKIER_CARVE_30 );
                }
            }
        }
    }

    float elapsed_time_ms = elapsed_time.asMicroseconds() / 1000.0f;
  
    Move( m_velocity.x * elapsed_time_ms, m_velocity.y * elapsed_time_ms );
}
