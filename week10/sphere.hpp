#ifndef SPHERE_HPP
# define SPHERE_HPP

# include "hittable.hpp"
# include "ray.hpp"

class sphere : public hittable
{
public:
	point3					_center;
	double					_radius;
	shared_ptr<material>	_mat_ptr;
public:
	sphere() {};
	sphere(point3 center, double r, shared_ptr<material> m)
	: _center(center), _radius(r), _mat_ptr(m)
	{};
	virtual ~sphere()
	{};

	virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override;
};

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &rec) const
{
	vec3	oc(r.point() - _center);
	double	a = dot(r.normal(), r.normal());
	double	b = dot(oc, r.normal());
	double	c = dot(oc, oc) - (_radius * _radius);
	double	discriminant = (b * b) - (a * c);
	double	t = 0;
	
	if (discriminant <= 0)
		return (false);
	else
	{
		double	t1 = (-b - sqrt(discriminant)) / a;
		double	t2 = (-b + sqrt(discriminant)) / a;
		if (t1 < t2 && t1 > 0)
			t = t1;
		else if (t1 > t2 && t2 > 0)
			t = t2;
		else
			return (false);
		if (t < t_min || t_max < t)
			return (false);
	}
	rec.t = t;
	rec.p = r.at(rec.t);
	rec.normal = unit_vec3(rec.p - _center);
	rec.mat_ptr = _mat_ptr;
	return (true);
}

#endif