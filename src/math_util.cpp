#include <math_util.hpp>

namespace Util {

sf::Vector2f Get_perpendicular_v2f( sf::Vector2f vec ) {
  sf::Vector2f  perp_vec( 0, 0 );
  // rotate clockise by 90 degrees
  perp_vec.x = vec.y;
  perp_vec.y = -vec.x;
  return perp_vec;
}

} // namespace Util
