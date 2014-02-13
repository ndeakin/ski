#include "math_util.hpp"

namespace Util {

sf::Vector2f Get_perpendicular_v2f( sf::Vector2f vec, float mult ) {
  sf::Vector2f  perp_vec( 0, 0 );
  // Rotate clockise by 90 degrees.
  // Apply multiplier if required.
  perp_vec.x = vec.y * mult;
  perp_vec.y = -vec.x * mult;
  return perp_vec;
}

} // namespace Util
