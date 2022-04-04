#ifndef RTWEEKEND_HPP
# define RTWEEKEND_HPP

# include <cmath>
# include <limits>
# include <memory>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double	infinity = std::numeric_limits<double>::infinity();
const double	pi = 3.1415926535897932385;

inline double degree_to_radian(double degree)
{ return (degree * pi / 180.0); };

# include "ray.hpp"
# include "vec3.hpp"

#endif