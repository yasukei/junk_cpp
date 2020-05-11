#include <iostream>

#include <typeinfo>

namespace abc
{

class Super1
{
public:
	virtual void hoge() {}
};

} // namespace abc

using namespace abc;

class Sub1 : public Super1
{
};

class Sub2 : public Super1
{
};

class SubSub1 : public Sub1
{
};

int main()
{
	Super1* super1 = new Super1();
	Super1* sub1 = new Sub1();
	Super1* sub2 = new Sub2();
	Super1* subsub1 = new SubSub1();

	auto print = [=](Super1* ptr) {
		std::cout << "typeid(*ptr).name():      [" << typeid(*ptr).name() << "]\n";
		std::cout << "typeid(*ptr).hash_code(): [" << typeid(*ptr).hash_code() << "]\n";

	};

	std::cout << "\n[Super1]\n";
	print(super1);

	std::cout << "\n[Sub1]\n";
	print(sub1);
	
	std::cout << "\n[Sub2]\n";
	print(sub2);
	
	std::cout << "\n[SubSub1]\n";
	print(subsub1);

	return 0;
}
