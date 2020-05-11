#include <iostream>
#include <string>
#include <vector>

#include <unordered_set>

int main()
{
	std::unordered_set<std::string> us;
	auto print = [&]() {
		std::cout << "us.empty():    " << us.empty() << "\n";
		std::cout << "us.size():     " << us.size() << "\n";
		std::cout << "us.max_size(): " << us.max_size() << "\n";
		std::cout << "us.bucket_count(): " << us.bucket_count() << "\n";
		std::cout << "us.max_bucket_count(): " << us.max_bucket_count() << "\n";
		for (auto it = us.begin(); it != us.end(); ++it)
		{
			std::cout << "s[" << it->c_str() << "]\n";
		}
		for (int i = 0; i < us.bucket_count(); ++i)
		{
			std::cout << "us.bucket_size(" << i << "): " << us.bucket_size(i) << "\n";
		}
		std::cout << "us.load_factor(): " << us.load_factor() << "\n";
		std::cout << "us.max_load_factor(): " << us.max_load_factor() << "\n";
	};

	std::cout << "\n[Initial state]\n";
	print();

	std::cout << "\n[After insert()]\n";
	auto result = us.insert("Jan");
	std::cout << "inserted: [" << result.second << "]\n";
	result = us.insert("Jan");
	std::cout << "inserted: [" << result.second << "]\n";
	print();

	std::cout << "\n[After push_back()]\n";
	us.insert("Feb");
	print();

	std::cout << "\n[After clear()]\n";
	us.clear();
	print();

	std::cout << "\n[After insert()]\n";
	std::vector<std::string> month = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	for (int i = 0; i < month.size(); i++)
	{
		us.insert(month[i]);
	}
	print();

	std::cout << "\n[After erase()]\n";
	for (auto it = us.begin(); it != us.end(); )
	{
		if (it->front() == 'J')
		{
			it = us.erase(it);
		}
		else
		{
			++it;
		}
	}
	print();

	std::cout << "\n[find(\"Jul\")]\n";
	auto search = us.find("Jul");
	if (search == us.end())
	{
		std::cout << "Not found" << "\n";
	}
	else
	{
		std::cout << search->c_str() << " was found" << "\n";
	}
	
	return 0;
}
