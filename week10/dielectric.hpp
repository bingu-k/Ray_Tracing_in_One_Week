#ifndef DIELECTRIC_HPP
# define DIELECTRIC_HPP

#include "material.hpp"

class dielectric : public material
{
public:
	double	ir;
public:
	dielectric(double index_of_refraction) : ir(index_of_refraction)
	{};
	virtual ~dielectric()
	{};

	virtual bool	scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override;

private:
	static double	reflectance(double cosine, double ref_idx)
	{
		double	r0 = (1 - ref_idx) / (1 + ref_idx);
		r0 = r0 * r0;
		return (r0 + (1 - r0) * pow((1 - cosine), 5));
	}
};

bool	dielectric::scatter(const ray &r_in, const hit_record & rec, color &attenuation, ray &scattered) const
{
	attenuation = color(1.0, 1.0, 1.0);
	double	refraction_ratio = rec.front_face ? 1 / ir : ir;
	// vec3	refracted = refract(r_in.normal(), rec.normal, refraction_ratio);
	// scattered = ray(rec.p, refracted);
	// return (true);
	double	cos_theta = fmin(dot(r_in.normal() * -1, rec.normal), 1.0);
	double	sin_theta = sqrt(1.0 - (cos_theta * cos_theta));
	bool	cannot_refract = (refraction_ratio * sin_theta) > 1.0;
	vec3	direction;
	// if (cannot_refract)
	if (cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double())
		direction = reflect(r_in.normal(), rec.normal);
	else
		direction = refract(r_in.normal(), rec.normal, refraction_ratio);
	scattered = ray(rec.p, direction);
	return (true);
};

#endif