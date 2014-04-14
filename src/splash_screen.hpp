#ifndef _SPLASH_SCREEN_HPP
#define _SPLASH_SCREEN_HPP

#include <SFML/System/Time.hpp>

#include "visible_game_object.hpp"

class Game;

class Splash_screen : public Visible_game_object {
  private:
    bool            m_is_finished;

  public:
    Splash_screen( Game * game, std::string name );

    // Update( sf::Time ) would be called by the game object manager, but the
    // manager will not normally be doing anything at the time that the splash
    // screen is shown.  For this reason, Update( sf::Time ) only calls
    // Update(), in case that the game object manager is ever desired to call
    // Update( sf::Time ), but currently it is expected that the creater of the
    // splash screen will call Update() as appropriate.
    void Update();
    void Update( sf::Time elapsed_time );

    bool Is_finished();
    void Show_in( sf::RenderWindow & render_window );
};

#endif // !_SPLASH_SCREEN_PP
