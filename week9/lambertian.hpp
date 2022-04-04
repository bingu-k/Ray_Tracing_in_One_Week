#ifndef LAMBERTIAN_HPP
# define LAMBERTIAN_HPP

#include "material.hpp"

class lambertian : public material
{
public:
	color	_albedo;
public:
	lambertian(const color &albedo) : _albedo(albedo)
	{};
	virtual ~lambertian()
	{};

	virtual bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override;
};

bool lambertian::scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const
{
	(void)r_in;
	vec3	scatter_direction = rec.normal + random_unit_vector();
	// 위의 값이 영벡터와 거의 차이가 없다면 rec의 법선벡터로 변경.
	if (scatter_direction.near_zero())
		scatter_direction = rec.normal;
	scattered = ray(rec.p, scatter_direction);
	attenuation = _albedo;
	return (true);
}

#endif