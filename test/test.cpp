#include "gtest/gtest.h"
#include "DataFrame.h"

using rowTypes = std::tuple<int, double, double, std::string>;


std::string fileName{"datingTestSet.txt"};



TEST(DataFrameTestFixfure, CheckDataSizes)
{
	std::vector<rowTypes> dataFrame = DataFrame::loadData<rowTypes>(fileName, '\t');
	EXPECT_EQ(dataFrame.size(), 1000);
}

TEST(DataFrameTestFixfure, CheckColumnDataTypes)
{
	std::vector<rowTypes> dataFrame = DataFrame::loadData<rowTypes>(fileName, '\t');
}



int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return  RUN_ALL_TESTS();
}
