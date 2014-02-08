#include "skier.hpp"
#include "visible_game_object.hpp"

Skier::Skier( sf::IntRect int_rect )
{
  Load( "images/skiing_sprite_sheet.png" );
  Get_sprite().setTextureRect( int_rect );
}

Skier::~Skier() {}

void Skier::Update( sf::Time elapsed_time ) {
  
  // moving a number of pixels equal to the number of ms that the button
  // is pressed.  This seems to work nicely; the rate of acceleration that the
  // skier receives can be adjusted by changing the multiplier of elapsed_time.
  // (The current multiplier is 1)
  double amount = elapsed_time.asMilliseconds();

  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) ) {
    Move( amount, 0.0f );
  }
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) ) {
    Move( -amount, 0.0f );
  }
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) ) {
    Move( 0.0f, -amount );
  }
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) ) {
    Move( 0.0f, amount );
  }
}

float Skier::Get_velocity() const {
  // TODO
  return 0.0f;
}
