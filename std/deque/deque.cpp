#include <iostream>

#include <deque>

int main()
{
	std::deque<int> d;
	auto print = [&]() {
		std::cout << "d.empty():    " << d.empty() << "\n";
		std::cout << "d.size():     " << d.size() << "\n";
		std::cout << "d.max_size(): " << d.max_size() << "\n";
		for (int i = 0; i < d.size(); i++)
		{
			std::cout << "d[" << i << "]: " << d[i] << "\n";
		}
	};

	std::cout << "\n[Initial state]\n";
	print();

	std::cout << "\n[After push_front()/push_back()]\n";
	d.push_front(1);
	d.push_back(2);
	print();

	std::cout << "\n[After clear()]\n";
	d.clear();
	print();

	std::cout << "\n[After insert()]\n";
	for (int i = 0; i < 10; i++)
	{
		d.insert(d.end(), i);
	}
	print();

	std::cout << "\n[After erase()]\n";
	for (auto it = d.begin(); it != d.end(); )
	{
		if (*it % 2 == 0)
		{
			it = d.erase(it);
		}
		else
		{
			++it;
		}
	}
	print();

	std::cout << "\n[After resize()]\n";
	d.resize(10);
	print();

	return 0;
}
