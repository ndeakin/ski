#include "skier.hpp"
#include "visible_game_object.hpp"

Skier::Skier()
{
  Load( "images/skiing_sprite_sheet.png" ); 
}

Skier::~Skier() {}

void Skier::Update( float elapsed_time ) {
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) ) {
    Move( 1.0f, 0.0f );
  }
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) ) {
    Move( -1.0f, 0.0f );
  }
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) ) {
    Move( 0.0f, -1.0f );
  }
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) ) {
    Move( 0.0f, 1.0f );
  }
}

float Skier::Get_velocity() const {
  // TODO
  return 0.0f;
}
