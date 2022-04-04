#ifndef HITTABLE_HPP
# define HITTABLE_HPP

# include "ray.hpp"

class material;

struct hit_record{
	point3					p;
	vec3					normal;
	shared_ptr<material>	mat_ptr;
	double					t;
};

class hittable
{
public:
	virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const = 0;
};

#endif