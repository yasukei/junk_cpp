#include <iostream>

#include <array>

int main()
{
	std::array<int, 4> myArray1 = { 0, 10, 100, 1000 };
	auto printMyArray1 = [&]() {
		std::cout << "myArray1\n";
		for (int i = 0; i < myArray1.size(); i++)
		{
			std::cout << "myArray1[" << i << "]: " << myArray1[i] << "\n";
		}
	};
	printMyArray1();

	std::array<int, 4> myArray2 = { 0, 20, 200, 2000 };
	auto printMyArray2 = [&]() {
		std::cout << "myArray2\n";
		for (std::array<int, 4>::iterator it = myArray2.begin(); it != myArray2.end(); it++)
		{
			std::cout << "myArray2[" << std::distance(myArray2.begin(), it) << "]: " << *it << "\n";
		}
	};
	printMyArray2();

	myArray1.swap(myArray2);
	std::cout << "\nAfter swap()\n";
	printMyArray1();
	printMyArray2();

	return 0;
}
