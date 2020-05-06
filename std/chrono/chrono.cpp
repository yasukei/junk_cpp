#include <iostream>
#include <iomanip>
#include <ctime>

#include <chrono>

int main()
{
	std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::cout << "UTC:   " << std::put_time(std::gmtime(&t), "%F %T") << '\n';
	std::cout << "Local: " << std::put_time(std::localtime(&t), "%F %T %z") << '\n';
	
	std::chrono::steady_clock::time_point before = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point after = std::chrono::steady_clock::now();
	
	std::chrono::duration<double, std::nano> elapsedNanoSec = after - before;
	std::cout << "elapsed time: " << elapsedNanoSec.count() << "[ns]\n";

	return 0;
}
