#include <iostream>
#include <string>
#include <vector>

#include <unordered_map>

int main()
{
	std::unordered_map<std::string, int> um;
	auto print = [&]() {
		std::cout << "um.empty():    " << um.empty() << "\n";
		std::cout << "um.size():     " << um.size() << "\n";
		std::cout << "um.max_size(): " << um.max_size() << "\n";
		std::cout << "um.bucket_count(): " << um.bucket_count() << "\n";
		std::cout << "um.max_bucket_count(): " << um.max_bucket_count() << "\n";
		for (auto it = um.begin(); it != um.end(); ++it)
		{
			std::cout << "um[" << it->first << "]: " << it->second << "\n";
		}
		for (int i = 0; i < um.bucket_count(); ++i)
		{
			std::cout << "um.bucket_size(" << i << "): " << um.bucket_size(i) << "\n";
		}
		std::cout << "um.load_factor(): " << um.load_factor() << "\n";
		std::cout << "um.max_load_factor(): " << um.max_load_factor() << "\n";
	};

	std::cout << "\n[Initial state]\n";
	print();

	std::cout << "\n[After insert()]\n";
	um.insert({ "Jan", 1 });
	print();

	std::cout << "\n[After insert()]\n";
	um.insert(std::make_pair("Feb", 2));
	print();

	std::cout << "\n[After clear()]\n";
	um.clear();
	print();

	std::cout << "\n[After insert()]\n";
	std::vector<std::string> month = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	for (int i = 0; i < month.size(); i++)
	{
		um.insert({ month[i], i+1 });
	}
	print();

	std::cout << "\n[After erase()]\n";
	for (auto it = um.begin(); it != um.end(); )
	{
		if (it->second % 2 == 0)
		{
			it = um.erase(it);
		}
		else
		{
			++it;
		}
	}
	print();

	std::cout << "\n[find(\"Jul\")]\n";
	auto search = um.find("Jul");
	if (search == um.end())
	{
		std::cout << "Not found" << "\n";
	}
	else
	{
		std::cout << search->second << " was found" << "\n";
	}
	
	return 0;
}
