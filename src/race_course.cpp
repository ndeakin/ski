#include "colour.hpp"
#include "game.hpp"
#include "race_course.hpp"

static const unsigned int NEW_GATE_SPAWN_Y = 1200;

Race_course::Race_course()
    : Moving_game_object( "Race Course" ),
      m_distance_travelled( 0.0f ),
      m_num_gates( 0 ),
      m_course_length( 0 ),
      m_gates_passed( 0 ),
      m_horizontal_course_center( 800 ),
      m_gate_separation_y( 400 ),
      m_gate_amplitude_x( 100 ),
      m_next_gate_index( 0 )
{
    // TODO: Initial gates would ideally depend on screen height.
    //       This would mean only making as many gates as required to cover the
    //       screen height.  However, this would be significantly more work for
    //       a pretty small gain, so it has not been done yet. This change
    //       would also require changes to Race_course::Update().
    m_gates.push_back( new Gate( "Course_gate_1", Colour::RED,
                       m_horizontal_course_center + 50, Game::SKIER_START_Y + 400,
                       true ) );
    m_gates.push_back( new Gate( "Course_gate_2", Colour::BLUE,
                       m_horizontal_course_center - 50, Game::SKIER_START_Y + 800,
                       false ) );
    m_gates.push_back( new Gate( "Course_gate_3", Colour::RED,
                       m_horizontal_course_center + 100, Game::SKIER_START_Y + 1200,
                       true ) );
    m_gates.push_back( new Gate( "Course_gate_4", Colour::BLUE,
                       m_horizontal_course_center - 100, Game::SKIER_START_Y + 1600,
                       false ) );
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
        if( m_num_gates < m_course_length ) {
            char name_string[16];
            snprintf( name_string, 16, "Course_gate_%i", ++m_num_gates );
            m_gates.push_back( new Gate( name_string,
                                         m_num_gates % 2 == 0 ? Colour::BLUE : Colour::RED,
                                         m_horizontal_course_center + 100 -
                                         ( m_num_gates % 2 == 0 ? 200 : 0 ),
                                         NEW_GATE_SPAWN_Y,
                                         // if odd number,
                                         // then x_coord_is_left_side is true
                                         m_num_gates % 2 != 0 ? true : false )  );
            delete *m_gates.begin();
            m_gates.erase( m_gates.begin() );

            if( m_next_gate_index != 0 ) {
                --m_next_gate_index;
            } else {
                Increment_next_gate();
            }
        }
    }
}

void Race_course::Move( float x, float y, bool manager_should_handle ) {
    m_distance_travelled -= y;
}

Gate const * Race_course::Get_next_gate() const {
    return const_cast< Gate const * > ( m_gates[m_next_gate_index] );
}

bool Race_course::Increment_next_gate() {
    ++m_gates_passed;

    if( m_gates.size() < 2 ) {
        m_next_gate_index = 0;
        return false;
    }

    size_t next_index = 0;

    for( size_t index = 1; index < m_gates.size(); ++index ) {
        if( index == m_next_gate_index ||
            m_gates[index]->Get_height() <
            m_gates[m_next_gate_index]->Get_height() )
        {
            continue;
        }
        if( next_index == m_next_gate_index ||
            m_gates[next_index]->Get_height() <
            m_gates[m_next_gate_index]->Get_height() ||
            m_gates[index]->Get_height() <
            m_gates[next_index]->Get_height() )
        {
            next_index = index;
        }
    }

    m_next_gate_index = next_index;
    
    if( m_gates_passed >= m_course_length ) {
        return true;
    }
    return false;
}
