#include "race_course.hpp"

Race_course::Race_course()
    : Moving_game_object( "Race Course" ),
      m_distance_travelled( 0.0f ),
      m_num_gates( 0 )
{
    m_gates.push_back( new Gate( "Course_gate_1", Gate::RED, 400, 600 ) );
    m_gates.push_back( new Gate( "Course_gate_2", Gate::BLUE, 300, 1100 ) );
    m_gates.push_back( new Gate( "Course_gate_3", Gate::RED, 400, 1600 ) );
    m_num_gates += 3;
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
    if(  m_distance_travelled / 500 > m_num_gates - 1 ) {
        char name_string[16];
        snprintf( name_string, 16, "Course_gate_%i", ++m_num_gates );
        m_gates.push_back( new Gate( name_string,
                                     m_num_gates % 2 == 0 ? Gate::BLUE : Gate::RED,
                                     m_num_gates % 2 == 0 ? 300 : 400,
                                     1100 )  );
        delete *m_gates.begin();
        m_gates.erase( m_gates.begin() );
    }
}

void Race_course::Move( float x, float y, bool manager_should_handle ) {
    m_distance_travelled -= y;
}
