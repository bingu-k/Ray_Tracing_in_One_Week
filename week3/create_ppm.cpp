#include "vec3.hpp"
#include "color.hpp"

int main() {
    // Image
    const int image_width = 256;
    const int image_height = 256;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
			color	pixel_color(static_cast<double>(i) / (image_width - 1),
								static_cast<double>(j) / (image_height - 1),
								0.25);
			write_color(std::cout, pixel_color);
        }
    }
}