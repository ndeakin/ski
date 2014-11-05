#ifndef _TIME_DIGIT_HPP
#define _TIME_DIGIT_HPP

class Time_digit : public Visible_game_digit {
  public:
    Time_digit( Game * game,
                std::string name,
                sf::IntRect rect );

  private:
    sf::IntRect m_rect;
};

#endif // !_TIME_DIGIT_HPP
