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

    // X-coordinate that the course is centered about.
    // TODO: currently this will just be the center of the screen, or some
    //       other fixed position, but in the future, this combined with the
    //       idea of an amplitude for the gates horizontal distance can be used
    //       to make a more varying course.
    const unsigned int  m_horizontal_course_center;

    // Vertical distance between neighboring gates, in pixels.
    // NOTE: this is const because the implementation is not ready for it to change
    const unsigned int m_gate_separation_y;
    // amplitude = separation / 2
    unsigned int m_gate_amplitude_x;

  public:
    Race_course();
    ~Race_course();

    void Update( sf::Time elapsedd_time );
    void Move( float x, float y, bool manager_shold_handle = true ); 
};

#endif // !_RACCE_COURSE_HPP
