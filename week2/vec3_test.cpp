#include "vec3.hpp"

int	main(void)
{
	vec3	zero;
	vec3	ab(1, 1, 1);
	vec3	bc(3, 7, 2);
	double	num(5);

	std::cout << zero << ab << bc << std::endl;
	ab *= num;
	std::cout << "ab * num = " << ab << std::endl;
	ab /= num;
	std::cout << "bc / num = " << ab << std::endl;
	std::cout << "ab + bc = " << ab + bc << std::endl;
	std::cout << "ab - bc = " << ab - bc << std::endl;
	std::cout << "ab * bc = " << ab * num << std::endl;
	std::cout << "ab / bc = " << ab / num << std::endl;
	std::cout << "ab dot bc = " << dot(ab, bc) << std::endl;
	std::cout << "ab cross bc = " << cross(ab, bc) << std::endl;
	std::cout << "unit vec bc = " << unit_vec3(bc) << std::endl;
	std::cout << zero << ab << bc << std::endl;
	std::cout << "bc length = " << bc.length() << std::endl;
	std::cout << "bc length_sqrt = " << bc.length_sqrt() << std::endl;
	return (0);
}