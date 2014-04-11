#ifndef _SPLASH_SCREEN_HPP
#define _SPLASH_SCREEN_HPP

#include <SFML/System/Time.hpp>

#include "visible_game_object.hpp"

class Game;

class Splash_screen : public Visible_game_object {
  private:
    sf::Sprite *    m_sprite;
    sf::Image *     m_image;

    bool            m_is_finished;

  public:
    Splash_screen( Game * game, std::string name );
    ~Splash_screen();

    void Update();
    void Update( sf::Time elapsed_time );

    bool Is_finished();
    void Show_in( sf::RenderWindow & render_window );
};

#endif // !_SPLASH_SCREEN_PP
