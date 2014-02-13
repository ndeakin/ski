#include <math.h>

#include "math_util.hpp"
#include "skier.hpp"
#include "visible_game_object.hpp" 

Skier::Skier()
  : m_velocity( 0.0f, 0.0f ),
    m_terminal_velocity( 10.0f )
{
  Load( "images/skiing_sprite_sheet.png" );
  // TODO: change how default sprite on sheet is determined
  Get_sprite().setTextureRect( sf::IntRect( 60, 65, 55, 50 ) );
}

Skier::~Skier() {}

void Skier::Update( sf::Time elapsed_time ) {
  
  Update_velocity( elapsed_time );

  Update_sprite();

}

void Skier::Update_velocity( sf::Time elapsed_time ) {
  
  // This multiplier acts as a general physics speed modifier.
  // All other similar multiplying values behave as relative intensities
  // compared to other physics effects
  double amount = elapsed_time.asMilliseconds() / 1.0f;

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
    m_velocity.y -= amount / 100.0f;
    

    // ... but not too much
    if( m_velocity.y < 0.0f ) {
      m_velocity.y = 0.0f;
    }
    // friction:
    m_velocity.x /= 1.0f + amount / 10.0f;
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
  float velocity_squared = pow( m_velocity.x, 2 ) + pow( m_velocity.y, 2 ); 
  if( velocity_squared > pow( m_terminal_velocity, 2 ) ) {
    float v_ratio = pow( m_terminal_velocity, 2 ) / velocity_squared;
    m_velocity.x *= v_ratio;
    m_velocity.y *= v_ratio;
  }
}

void Skier::Update_sprite() {
  // TODO: later on, also adjust sprite used; ex change angle

  Get_sprite().move( m_velocity.x, m_velocity.y );
}
