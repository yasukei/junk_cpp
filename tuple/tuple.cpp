#include <cstdio>

#include <tuple>

int main()
{
	std::tuple<double, double, double> xyz = std::make_tuple(1.0, 2.0, 3.0);
	std::get<0>(xyz) = 4.0;
	printf("std::get<0>(xyz): [%lf]\n", std::get<0>(xyz));
	printf("std::get<1>(xyz): [%lf]\n", std::get<1>(xyz));
	printf("std::get<2>(xyz): [%lf]\n", std::get<2>(xyz));

	double x, y, z;
	std::tie(x, y, z) = xyz;
	printf("x: [%lf]\n", x);
	printf("y: [%lf]\n", y);
	printf("z: [%lf]\n", z);

	return 0;
}
