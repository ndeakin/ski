#ifndef _MATH_UTIL_HPP
#define _MATH_UTIL_HPP

#include <SFML/System/Vector2.hpp>

namespace Util {

// Return a perpendicular vector with equal magnitude;
// alwaus rotates the vector clockwise.
// Optional: second argument to multiply the magnitude of the vector by
sf::Vector2< long double > Get_perpendicular_v2f( sf::Vector2< long double > vec,
                                                  float mult = 1.0f );

} // namespace Util

#endif // !_MATH_UTIL_HPP
