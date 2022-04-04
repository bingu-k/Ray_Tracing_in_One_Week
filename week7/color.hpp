#ifndef COLOR_HPP
# define COLOR_HPP

# include "vec3.hpp"
# include "rtweekend.hpp"

using color = vec3; // 색표현

void	write_color(std::ostream &os, color pixel_color, int samples_per_pixel)
{
	double	scale = 1.0 / samples_per_pixel;
	double	r = pixel_color.x() * scale;
	double	g = pixel_color.y() * scale;
	double	b = pixel_color.z() * scale;

	os	<< static_cast<int>(255.999 * clamp(r, 0.0, 0.999)) << ' '
		<< static_cast<int>(255.999 * clamp(g, 0.0, 0.999)) << ' '
		<< static_cast<int>(255.999 * clamp(b, 0.0, 0.999)) << ' ' << std::endl;
};

#endif