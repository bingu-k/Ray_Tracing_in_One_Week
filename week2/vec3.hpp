#ifndef VEC3_HPP
# define VEC3_HPP

#include <cmath>

class vec3
{
public:
	double  element[3];
public:
	vec3(void) : element{0, 0, 0} { };
	vec3(double x, double y, double z) : element{x, y, z} { };
	vec3(vec3 const &origin) : element{origin.x(), origin.y(), origin.z()} { };
	~vec3(void);

	// Get Elements
	double	x(void) const { return (this->element[0]); }
	double	y(void) const { return (this->element[1]); }
	double	z(void) const { return (this->element[2]); }

	// Vector calcurator
	vec3&	operator=(vec3 const &origin)
	{
		this->element[0] = origin.x();
		this->element[1] = origin.y();
		this->element[2] = origin.z();
		return (*this);
	}

	vec3&	operator+(vec3 const &origin)
	{
		vec3	res(vec3(this->x() + origin.x(), this->y() + origin.y(), this->z() + origin.z()));
		return (res);
	}
	vec3&	operator-(vec3 const &origin)
	{
		vec3	res(vec3(this->x() - origin.x(), this->y() - origin.y(), this->z() - origin.z()));
		return (res);
	}
	vec3&	operator*(vec3 const &origin)
	{
		vec3	res(vec3(this->x() * origin.x(), this->y() * origin.y(), this->z() * origin.z()));
		return (res);
	}
	vec3&	operator/(vec3 const &origin)
	{
		vec3	res(vec3(this->x() / origin.x(), this->y() / origin.y(), this->z() / origin.z()));
		return (res);
	}
	double	dot_product(vec3 const &rhs)
	{ return (this->x() * rhs.x() + this->y() * rhs.y() + this->z() * rhs.z()); }
	vec3&	cross_product(vec3 const &rhs)
	{
		vec3	res()
	}
	double	length(void) const { return (sqrt(this->dot_product(*this))); }
};

#endif