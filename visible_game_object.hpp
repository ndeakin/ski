#pragma once

class Visible_game_object {
 public:
  Visible_game_object();
  virtual ~Visible_game_object();

  virtual void Load( std::string filename );
  virtual void Draw( sf::RenderWindow & window );
  virtual void Update( float elapsed_time );

  virtual void Set_position( float x, float y );
  virtual sf::Vector2f Get_position() const;
  virtual bool Is_loader() const;

  virtual float Get_width() const;
  virtual float Get_height() const;
  virtual sf::Rect< float > Get_bounding_rect() const;

 protected:
  sf::Sprite & Get_sprite();

 private:
  sf::Sprite  m_sprite;
  sf::Image   m_image;
  std::string m_filename;
  bool        m_is_loaded;
};
