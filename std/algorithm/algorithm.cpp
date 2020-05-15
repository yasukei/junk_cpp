#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <set>

#include <algorithm>

int main()
{
	std::cout << "\n[all_of, any_of, none_of]\n";
	{
		std::vector<int> v = { 0, 10, 100, 1000 };

		auto moreThanZero = [](int i) { return i >= 0; };
		if (std::all_of(v.cbegin(), v.cend(), moreThanZero))
		{
			std::cout << "all of vector are more than zero\n";
		}

		auto isTen = [](int i) { return i == 10; };
		if (std::any_of(v.cbegin(), v.cend(), isTen))
		{
			std::cout << "any of vector is ten\n";
		}

		auto lessThanZero = [](int i) { return i < 0; };
		if (std::none_of(v.cbegin(), v.cend(), lessThanZero))
		{
			std::cout << "none of vector is less than zero\n";
		}
	}

	std::cout << "\n[for_each]\n";
	{
		std::array<int, 10> a = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		auto print = [](int i) { std::cout << i << ", "; };
		auto minus1 = [](int &i) { i -= 1; };

		std::for_each(a.cbegin(), a.cend(), print);
		std::cout << "\n";

		std::for_each(a.begin(), a.end(), minus1);

		std::for_each(a.cbegin(), a.cend(), print);
		std::cout << "\n";
	}

	std::cout << "\n[count, count_if]\n";
	{
		std::deque<bool> d = { true, false, true, true };

		auto isFalse = [](bool b) { return !b; };

		std::cout << "the number of true is  " << std::count(d.cbegin(), d.cend(), true) << "\n";
		std::cout << "the number of false is " << std::count_if(d.cbegin(), d.cend(), isFalse) << "\n";
	}

	std::cout << "\n[mismatch]\n";
	{
		std::forward_list<double> fl1 = { 1.0, 2.0, 3.0, 4.0, 5.0 };
		std::forward_list<double> fl2 = { 1.0, 2.0, 3.0, 4.5, 6.5 };

		auto mismatch1 = std::mismatch(fl1.cbegin(), fl1.cend(), fl2.cbegin());
		std::cout << "mismatch was (" << *mismatch1.first << ", " << *mismatch1.second << ")\n";

		auto seeOnlyIntegerPart = [](double d1, double d2)
		{
			if (d1 > d2)
			{
				return d1 - d2 < 1.0;
			}
			else
			{
				return d2 - d1 < 1.0;
			}
		};
		auto mismatch2 = std::mismatch(fl1.cbegin(), fl1.cend(), fl2.cbegin(), seeOnlyIntegerPart);
		std::cout << "mismatch was (" << *mismatch2.first << ", " << *mismatch2.second << ")\n";
	}

	std::cout << "\n[find, find_if, find_if_not]\n";
	{
		std::list<std::string> l = { "abc", "def", "ghi" };

		auto printResult = [](std::list<std::string>::const_iterator& found, std::list<std::string>::const_iterator& end)
		{
			if (found == end)
			{
				std::cout << "not found\n";
			}
			else
			{
				std::cout << *found << "\n";
			}
		};
		auto found = std::find(l.cbegin(), l.cend(), "def");
		printResult(found, l.cend());

		found = std::find(l.cbegin(), l.cend(), "DEF");
		printResult(found, l.cend());

		
		auto find_ghi = [](const std::string s) { return s.compare("ghi") == 0; };
		found = std::find_if(l.cbegin(), l.cend(), find_ghi);
		printResult(found, l.cend());

		found = std::find_if_not(l.cbegin(), l.cend(), find_ghi);
		printResult(found, l.cend());
	}

	std::cout << "\n[search]\n";
	{
		std::map<int, double> m1 = { {1, 1.5}, {2, 2.5}, {3, 3.5}, {5, 5.5} };
		std::map<int, double> m2 = { {2, 2.5}, {3, 3.5} };

		auto found = std::search(m1.cbegin(), m1.cend(), m2.cbegin(), m2.cend());
		std::cout << (*found).first << ", " << (*found).second << "\n";
	}

	std::cout << "\n[copy]\n";
	{
		std::vector<int> from_vector(10);
		std::iota(from_vector.begin(), from_vector.end(), 0);

		std::vector<int> to_vector;
		std::copy(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector));
		// or, alternatively,
		//  std::vector<int> to_vector(from_vector.size());
		//  std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());
		// either way is equivalent to
		//  std::vector<int> to_vector = from_vector;

		std::cout << "to_vector contains: ";

		std::copy(to_vector.begin(), to_vector.end(),
			std::ostream_iterator<int>(std::cout, " "));
		std::cout << '\n';
	}

	std::cout << "\n[fill]\n";
	{
		std::vector<short> v = { 1, 2, 3, 4 };
		auto print = [](short s) { std::cout << s << ", "; };

		std::for_each(v.cbegin(), v.cend(), print);
		std::cout << "\n";

		std::fill(v.begin(), v.end(), 10);

		std::for_each(v.cbegin(), v.cend(), print);
		std::cout << "\n";
	}

	return 0;
}
