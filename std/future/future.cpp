#include <cstdio>
#include <string>

#include <future>

int main()
{
	auto f = [](std::string threadName) {
		for (int i = 0; i < 10; i++)
		{
			printf("threadName: [%s], i: [%d]\n", threadName.c_str(), i);
		}
	};
	std::future<void> future1 = std::async(f, "thread1");

	printf("before join\n");
	future1.wait();
	printf("after join\n");
	return 0;
}
