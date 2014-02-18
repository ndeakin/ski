#include "math_util.hpp"

namespace Util {

sf::Vector2< long double > Get_perpendicular_v2f( sf::Vector2< long double > vec,
                                                  float mult ) {
  sf::Vector2< long double >  perp_vec( 0, 0 );
  // Rotate clockise by 90 degrees.
  // Apply multiplier if required.
  perp_vec.x = vec.y * mult;
  perp_vec.y = -vec.x * mult;
  return perp_vec;
}

} // namespace Util
