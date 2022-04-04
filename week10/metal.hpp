#ifndef METAL_HPP
# define METAL_HPP

#include "material.hpp"

class metal : public material
{
public:
	color	_albedo;
	double	_fuzz;
public:
	metal(const color &albedo, double fuzz) : _albedo(albedo), _fuzz(fuzz < 1 ? fuzz : 1)
	{};
	virtual ~metal()
	{};

	virtual bool	scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override;
};

bool metal::scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const
{
	vec3	reflected = reflect(unit_vec3(r_in.normal()), rec.normal);
	scattered = ray(rec.p, reflected + (random_in_unit_sphere() * _fuzz));
	attenuation = _albedo;
	return (dot(scattered.normal(), rec.normal) > 0);
}

#endif