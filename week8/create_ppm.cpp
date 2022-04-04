#include "rtweekend.hpp"
#include "color.hpp"
#include "camera.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"

color   ray_color(const ray &r, const hittable &world, int depth)
{
	hit_record	rec;
	double	t = 0;

	if (depth <= 0)
		return (color(0.0,0.0,0.0));
	if (world.hit(r, roundoff_error, infinity, rec))
	{
		// point3	target = rec.p + rec.normal + random_unit_vector();
		point3	target = rec.p + random_in_hemisphere(rec.normal);
		return ((ray_color(ray(rec.p, target - rec.p), world, depth - 1)) * 0.5);
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
	world.add(make_shared<sphere>(point3(2,0,0), 0.5));
	world.add(make_shared<sphere>(point3(0,-100.5,0), 100));

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