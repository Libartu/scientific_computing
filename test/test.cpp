#include "DataFrame.h"


/* Move to class named dataframe  */
/* Add slicing and copying to eigen structs */
/* Use type traits for checking data types in template. */
int main()
{
	std::string fileName{"test/data/datingTestSet.txt"};
	using rowTypes = std::tuple<int, double, double, std::string>;

	std::vector<rowTypes> dataFrame = loadData<rowTypes>(fileName, '\t');

	return 0;
}
