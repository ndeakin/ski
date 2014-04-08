#ifndef _GATE_HPP
#define _GATE_HPP

#include <SFML/System/Time.hpp>

#include "colour.hpp"
#include "moving_game_object.hpp"

class Lone_gate : public Moving_game_object {
  public:
    // This is currently the width of the sprite, in pixels.
    // TODO: improve the detection of the edge of the gate relative to where
    //       it looks like it should be detected.
    static const unsigned   LONE_GATE_WIDTH = 33;

    // If x_coord_is_left_side is true, then the x-coordinate given is where
    // the left side of the gate is placed.  If it's false, then the right side
    // of the gate is placed at the x-coordinate given.
    Lone_gate( std::string name, Colour::Colour colour, float x, float y,
               bool x_coord_is_left_side = true );
    virtual ~Lone_gate();

    virtual void Update( sf::Time elapsed_time );

  private:
    Colour::Colour  m_colour;
    bool            m_x_coord_is_left_side;
};

class Gate : public Moving_game_object {
  public:
    // Width between the two Lone_gates of a Gate, in pixels
    static const unsigned   GATE_WIDTH = 300;

    // x_coord_is_left_side has the same effect as it does for lone gate.
    Gate( std::string name, Colour::Colour colour, float x, float y,
          bool x_coord_is_left_side = true );
    virtual ~Gate();

    void Set_position( float x, float y );
    void Update( sf::Time elapsed_time );

    float Get_height() const;
    sf::Vector2f Get_left_gate_position() const;
    sf::Vector2f Get_right_gate_position() const;

  private:
    unsigned        m_left_gate_x;
    unsigned        m_right_gate_x;

    Lone_gate       m_left_gate;
    Lone_gate       m_right_gate;

    Colour::Colour  m_colour;
    bool            m_x_coord_is_left_side;
};

#endif // !_GATE_HPP
