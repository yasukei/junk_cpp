#include <iostream>

#include <ctime>

int main()
{
	std::time_t calendar_clock = std::time(nullptr);
	char utc[256];
	char local[256];
	std::strftime(utc, sizeof(utc), "%c", std::gmtime(&calendar_clock));
	std::strftime(local, sizeof(local), "%c", std::localtime(&calendar_clock));
	std::cout << "UTC:   " << utc << "\n";
	std::cout << "Local: " << local << "\n";

	return 0;
}
