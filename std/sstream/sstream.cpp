#include <iostream>
#include <chrono>

#include <sstream>

int main()
{
	std::cout << "\n\nReferencing string of sstream\n";
	{
		std::stringstream ss;

		ss << "hello ";

		std::string s = ss.str();
		const std::string& cs = ss.str();
		const char* c = ss.str().c_str();

		std::cout << "\n\n1st place\n";
		std::cout << "std::string s = ss.str();          :" << s;
		printf("0x%p\n\n", s.c_str());
		std::cout << "const std::string& cs = ss.str();  :" << cs;
		printf("0x%p\n\n", cs.c_str());
		std::cout << "const char* c = ss.str().c_str();  :" << c;
		printf("0x%p\n\n", c);

		ss << "good bye ";
		std::cout << "\n\n2nd palce\n";
		std::cout << "std::string s = ss.str();          :" << s;
		printf("0x%p\n\n", s.c_str());
		std::cout << "const std::string& cs = ss.str();  :" << cs;
		printf("0x%p\n\n", cs.c_str());
		std::cout << "const char* c = ss.str().c_str();  :" << c;
		printf("0x%p\n\n", c);

		const std::string& cs2 = ss.str();
		std::cout << "const std::string& cs2 = ss.str(); :" << cs2;
		printf("0x%p\n\n", cs2.c_str());
	}

	std::cout << "\n\nBuilding string\n";
	{
		std::chrono::steady_clock::time_point before, after;
		std::chrono::duration<double, std::nano> elapsedNanoSec;

		std::stringstream ss;
		before = std::chrono::steady_clock::now();
		ss << "abc" << "def";
		after = std::chrono::steady_clock::now();

		elapsedNanoSec = after - before;
		std::cout << "Building string by sstream. elapsed time: " << elapsedNanoSec.count() << "[ns]\n";

		std::string s;
		before = std::chrono::steady_clock::now();
		s += "abc";
		s += "def";
		after = std::chrono::steady_clock::now();

		elapsedNanoSec = after - before;
		std::cout << "Building string by string. elapsed time: " << elapsedNanoSec.count() << "[ns]\n";
	}

	return 0;
}
