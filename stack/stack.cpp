#include <iostream>
#include <deque>
#include <list>
#include <vector>

#include <stack>

int main()
{
	std::deque<int> d = { 1, 2, 3 };
	std::list<int> l = { 4, 5 };
	std::vector<int> v = { 6 };

	std::stack<int> s1(std::move(d));
	std::stack<int, std::list<int>> s2(std::move(l));
	std::stack<int, std::vector<int>> s3(std::move(v));

	auto print = [&]() {
		std::cout << "s1.empty():    " << s1.empty() << "\n";
		std::cout << "s1.size():     " << s1.size() << "\n";
		std::cout << "s2.empty():    " << s2.empty() << "\n";
		std::cout << "s2.size():     " << s2.size() << "\n";
		std::cout << "s3.empty():    " << s3.empty() << "\n";
		std::cout << "s3.size():     " << s3.size() << "\n";
	};

	std::cout << "\n[Initial state]\n";
	print();

	std::cout << "\n[After push()]\n";
	s1.push(10);
	s2.push(100);
	s3.push(1000);
	print();

	std::cout << "\n[After pop()]\n";
	s1.pop();
	s2.pop();
	s3.pop();
	print();
	return 0;
}
