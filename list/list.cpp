#include <iostream>

#include <list>

int main()
{
	std::list<int> l;
	auto print = [&]() {
		std::cout << "l.empty():    " << l.empty() << "\n";
		std::cout << "l.size():     " << l.size() << "\n";
		std::cout << "l.max_size(): " << l.max_size() << "\n";
		for (auto it = l.begin(); it != l.end(); ++it)
		{
			std::cout << *it << "\n";
		}
	};

	std::cout << "\n[Initial state]\n";
	print();

	std::cout << "\n[After push_back()]\n";
	l.push_back(1);
	print();

	std::cout << "\n[After clear()]\n";
	l.clear();
	print();

	std::cout << "\n[After insert()]\n";
	for (int i = 0; i < 10; i++)
	{
		l.insert(l.end(), i);
	}
	print();

	std::cout << "\n[After erase()]\n";
	for (auto it = l.begin(); it != l.end(); )
	{
		if (*it % 2 == 0)
		{
			it = l.erase(it);
		}
		else
		{
			++it;
		}
	}
	print();

	std::cout << "\n[After resize()]\n";
	l.resize(10);
	print();

	return 0;
}
