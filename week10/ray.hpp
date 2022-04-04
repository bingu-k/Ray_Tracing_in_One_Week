#ifndef RAY_HPP
# define RAY_HPP

#include "vec3.hpp"

using point3 = vec3;

class ray
{
public:
	point3	_point;
	vec3	_normal;
private:
public:
	ray() {};
	ray(point3 const point, vec3 const normal) : _point(point), _normal(unit_vec3(normal))
	{};
	ray(ray const &origin) : _point(origin._point), _normal(origin._normal)
	{};
	ray&	operator=(ray const &origin)
	{
		if (this != &origin)
		{
			_point = origin._point;
			_normal = origin._normal;
		}
		return (*this);
	}
	~ray()
	{};

	point3	point() const
	{ return (_point); };
	vec3	normal() const
	{ return (_normal); };
	point3	at(double t) const
	{ return (this->_point + (this->_normal * t)); };
};

#endif