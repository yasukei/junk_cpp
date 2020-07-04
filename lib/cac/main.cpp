#include <iostream>

#include "cac.hpp"

int __main()
{
	std::cout << "hello" << std::endl;
	
	cac::RequestHeader rh;

	rh.typeId.data = cac::TypeId::Request;
	rh.formatId.data = cac::FormatId::Full;
	rh.priority.data = cac::Priority::High;
	rh.transactionId.data = 1;
	rh.size = 2;

	uint8_t buf[32] = { 0 };

	rh.pack(buf);

	return 0;
}

#include <gtest/gtest.h>

TEST(aaa, bbb)
{
	__main();
	EXPECT_TRUE(true);
}
