#include <iostream>
#include <list>
#include <deque>

#include <queue>

int main()
{
	std::deque<int> d = { 1, 2, 3 };
	std::list<int> l = { 4, 5 };

	std::queue<int> q1(std::move(d));
	std::queue<int, std::list<int>> q2(std::move(l));

	auto print = [&]() {
		std::cout << "q1.empty():    " << q1.empty() << "\n";
		std::cout << "q1.size():     " << q1.size() << "\n";
		std::cout << "q2.empty():    " << q2.empty() << "\n";
		std::cout << "q2.size():     " << q2.size() << "\n";
	};

	std::cout << "\n[Initial state]\n";
	print();

	std::cout << "\n[After push()]\n";
	q1.push(10);
	q2.push(100);
	print();

	return 0;
}
