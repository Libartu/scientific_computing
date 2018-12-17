#ifndef DATA_FRAME_H
#define DATA_FRAME_H

#include <iostream>
#include <iterator>
#include <fstream>
#include <tuple>
#include <vector>
#include <sstream>


std::vector<std::string> split(const std::string& s, char delimiter);


void convertType(std::string lineItem, double &value);


void convertType(std::string lineItem, int &value);


void convertType(std::string lineItem, std::string &value);


// helper function to print a tuple of any size
template<class Tuple, std::size_t N>
struct Converter {
    static void convert(std::vector<std::string>& line, Tuple& t)
    {
    	typename std::remove_reference<decltype(std::get<N-1>(t))>::type value;
    	convertType(line[N-1], value);
    	std::get<N-1>(t) = value;

    	Converter<Tuple, N-1>::convert(line, t);
    }
};

template<class Tuple>
struct Converter<Tuple, 1> {
    static void convert(std::vector<std::string>& line, Tuple& t)
    {
    	typename std::remove_reference<decltype(std::get<0>(t))>::type value;
    	convertType(line[0], value);
    	std::get<0>(t) = value;
    }
};

template<class... Args>
static void convert(std::vector<std::string>& line, std::tuple<Args...>& t)
{
    return Converter<decltype(t), sizeof...(Args)>::convert(line, t);
}


template <class T>
std::vector<T> loadData(std::string fileName, char delimiter)
{
	std::ifstream in(fileName);
	std::vector<std::string> lines;
	std::vector<T> sheet;

	std::string line;
	while (std::getline(in, line))
	{
		lines.push_back(line.erase(line.size() - 1));
	}

	for (size_t i = 0; i < lines.size(); i++)
	{
		T tupleSample;
		std::vector<std::string> tokenizedLine{split(lines[i], delimiter)};
		convert(tokenizedLine, tupleSample);
		sheet.push_back(tupleSample);
	}

	return sheet;
}

#endif


