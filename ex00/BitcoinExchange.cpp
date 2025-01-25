/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:43:58 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/25 08:25:34 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::addData(inData d)
{
	this->in_data.push_back(d);
}

void BitcoinExchange::printContainer() const
{
	std::cout << "Printing Container..." << std::endl;
	for(auto &it: this->in_data)
		it.getValues();
}

void validateInput(char *str)
{
	std::ifstream file(str);
	std::string line;
	BitcoinExchange btc;

	if(file.is_open())
	{
		std::cout << "File opened" << std::endl;
		std::cout << "- Reading input file: -" << std::endl;
		while (std::getline(file, line))
		{
			std::cout << line << std::endl;
			btc.parseLine(line.data());
		}
		std::cout << "---" << std::endl;
	}
	else
		throw std::runtime_error("Could not access file");
	file.close();
	btc.printContainer();
}

//seperate date into parts and check if valid
//maybe do multiple parsing runthroughs first seperating the vaules => checking if valid => place in container

//isolate values => check if valid => if yes, store them as is => if not store error value(-1) and message in map

void BitcoinExchange::parseLine(char *str)
{
	inData d;
	std::regex line(R"(\s*(\d+-\d+-\d+)\s*\|\s*((\+?|-?)(\d*\.?\d*))\s*)");
	std::regex date(R"((\d{4})-(\d{2})-(\d{2}))");
	std::regex value(R"((\+?|-?)(\d+)|(\d*\.\d+)|(\d+\.\d*))");

	std::cmatch lm;
	std::cmatch dm;
	std::cmatch vm;

	if (std::regex_match(str, lm, line))
	{
		std::cout << "Match: " << lm.str(2) << std::endl;
		if (std::regex_match(lm.str(1).data(), dm, date))
			d.checkDate(dm.str(1), dm.str(2), dm.str(3));
		else
			std::cerr << "Bad date format" << std::endl;
		if (std::regex_match(lm.str(2).data(), vm, value))
			d.checkValue(vm.str());
		else
			std::cerr << "Invalid btc ammount format (only int or double)" << std::endl;
	}
	else
		std::cerr << "Invalid input type. Expected: 'YYYY-MM-DD | btc ammount (int or double)'" << std::endl;

	addData(d);
}

//Checking and setting numeric values

void inData::checkDate(std::string year_str, std::string month_str, std::string day_str)
{
	int year = std::stoi(year_str);
	int month = std::stoi(month_str);
	int day = std::stoi(day_str);

	if (year < 2009 || year > 2022)
		std::cerr << "Year outside of database (2009 - 2022)" << std::endl;
	if (month < 1 || month > 12)
		std::cerr << "Month out of range (1 - 12)" << std::endl;
	if (day < 1 || day > 31)
		std::cerr << "Day out of range (1 - 31)" << std::endl;

	setDate(year, month, day);
}

void inData::setDate(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

void inData::checkValue(std::string value_str)
{
	double value = std::stod(value_str);

	if (value > std::numeric_limits<int>::max())
		std::cerr << "Too large number" << std::endl;
	else if (value < 0.0)
		std::cerr << "Not a positive ammount" << std::endl;

	setValue(value);
}

void inData::setValue(double value)
{
	this->value = value;
}

void inData::getValues(void) const
{
	std::cout << this->year << "-" << this->month << "-" << this->day << " | " << std::fixed << this->value << std::endl;
}