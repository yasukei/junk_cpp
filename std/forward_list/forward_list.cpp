#include <iostream>

#include <forward_list>

int main()
{
	std::forward_list<int> l;
	auto print = [&]() {
		std::cout << "l.empty():    " << l.empty() << "\n";
		std::cout << "l.max_size(): " << l.max_size() << "\n";
		for (auto it = l.begin(); it != l.end(); ++it)
		{
			std::cout << *it << "\n";
		}
	};

	std::cout << "\n[Initial state]\n";
	print();

	std::cout << "\n[After push_front()]\n";
	l.push_front(1);
	print();

	std::cout << "\n[After clear()]\n";
	l.clear();
	print();

	std::cout << "\n[After insert()]\n";
	l.push_front(0);
	for (int i = 1; i < 10; i++)
	{
		l.insert_after(l.begin(), i);
	}
	print();

	std::cout << "\n[After erase()]\n";
	for (auto it = l.begin(); it != l.end(); )
	{
		if (*it % 2 == 0)
		{
			it = l.erase_after(it);
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
