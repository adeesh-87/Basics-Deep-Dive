#include <iostream>
#include <merge_sort.h>
#include <gtest/gtest.h>
#include <sorting_tests.h>

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}