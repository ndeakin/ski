#include "menu.hpp"

#include <SFML/Graphics.hpp>

Button::Button( Game * game, std::string name,
                sf::IntRect normal_rect, sf::IntRect hover_rect )
    : Visible_game_object( game, name ),
      m_normal_rect( normal_rect ),
      m_hover_rect( hover_rect ),
      m_is_hovering( false )
{
    Load( "images/menu_buttons.png" );
    Get_sprite().setTextureRect( m_normal_rect );
}

void Button::Hover()
{
    if( !m_is_hovering ) {
        m_is_hovering = true;
        Get_sprite().setTextureRect( m_hover_rect );
    }
}

void Button::Unhover()
{
    if( m_is_hovering ) {
        m_is_hovering = false;
        Get_sprite().setTextureRect( m_normal_rect );
    }
}

// Button positions

static const int PLAY_LEFT = 100;
static const int PLAY_RIGHT = 370;
static const int PLAY_TOP = 100;
static const int PLAY_BOTTOM = 205;

static const sf::IntRect    PLAY_NORMAL_RECT( 0, 0, 270, 105 );
static const sf::IntRect    PLAY_HOVER_RECT( 0, 200, 270, 105 );

static const int EXIT_LEFT = 100;
static const int EXIT_RIGHT = 370;
static const int EXIT_TOP = 206;
static const int EXIT_BOTTOM = 300;

static const sf::IntRect    EXIT_NORMAL_RECT( 0, 105, 270, 95 );
static const sf::IntRect    EXIT_HOVER_RECT( 0, 305, 270, 95 );

Menu::Menu( Game * game, std::string name )
    : Visible_game_object( game, name ),
      m_result( UNDECIDED ),
      m_play_button( NULL ),
      m_exit_button( NULL )
{    
    Load( "images/menu_background.png" );
    
    m_play_button = new Button( game, "Play button", PLAY_NORMAL_RECT, PLAY_HOVER_RECT );
    // TODO: check for allocation failure
    m_play_button->Set_position( 100, 100 );
    
    m_exit_button = new Button( game, "Exit button", EXIT_NORMAL_RECT, EXIT_HOVER_RECT );
    // TODO: check for allocation failure
    m_exit_button->Set_position( 100, 205 );
}

Menu::~Menu()
{
    delete m_play_button;
    m_play_button = NULL;
    delete m_exit_button;
    m_exit_button = NULL;
}

void Menu::Update() {
    // Check for key presses
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) ) {
        m_result = PLAY;
        return;
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) ) {
        m_result = EXIT;
        return;
    }

    // TODO: make a button member function to see if mouse position is inside it
    // Check mouse position and clicking
    sf::Vector2i position = sf::Mouse::getPosition();
    if( position.x > PLAY_LEFT && position.x < PLAY_RIGHT &&
        position.y > PLAY_TOP && position.y < PLAY_BOTTOM )
    {
        m_play_button->Hover();
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) {
            m_result = PLAY;
        }
        m_exit_button->Unhover();
    } else if( position.x > EXIT_LEFT && position.x < EXIT_RIGHT &&
               position.y > EXIT_TOP && position.y < EXIT_BOTTOM )
    {
        m_exit_button->Hover();
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) {
            m_result = EXIT;
        }
        m_play_button->Unhover();
    } else {
        m_play_button->Unhover();
        m_exit_button->Unhover();
    }
}

void Menu::Update( sf::Time elapsed_time ) {
    Update();
}

Menu::Menu_result Menu::Get_result() {
    return m_result;
}
