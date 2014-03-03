#ifndef _RACE_COURSE_HPP
#define _RACE_COURSE_HPP

#include "gate.hpp"
#include "moving_game_object.hpp"

class Race_course : public Moving_game_object {
  private:
    // List of gates belonging to the course
    std::vector< Gate * >   m_gates;
    
    // Vertical distance traveled, so the course knows when to add more gates.
    long double m_distance_travelled;

    // Number of gates the course has made so far
    unsigned int    m_num_gates;

  public:
    Race_course();
    ~Race_course();
    
    void Update( sf::Time elapsedd_time );
    void Move( float x, float y, bool manager_shold_handle = true ); 
};

#endif // !_RACCE_COURSE_HPP
