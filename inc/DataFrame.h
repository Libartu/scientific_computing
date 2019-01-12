/*
 * This module provides basic utilities for reading, parsing and converting
 * text file data into appropriate format.
 * Copyright (C) 2018 Libartu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this module.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef DATA_FRAME_H
#define DATA_FRAME_H

#include <iostream>
#include <iterator>
#include <fstream>
#include <tuple>
#include <vector>
#include <sstream>

namespace DataFrame
{

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
std::vector<T> loadData(std::string fileName, char delimiter, bool hasHeader)
{
	std::ifstream in(fileName);
	std::vector<std::string> lines;
	std::vector<T> sheet;

	std::string line;
	if (hasHeader)
	{
		std::getline(in, line);
	}

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

}  // namespace DataFrame

#endif
