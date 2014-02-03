#include <string>

#include "visible_game_object.hpp"


Visible_game_object::Visible_game_object()
  : m_is_loaded( false )
{}

Visible_game_object::~Visible_game_object() {}

void Visible_game_object::Load( std::string filename ) {
  if( m_texture.loadFromFile( filename ) == false ) {
    m_filename = "";
    m_is_loaded = false;
  } else {
    m_filename = filename;
    m_sprite.setTexture( m_texture );
    m_is_loaded = true;
  }
}

void Visible_game_object::Draw( sf::RenderWindow & render_window ) {
  if( m_is_loaded ) {
    render_window.draw( m_sprite );
  }
}

void Visible_game_object::Update( float elapsed_time ) {

}

void Visible_game_object::Set_position( float x, float y ) {
  if( m_is_loaded ) {
    m_sprite.setPosition( x, y );
  }
}

sf::Vector2f Visible_game_object::Get_position() const {
  if( m_is_loaded ) {
    return m_sprite.getPosition();
  }
  return sf::Vector2f();
}

sf::Sprite & Visible_game_object::Get_sprite() {
  return m_sprite;
}

bool Visible_game_object::Is_loaded() const {
  return m_is_loaded;
}

float Visible_game_object::Get_height() const {
  return m_texture.getSize().y;
}

float Visible_game_object::Get_width() const {
  return m_texture.getSize().x;
}

sf::Rect< float > Visible_game_object::Get_bounding_rect() const {
  sf::Vector2u size = m_texture.getSize();
  sf::Vector2f position = m_sprite.getPosition();

  return sf::Rect< float >(
    position.x - size.x / 2,
    position.y - size.y / 2,
    position.x + size.x / 2,
    position.y + size.y / 2 );
}