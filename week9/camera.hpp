#ifndef CAMEAR_HPP
# define CAMEAR_HPP

# include "vec3.hpp"
# include "ray.hpp"

using point3 = vec3;

class camera
{
public:
	double	_viewport_width;
	double	_viewport_height;
	double	_aspect_ratio;
	double	_focal_length;
	point3	_point;
	vec3	_normal;
	vec3	_horizontal;
	vec3	_vertical;
	vec3	_left_bottom_corner;
private:
	camera() {};
public:
	camera(int viewport_width, double aspect_ratio, point3 point, vec3 normal)
	: _viewport_width(viewport_width), _viewport_height(_viewport_width / aspect_ratio)
	, _aspect_ratio(aspect_ratio), _focal_length(1.0), _point(point), _normal(unit_vec3(normal))
	, _horizontal(), _vertical(), _left_bottom_corner()
	{
		_horizontal = unit_vec3(cross(_normal, vec3(0,1,0))) * _viewport_width;
		_vertical = unit_vec3(cross(_horizontal, _normal)) * _viewport_height;
		_left_bottom_corner = _point - ((_horizontal / 2) + (_vertical / 2) - (_normal * _focal_length));
	};
	~camera() {};

	ray	get_ray(double u, double v) const
	{ return (ray(_point, _left_bottom_corner + (_horizontal * u) + (_vertical * v) - _point)); };
};

std::ostream	&operator<<(std::ostream &os, camera const &cam)
{
	os	<< "viewport_width\t: " << cam._viewport_width << std::endl
		<< "viewport_height\t: " << cam._viewport_height << std::endl
		<< "aspect_ratio\t: " << cam._aspect_ratio << std::endl
		<< "focal_length\t: " << cam._focal_length << std::endl
		<< "point\t: " << cam._point
		<< "normal\t: " << cam._normal
		<< "horizontal\t: " << cam._horizontal
		<< "vertical\t: " << cam._vertical
		<< "left_bottom_corner\t: " << cam._left_bottom_corner;
	return (os);
};

#endif