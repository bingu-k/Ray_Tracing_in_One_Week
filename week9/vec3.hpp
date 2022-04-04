#ifndef VEC3_HPP
# define VEC3_HPP

#include <iostream>
#include <cmath>
#include "rtweekend.hpp"

class vec3
{
public:
	double  _x;
	double	_y;
	double	_z;
public:
	vec3(void) : _x(0), _y(0), _z(0)
	{};
	vec3(double x, double y, double z) : _x(x), _y(y), _z(z)
	{};
	vec3(vec3 const &origin) : _x(origin.x()), _y(origin.y()), _z(origin.z())
	{};
	~vec3(void)
	{};

	// Get Elements
	double	x(void) const
	{ return (this->_x); };
	double	y(void) const
	{ return (this->_y); };
	double	z(void) const
	{ return (this->_z); };

	// Vector Substitude Operator
	vec3&	operator=(vec3 const &origin)
	{
		this->_x = origin._x;
		this->_y = origin._y;
		this->_z = origin._z;
		return (*this);
	};
	vec3	operator+=(vec3 const &origin)
	{
		_x += origin._x;
		_y += origin._y;
		_z += origin._z;
		return (*this);
	};
	vec3	operator-=(vec3 const &origin)
	{
		_x -= origin._x;
		_y -= origin._y;
		_z -= origin._z;
		return (*this);
	};
	vec3	&operator*=(double num)
	{
		_x *= num;
		_y *= num;
		_z *= num;
		return (*this);
	};
	vec3	&operator/=(double num)
	{ return (*this *= 1/num); };

	double	length_sqrt(void) const
	{ return (_x * _x + _y * _y + _z * _z); };
	double	length(void) const
	{ return (sqrt(this->length_sqrt())); };

	inline static vec3	random()
	{ return (vec3(random_double(), random_double(), random_double())); };
	inline static vec3	random(double min, double max)
	{ return (vec3(random_double(min, max), random_double(min, max), random_double(min, max))); };

	// vec3의 값이 0과 거의 차이가 없는지 확인.
	bool	near_zero() const
	{
		const double s = 1e-8;
		return ((fabs(_x) < s) && (fabs(_y) < s) && (fabs(_z) < s));
	}
};

// Print Status
inline std::ostream	&operator<<(std::ostream &os, vec3 const &origin)
{
	os << "vec3(" << origin._x << ", " << origin._y << ", " << origin._z << ")\n";
	return (os);
};

// Vec3 Calculator
inline vec3	operator+(const vec3 &lhs, const vec3 &rhs)
{ return (vec3(lhs._x + rhs._x, lhs._y + rhs._y, lhs._z + rhs._z)); };

inline vec3	operator-(const vec3 &lhs, const vec3 &rhs)
{ return (vec3(lhs._x - rhs._x, lhs._y - rhs._y, lhs._z - rhs._z)); };

inline vec3	operator*(const vec3 &lhs, double num)
{ return (vec3(lhs._x * num, lhs._y * num, lhs._z * num)); };

inline vec3	operator*(const vec3 &lhs, const vec3 &rhs)
{ return (vec3(lhs._x * rhs._x, lhs._y * rhs._y, lhs._z * rhs._z)); };

inline vec3	operator/(const vec3 &lhs, double num)
{ return (vec3(lhs._x * (1/num), lhs._y * (1/num), lhs._z * (1/num))); };

inline double	dot(vec3 const &lhs, vec3 const &rhs)
{ return (lhs._x * rhs._x + lhs._y * rhs._y + lhs._z * rhs._z); };

inline vec3	cross(vec3 const &lhs, vec3 const &rhs)
{
	double	x(lhs._y * rhs._z - lhs._z * rhs._y);
	double	y(lhs._z * rhs._x - lhs._x * rhs._z);
	double	z(lhs._x * rhs._y - lhs._y * rhs._x);
	return (vec3(x, y, z));
};

inline vec3	unit_vec3(vec3 const &origin)
{ return (origin / origin.length()); };

vec3	random_in_unit_sphere()
{
	while (true)
	{
		vec3	p = vec3::random(-1, 1);
		if (p.length_sqrt() >= 1)
			continue ;
		return (p);
	}
}

vec3	random_unit_vector()
{ return (unit_vec3(random_in_unit_sphere())); };

// 반구형 산란
vec3	random_in_hemisphere(const vec3 &normal)
{
	vec3	in_unit_sphere = random_in_unit_sphere();
	if (dot(in_unit_sphere, normal) > 0.0)
		return (in_unit_sphere);
	else
		return (in_unit_sphere * -1);
};

// 부딫힌 면에 반사광 찾기
vec3	reflect(const vec3 &v, const vec3 &n)
{ return(v - ((n * dot(v, n)) * 2)); };

#endif