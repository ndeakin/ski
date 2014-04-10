#include "game.hpp"
#include "game_object_manager.hpp"

Game_object_manager::Game_object_manager() {
    
}

Game_object_manager::~Game_object_manager() {
    std::for_each( m_game_objects.begin(),
                   m_game_objects.end(),
                   Game_object_deallocator() );
}

void Game_object_manager::Add( std::string name, Visible_game_object * game_object ) {
    m_game_objects.insert( std::pair< std::string, Visible_game_object * >( 
                                      name,        game_object ) );
}

void Game_object_manager::Remove( std::string name ) {
    m_game_objects.erase( m_game_objects.find( name ) );
}

Visible_game_object * Game_object_manager::Get( std::string name ) const {
    std::map< std::string, Visible_game_object * >::const_iterator results = 
            m_game_objects.find( name );
    if( results == m_game_objects.end() ) {
        return NULL;
    } else {
        return results->second;
    }
}

void Game_object_manager::Draw_all( sf::RenderWindow & render_window ) {
    std::map< std::string, Visible_game_object * >::const_iterator itr = 
            m_game_objects.begin();

    while( itr != m_game_objects.end() ) {
        itr->second->Draw( render_window );
        ++itr;
    }
}

void Game_object_manager::Update_all( Game & game, sf::Time delta_time ) {
  
    if( game.Get_game_state() != Game::PLAYING ) {
        return;
    }
    std::map< std::string, Visible_game_object * >::const_iterator itr =
            m_game_objects.begin();
  
    // Currently doing timing ourself, but might want this instead at some point
    #if 0
        game.Get_window().getFrameTime();
    #endif

    while( itr != m_game_objects.end() ) {
        itr->second->Update( delta_time );
        itr++;
    }
    
    game.Update_gate_keeping();
}

