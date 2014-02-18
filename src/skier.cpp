#include <math.h>

#include "math_util.hpp"
#include "skier.hpp"
#include "skier_sprites.hpp"
#include "visible_game_object.hpp" 

Skier::Skier()
  : m_velocity( 0.0f, 0.0f ),
    // TODO: verify a value for terminal velocity, and impliment
    // some sort of wind resisitance in the form of approaching
    // terminal velocity.
    m_terminal_velocity( 0.45f )
{
  Load( "images/skiing_sprite_sheet.png" );
  Get_sprite().setTextureRect( Sprites::SKIER_CARVE_270 );
}

Skier::~Skier() {}

void Skier::Update( sf::Time elapsed_time ) {
  
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
  m_velocity.y += amount / 980.6f;

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

void Skier::Update_sprite( sf::Time elapsed_time ) {
  // Note: This math is a little weird due to our sprite angles
  //       being based on a typical cartesian grid whereas SFML's
  //       image grid being a typical grid mirrored about the axis.
  
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
      } else if( slope <= Sprite_angle::SLOPE_247_5 ) {
        Get_sprite().setTextureRect( Sprites::SKIER_CARVE_225 );
      } else if( slope <= Sprite_angle::SLOPE_207_5 ) {
        Get_sprite().setTextureRect( Sprites::SKIER_CARVE_210 );
      } else if( slope <= Sprite_angle::SLOPE_202_5 ) {
        Get_sprite().setTextureRect( Sprites::SKIER_CARVE_195 );
      } else if( slope <= Sprite_angle::SLOPE_187_5 ) {
        Get_sprite().setTextureRect( Sprites::SKIER_CARVE_180 );
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
  
  Get_sprite().move( m_velocity.x * elapsed_time_ms,
                     m_velocity.y * elapsed_time_ms );
  
  // TODO: remove this once proper graphics are implemented;
  // only here for testing
  if( Get_sprite().getPosition().y > 900 ) {
    Get_sprite().setPosition( Get_sprite().getPosition().x, 0 );
  }
}
