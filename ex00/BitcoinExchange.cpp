/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h4ns <h4ns@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:43:58 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/23 20:31:33 by h4ns             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::addData(t_data d)
{
	this->in_data.push_back(d);
}

void BitcoinExchange::printContainer() const
{
	std::cout << "Printing Container..." << std::endl;
	for(auto &it: this->in_data)
		std::cout << it.year << " " << it.value << std::endl;
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
			btc.addData(parseLine(line.data()));
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

t_data parseLine(char *str) 
{
	t_data d;
	std::regex line(R"(\s*(\d+-\d+-\d+)\s*\|\s*((\+?|-?)(\d*\.?\d*))\s*)");
	std::regex date(R"((\d{4})-(\d{2})-(\d{2}))");
	std::regex value(R"((\+?|-?)(\d+)|(\d*\.\d+)|(\d+\.\d*))");

	std::cmatch lm;
	std::cmatch dm;
	std::cmatch vm;

	if (std::regex_match(str, lm, line))
	{
		d.input = lm.str(1) + lm.str(2);
		std::cout << "Match: " << lm.str(2) << std::endl;
		if (std::regex_match(lm.str(1).data(), dm, date))
			d = checkDate(dm.str(1), dm.str(2), dm.str(3), d);
		else
			std::cerr << "Bad date format" << std::endl;
		if (std::regex_match(lm.str(2).data(), vm, value))
			checkValue(vm.str(), d);
		else
			std::cerr << "Invalid btc ammount format (only int or double)" << std::endl;
	}
	else
		std::cerr << "Invalid input type. Expected: 'YYYY-MM-DD | btc ammount (int or double)'" << std::endl;

	return d;
}

t_data checkDate(std::string year_str, std::string month_str, std::string day_str, t_data d)
{
	d.year = std::stoi(year_str);
	d.month = std::stoi(month_str);
	d.day = std::stoi(day_str);

	if (d.year < 2009 || d.year > 2022)
		std::cerr << "Year outside of database (2009 - 2022)" << std::endl;
	if (d.month < 1 || d.month > 12)
		std::cerr << "Month out of range (1 - 12)" << std::endl;
	if (d.day < 1 || d.day > 31)
		std::cerr << "Day out of range (1 - 31)" << std::endl;

	std::cout << d.year << " " << d.month << " " << d.day << std::endl;

	return d;
}

void checkValue(std::string value_str, t_data &d)
{
	d.value = std::stod(value_str);

	if (d.value > std::numeric_limits<int>::max())
		std::cerr << "Too large number" << std::endl;
	else if (d.value < 0.0)
		std::cerr << "Not a positive ammount" << std::endl;
	else
		std::cout << std::fixed << d.value << std::endl; //what is the right precision / display-type here?
}
