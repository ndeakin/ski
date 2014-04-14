#ifndef _MENU_HPP
#define _MENU_HPP

#include "visible_game_object.hpp"

class Menu : public Visible_game_object {
  public:
    enum Menu_result {
        UNDECIDED,
        PLAY,
        EXIT,
    };

    Menu( Game * game, std::string name );

    // Update( sf::Time ) would be called by the game object manager, but the
    // manager will not normally be doing anything at the times that the menu
    // is shown.  For this reason, Update( sf::Time ) only calls Update(), in
    // case that the game object manager is ever desired to call
    // Update( sf::Time ), but currently it is expected that the creater of the
    // menu will call Update() as appropriate.
    void Update();
    void Update( sf::Time elapsed_time );

    void Show_in( sf::RenderWindow & render_window );

    Menu_result Get_result();

  private:
    Menu_result m_result;
};

#endif // !_MENU_HPP
