#include <cstdio>
#include <string>
#include <thread>

#include <mutex>

class SomeClass
{
public:
	SomeClass(std::string threadName, std::mutex& mtx) :
		_threadName(threadName),
		_mtx(mtx)
	{
	}

	static void run(void* arg)
	{
		SomeClass* self = (SomeClass*)arg;

		printf("threadName: [%s], before lock\n", self->_threadName.c_str());

		self->_mtx.lock();
		
		printf("threadName: [%s], after  lock\n", self->_threadName.c_str());
		printf("threadName: [%s], before unlock\n", self->_threadName.c_str());
		
		self->_mtx.unlock();
		
		printf("threadName: [%s], after  unlock\n", self->_threadName.c_str());
	}

private:
	std::string _threadName;
	std::mutex& _mtx;
};

extern void lock_guard_main();
int main()
{
	std::mutex mtx;
	SomeClass instance1("thread1", mtx);
	SomeClass instance2("thread2", mtx);
	SomeClass instance3("thread3", mtx);

	std::thread thread1(SomeClass::run, &instance1);
	std::thread thread2(SomeClass::run, &instance2);
	std::thread thread3(SomeClass::run, &instance3);

	printf("before join\n");
	thread1.join();
	thread2.join();
	thread3.join();
	printf("after join\n");

	lock_guard_main();
	return 0;
}
