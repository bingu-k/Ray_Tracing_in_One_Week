#ifndef RTWEEKEND_HPP
# define RTWEEKEND_HPP

# include <cmath>
# include <limits>
# include <memory>
# include <random>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double	infinity = std::numeric_limits<double>::infinity();
const double	pi = 3.1415926535897932385;

inline double	degree_to_radian(double degree)
{ return (degree * pi / 180.0); };

inline double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	else if (x > max)
		return (max);
	else
		return (x);
};

inline double	random_double()
{
	// 간격 [a, b] 에 균일하게 분포 된 , 즉 확률 밀도 함수에 따라 분포 된 임의의 부동 소수점 값 i 를 생성합니다.
	static std::uniform_real_distribution<double>	distribution(0.0, 1.0);
	// 메르센 트위스터, 2^19937-1의 주기를 갖고 있다. [엄청나게 큰 주기와 고른 분포] => 기본 난수 엔진으로 채택.
	static std::mt19937								generator;
	return (distribution(generator));
};

inline double	random_double(double min, double max)
{
	// 간격 [a, b] 에 균일하게 분포 된 , 즉 확률 밀도 함수에 따라 분포 된 임의의 부동 소수점 값 i 를 생성합니다.
	static std::uniform_real_distribution<double>	distribution(min, max);
	// 메르센 트위스터, 2^19937-1의 주기를 갖고 있다. [엄청나게 큰 주기와 고른 분포] => 기본 난수 엔진으로 채택.
	static std::mt19937								generator;
	return (distribution(generator));
};

# include "ray.hpp"
# include "vec3.hpp"

#endif