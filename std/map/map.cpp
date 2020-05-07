#include <iostream>
#include <string>
#include <vector>

#include <map>

int main()
{
	std::map<std::string, int> m;
	auto print = [&]() {
		std::cout << "m.empty():    " << m.empty() << "\n";
		std::cout << "m.size():     " << m.size() << "\n";
		std::cout << "m.max_size(): " << m.max_size() << "\n";
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			std::cout << "v[" << it->first << "]: " << it->second << "\n";
		}
	};

	std::cout << "\n[Initial state]\n";
	print();

	std::cout << "\n[After push_back()]\n";
	m.insert({ "Jan", 1 });
	print();

	std::cout << "\n[After push_back()]\n";
	m.insert(std::make_pair("Feb", 2));
	print();

	std::cout << "\n[After clear()]\n";
	m.clear();
	print();

	std::cout << "\n[After insert()]\n";
	std::vector<std::string> month = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	for (int i = 0; i < month.size(); i++)
	{
		m.insert({ month[i], i+1 });
	}
	print();

	std::cout << "\n[After erase()]\n";
	for (auto it = m.begin(); it != m.end(); )
	{
		if (it->second % 2 == 0)
		{
			it = m.erase(it);
		}
		else
		{
			++it;
		}
	}
	print();

	std::cout << "\n[find(\"Jul\")]\n";
	auto search = m.find("Jul");
	if (search == m.end())
	{
		std::cout << "Not found" << "\n";
	}
	else
	{
		std::cout << search->second << " was found" << "\n";
	}
	
	return 0;
}
