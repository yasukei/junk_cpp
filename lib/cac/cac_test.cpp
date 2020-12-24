#include <iostream>
#include <vector>

#include "cac.hpp"

#include <gtest/gtest.h>

TEST(aaa, bbb)
{
	cac::RequestHeader rh;

	rh.typeId.data = cac::TypeId::Request;
	rh.formatId.data = cac::FormatId::Full;
	rh.priority.data = cac::Priority::High;
	rh.transactionId.data = 1;
	rh.size = 2;

	std::vector<uint8_t> buf(6, 0);

	rh.pack(buf.data());

	std::vector<uint8_t> expect = { 0x52, 0x01, 0x02, 0x00, 0x00, 0x00 };

	EXPECT_EQ(expect, buf);
}
