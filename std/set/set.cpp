#include <iostream>
#include <string>
#include <vector>

#include <set>

int main()
{
	std::set<std::string> s;
	auto print = [&]() {
		std::cout << "s.empty():    " << s.empty() << "\n";
		std::cout << "s.size():     " << s.size() << "\n";
		std::cout << "s.max_size(): " << s.max_size() << "\n";
		for (auto it = s.begin(); it != s.end(); ++it)
		{
			std::cout << "s[" << it->c_str() << "]\n";
		}
	};

	std::cout << "\n[Initial state]\n";
	print();

	std::cout << "\n[After insert()]\n";
	auto result = s.insert("Jan");
	std::cout << "inserted: [" << result.second << "]\n";
	result = s.insert("Jan");
	std::cout << "inserted: [" << result.second << "]\n";
	print();

	std::cout << "\n[After push_back()]\n";
	s.insert("Feb");
	print();

	std::cout << "\n[After clear()]\n";
	s.clear();
	print();

	std::cout << "\n[After insert()]\n";
	std::vector<std::string> month = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	for (int i = 0; i < month.size(); i++)
	{
		s.insert(month[i]);
	}
	print();

	std::cout << "\n[After erase()]\n";
	for (auto it = s.begin(); it != s.end(); )
	{
		if (it->front() == 'J')
		{
			it = s.erase(it);
		}
		else
		{
			++it;
		}
	}
	print();

	std::cout << "\n[find(\"Jul\")]\n";
	auto search = s.find("Jul");
	if (search == s.end())
	{
		std::cout << "Not found" << "\n";
	}
	else
	{
		std::cout << search->c_str() << " was found" << "\n";
	}
	
	return 0;
}
