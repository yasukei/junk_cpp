#include <iostream>

#include <vector>

int main()
{
	std::vector<int> v;
	auto print = [&]() {
		std::cout << "v.empty():    " << v.empty() << "\n";
		std::cout << "v.size():     " << v.size() << "\n";
		std::cout << "v.max_size(): " << v.max_size() << "\n";
		std::cout << "v.capacity(): " << v.capacity() << "\n";
		for (int i = 0; i < v.size(); i++)
		{
			std::cout << "v[" << i << "]: " << v[i] << "\n";
		}
	};

	std::cout << "\n[Initial state]\n";
	print();

	std::cout << "\n[After reserve()]\n";
	v.reserve(32);
	print();

	std::cout << "\n[After shrink_to_fit()]\n";
	v.shrink_to_fit();
	print();

	std::cout << "\n[After push_back()]\n";
	v.push_back(1);
	print();

	std::cout << "\n[After clear()]\n";
	v.clear();
	print();

	std::cout << "\n[After insert()]\n";
	for (int i = 0; i < 10; i++)
	{
		v.insert(v.end(), i);
	}
	print();

	std::cout << "\n[After erase()]\n";
	for (auto it = v.begin(); it != v.end(); )
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}
	print();

	std::cout << "\n[After resize()]\n";
	v.resize(10);
	print();

	return 0;
}
