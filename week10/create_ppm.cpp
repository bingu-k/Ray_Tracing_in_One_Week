#include "rtweekend.hpp"
#include "color.hpp"
#include "camera.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"

#include "lambertian.hpp"
#include "metal.hpp"
#include "dielectric.hpp"

color   ray_color(const ray &r, const hittable &world, int depth)
{
	hit_record	rec;
	double	t = 0;

	if (depth <= 0)
		return (color(0.0,0.0,0.0));
	if (world.hit(r, roundoff_error, infinity, rec))
	{
		ray		scattered;
		color	attenuation;

		if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
			return (attenuation * ray_color(scattered, world, depth - 1));
		return (color(0.0,0.0,0.0));
	}
	t = (r._normal.y() * 0.5) + 1.0;
	return (color(1.0, 1.0, 1.0) * (1.0 - t) + color(0.5, 0.7, 1.0) * t);
}

int main() {
	// Image
	const double    aspect_ratio(16.0 / 9.0);
	const int       image_width(800);
	const int       image_height(static_cast<int>(image_width / aspect_ratio));
	const int		samples_per_pixel = 100;
	const int		max_depth = 50;

	// World
	hittable_list	world;

		// Create Materials
	auto	material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
	auto	material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
	auto	material_left = make_shared<dielectric>(1.5);
	auto	material_right = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);

		// Create objects
	world.add(make_shared<sphere>(point3(0.0,	-100.5,	0.0),	100.0,	material_ground));
	world.add(make_shared<sphere>(point3(2.0,	0.0,	0.0),	0.5,	material_center));
	world.add(make_shared<sphere>(point3(2.0,	0.0,	-1.0),	0.5,	material_left));
	world.add(make_shared<sphere>(point3(2.0,	0.0,	1.0),	0.5,	material_right));

	// Camera
	camera  cam(2.0, aspect_ratio, vec3(0,0,0), vec3(1, 0, 0));
	// Render
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i)
		{
			color   pixel_color(0.0, 0.0, 0.0);
			for (int k = 0; k < samples_per_pixel; ++k)
			{
				// 원래 값의 0~1까지의 숫자를 100회 뽑아 평균값을 표현.
				double  u((i + random_double()) / (image_width - 1));
				double  v((j + random_double()) / (image_height - 1));
				ray     r = cam.get_ray(u, v);
				pixel_color += ray_color(r, world, max_depth);
			}
			write_color(std::cout, pixel_color, samples_per_pixel);
		}
	}
}