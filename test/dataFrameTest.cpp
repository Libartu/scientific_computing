#include "gtest/gtest.h"
#include "DataFrame.h"

using rowTypes = std::tuple<int, double, double, std::string>;

std::string fileName{TEST_SET_1};


// Checks if loaded data has correct size
TEST(DataFrameTestFixfure, CheckDataSizes)
{
	std::vector<rowTypes> dataFrame = DataFrame::loadData<rowTypes>(fileName, '\t', false);
	EXPECT_EQ(dataFrame.size(), 1000);
}


// Checks if loaded primitive data types are correct
TEST(DataFrameTestFixfure, CheckColumnPrimitiveDataTypes)
{
	std::vector<rowTypes> dataFrame = DataFrame::loadData<rowTypes>(fileName, '\t', false);

	EXPECT_EQ(std::string(typeid(std::get<0>(dataFrame[0])).name()), std::string("i"));
	EXPECT_EQ(std::string(typeid(std::get<1>(dataFrame[0])).name()), std::string("d"));
	EXPECT_EQ(std::string(typeid(std::get<2>(dataFrame[0])).name()), std::string("d"));
}


int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return  RUN_ALL_TESTS();
}
