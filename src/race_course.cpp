#include "game.hpp"
#include "race_course.hpp"

static const unsigned int NEW_GATE_SPAWN_Y = 1200;

Race_course::Race_course()
    : Moving_game_object( "Race Course" ),
      m_distance_travelled( 0.0f ),
      m_num_gates( 0 ),
      m_horizontal_course_center( 800 ),
      m_gate_separation_y( 400 ),
      m_gate_amplitude_x( 100 )
{
    // Y-start value is increased by 450; this 450 is the amount down
    // the screen that the skier starts.
    m_gates.push_back( new Gate( "Course_gate_1", Gate::RED,
                       m_horizontal_course_center + 50, Game::SKIER_START_Y + 400 ) );
    m_gates.push_back( new Gate( "Course_gate_2", Gate::BLUE,
                       m_horizontal_course_center - 50, Game::SKIER_START_Y + 800 ) );
    m_gates.push_back( new Gate( "Course_gate_3", Gate::RED,
                       m_horizontal_course_center + 100, Game::SKIER_START_Y + 1200 ) );
    m_gates.push_back( new Gate( "Course_gate_4", Gate::BLUE,
                       m_horizontal_course_center - 100, Game::SKIER_START_Y + 1600 ) );
    m_num_gates += 4;
}

Race_course::~Race_course() {
    for( std::vector< Gate * >::iterator gate_it = m_gates.begin();
         gate_it != m_gates.end();
         ++gate_it )
    {
        delete *gate_it;
    }
}

void Race_course::Update( sf::Time elapsed_time ) {
    // TODO: change how this m_gate_separation_y is used if we want to be able to
    //       change it during the course's lifetime.
    if(  ( m_distance_travelled - Game::SKIER_START_Y ) / m_gate_separation_y >
         m_num_gates - 2 )
    {
        char name_string[16];
        snprintf( name_string, 16, "Course_gate_%i", ++m_num_gates );
        m_gates.push_back( new Gate( name_string,
                                     m_num_gates % 2 == 0 ? Gate::BLUE : Gate::RED,
                                     m_horizontal_course_center + 100 -
                                     ( m_num_gates % 2 == 0 ? 200 : 0 ),
                                     NEW_GATE_SPAWN_Y )  );
        delete *m_gates.begin();
        m_gates.erase( m_gates.begin() );
    }
}

void Race_course::Move( float x, float y, bool manager_should_handle ) {
    m_distance_travelled -= y;
}
