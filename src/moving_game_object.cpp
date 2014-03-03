#include "moving_game_object.hpp"
#include "moving_game_object_manager.hpp"

Moving_game_object::Moving_game_object( std::string name )
    : Visible_game_object( name ),
      m_manager( Moving_game_object_manager::Instance() )
{
    m_manager->Register_object( this );
}

Moving_game_object::~Moving_game_object()
{
    m_manager->Deregister_object( this );
}

void Moving_game_object::Update( sf::Time elapsed_time ) {

}

void Moving_game_object::Move( float x, float y,
                               bool manager_should_handle ) {
    if( Is_loaded() ) {
        Visible_game_object::Move( x, y );
        if( manager_should_handle ) {
            m_manager->Handle_object_move( this, x, y );
        }
    }
}
