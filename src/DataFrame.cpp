#include "DataFrame.h"

namespace DataFrame
{

std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}

	return tokens;
}


void convertType(std::string lineItem, double &value)
{
	value = stod(lineItem);
}


void convertType(std::string lineItem, int &value)
{
	value = stoi(lineItem);
}


void convertType(std::string lineItem, std::string &value)
{
	value = lineItem;
}

} // namespace DataFrame
