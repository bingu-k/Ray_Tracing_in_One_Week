#include "rtweekend.hpp"
#include "color.hpp"
#include "camera.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"

color   ray_color(const ray &r, const hittable &world)
{
	hit_record	rec;
	double	t = 0;

	if (world.hit(r, 0, infinity, rec))
		return ((rec.normal + color(1.0,1.0,1.0)) * 0.5);
	t = (r._normal.y() * 0.5) + 1.0;
	return (color(1.0, 1.0, 1.0) * (1.0 - t) + color(0.5, 0.7, 1.0) * t);
}

int main() {
	// Image
	const double    aspect_ratio(16.0 / 9.0);
	const int       image_width(800);
	const int       image_height(static_cast<int>(image_width / aspect_ratio));

	// World
	hittable_list	world;
	world.add(make_shared<sphere>(point3(2,0,0), 0.5));
	world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

	// Camera
	camera  cam(2.0, aspect_ratio, vec3(0,0,0), vec3(1, 0, 0));
	// Render
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0; --j) {
		for (int i = 0; i < image_width; ++i) {
			double  u(static_cast<double>(i) / (image_width - 1));
			double  v(static_cast<double>(j) / (image_height - 1));
			ray     r = cam.get_ray(u, v);
			color   pixel_color(ray_color(r, world));
			write_color(std::cout, pixel_color);
		}
	}
}