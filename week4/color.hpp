#ifndef COLOR_HPP
# define COLOR_HPP

# include "vec3.hpp"

using color = vec3; // 색표현

void	write_color(std::ostream &os, color pixel_color)
{
	os	<< static_cast<int>(255.999 * pixel_color.x()) << ' '
		<< static_cast<int>(255.999 * pixel_color.y()) << ' '
		<< static_cast<int>(255.999 * pixel_color.z()) << ' ' << std::endl;
};

#endif