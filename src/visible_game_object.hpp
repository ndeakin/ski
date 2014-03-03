#ifndef _VISIBLE_GAME_OBJECT_HPP
#define _VISIBLE_GAME_OBJECT_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

class Visible_game_object {
  public:
    Visible_game_object( std::string name );
    virtual ~Visible_game_object();

    virtual void Load( std::string filename );
    virtual void Draw( sf::RenderWindow & window );
    virtual void Update( sf::Time elapsed_time );

    virtual void Set_position( float x, float y );
    virtual sf::Vector2f Get_position() const;
    virtual bool Is_loaded() const;

    virtual void Move( float x, float y );

    virtual float Get_width() const;
    virtual float Get_height() const;
    virtual sf::Rect< float > Get_bounding_rect() const;

    std::string Get_name() const   { return m_name; }

  protected:
    sf::Sprite & Get_sprite();

  private:
    sf::Sprite  m_sprite;
    sf::Texture m_texture;
    std::string m_filename;
    bool        m_is_loaded;
    std::string m_name;
};

#endif // _VISIBLE_GAME_OBJECT_HPP
