#ifndef _MENU_HPP
#define _MENU_HPP

#include "visible_game_object.hpp"

class Game;

class Button : public Visible_game_object {
  public:
    Button( Game * game, std::string name,
            sf::IntRect normal_rect, sf::IntRect hover_rect );

    void Hover();
    void Unhover();

  private:
    sf::IntRect m_normal_rect;
    sf::IntRect m_hover_rect;

    bool        m_is_hovering;
};

class Menu : public Visible_game_object {
  public:
    enum Menu_result {
        UNDECIDED,
        PLAY,
        EXIT,
    };

    Menu( Game * game, std::string name );

    ~Menu();

    // Update( sf::Time ) would be called by the game object manager, but the
    // manager will not normally be doing anything at the times that the menu
    // is shown.  For this reason, Update( sf::Time ) only calls Update(), in
    // case that the game object manager is ever desired to call
    // Update( sf::Time ), but currently it is expected that the creater of the
    // menu will call Update() as appropriate.
    void Update();
    void Update( sf::Time elapsed_time );

    Menu_result Get_result();

  private:
    Menu_result m_result;

    Button *    m_play_button;
    Button *    m_exit_button;
};

#endif // !_MENU_HPP
