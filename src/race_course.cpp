#include "race_course.hpp"

Race_course::Race_course()
    : Moving_game_object( "Race Course" ),
      m_distance_travelled( 0.0f ),
      m_num_gates( 0 )
{
    // Y-start value is increased by 450; this 450 is the amount down
    // the screen that the skier starts.
    // TODO: make this 450 a static const somewhere
    m_gates.push_back( new Gate( "Course_gate_1", Gate::RED,
                       850, 450 + 400 ) );
    m_gates.push_back( new Gate( "Course_gate_2", Gate::BLUE,
                       750, 450 + 800 ) );
    m_gates.push_back( new Gate( "Course_gate_3", Gate::RED,
                       900, 450 + 1200 ) );
    m_gates.push_back( new Gate( "Course_gate_4", Gate::BLUE,
                       700, 450 + 1600 ) );
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
    if(  ( m_distance_travelled - 450 ) / 400 > m_num_gates - 2 ) {
        char name_string[16];
        snprintf( name_string, 16, "Course_gate_%i", ++m_num_gates );
        m_gates.push_back( new Gate( name_string,
                                     m_num_gates % 2 == 0 ? Gate::BLUE : Gate::RED,
                                     m_num_gates % 2 == 0 ? 700 : 900,
                                     1200 )  );
        delete *m_gates.begin();
        m_gates.erase( m_gates.begin() );
    }
}

void Race_course::Move( float x, float y, bool manager_should_handle ) {
    m_distance_travelled -= y;
}
