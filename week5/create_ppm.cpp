#include "vec3.hpp"
#include "color.hpp"
#include "ray.hpp"
#include "camera.hpp"

bool    hit_sphere(const point3 &center, double radius, const ray &r)
{
	vec3	oc(r.point() - center);
	double	a = dot(r.normal(), r.normal());
	double	b = 2.0 * dot(oc, r.normal());
	double	c = dot(oc, oc) - (radius * radius);
	double	discriminant = (b * b) - (4 * a * c);
	return (discriminant > 0);
}

color   ray_color(const ray &r)
{
	if (hit_sphere(point3(2,0,0), 0.5, r))
		return (color(1, 0, 0));
	double  t(r._normal.y() + 1.0);
	return (color(1.0, 1.0, 1.0) * (1.0 - t) + color(0.5, 0.7, 1.0) * t);
}

int main() {
	// Image
	const double    aspect_ratio(16.0 / 9.0);
	const int       image_width(800);
	const int       image_height(static_cast<int>(image_width / aspect_ratio));

	// Camera
	camera  cam(2.0, aspect_ratio, vec3(0,0,0), vec3(1, 0, 0));
	// Render
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0; --j) {
		for (int i = 0; i < image_width; ++i) {
			double  u(static_cast<double>(i) / (image_width - 1));
			double  v(static_cast<double>(j) / (image_height - 1));
			ray     r = cam.create_ray(u, v);
			color   pixel_color(ray_color(r));
			write_color(std::cout, pixel_color);
		}
	}
}