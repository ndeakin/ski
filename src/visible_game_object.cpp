#include <string>

#include "error.hpp"
#include "game.hpp"
#include "game_object_manager.hpp"
#include "sprites.hpp"
#include "visible_game_object.hpp"

Visible_game_object::Visible_game_object( Game * game, std::string name )
    : m_manager( &game->Get_game_object_manager() ),
      m_filename( "" ),
      m_is_responsible_for_texture( false ),
      m_is_loaded( false ),
      m_name( name )
{
    m_manager->Add( m_name.c_str(), this );
}

Visible_game_object::~Visible_game_object() {
    m_manager->Remove( m_name );
    if( m_is_responsible_for_texture ) {
        delete m_texture;
    }
}

// Default filename is "", which will load from the Ski_sprite_sheet instead
void Visible_game_object::Load( std::string filename ) {
    if( filename != "" ) {
        m_texture = new sf::Texture();
        if( m_texture == NULL ) {
            Assert( false, EC_VISIBLE_GAME_OBJECT_TEXTURE_LOAD_FAILURE );
            return;
        }

        m_is_responsible_for_texture = true;

        if( m_texture->loadFromFile( filename ) == false ) {
            m_filename = "";
            m_is_loaded = false;
        } else {
            m_filename = filename;
            m_sprite.setTexture( *m_texture, true );
            m_is_loaded = true;
        }
    } else {
        m_filename = "";
        m_sprite.setTexture( Sprites::Ski_sprite_sheet );
        m_is_loaded = true;
    }
}

void Visible_game_object::Draw( sf::RenderWindow & render_window ) {
    if( m_is_loaded ) {
        render_window.draw( m_sprite );
    }
}

void Visible_game_object::Update( sf::Time elapsed_time ) {

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

void Visible_game_object::Move( float x, float y ) {
    if( m_is_loaded ) {
        m_sprite.move( x, y );
    }
}

sf::Sprite & Visible_game_object::Get_sprite() {
    return m_sprite;
}

bool Visible_game_object::Is_loaded() const {
    return m_is_loaded;
}

float Visible_game_object::Get_height() const {
    return m_sprite.getTextureRect().height;
}

float Visible_game_object::Get_width() const {
    return m_sprite.getTextureRect().width;
}

sf::Rect< float > Visible_game_object::Get_bounding_rect() const {
    sf::Vector2u size = m_texture->getSize();
    sf::Vector2f position = m_sprite.getPosition();

    return sf::Rect< float >(
        position.x - size.x / 2,
        position.y - size.y / 2,
        position.x + size.x / 2,
        position.y + size.y / 2 );
}
