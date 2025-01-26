/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:43:58 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/26 11:07:20 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Open file and read from it
void BitcoinExchange::readInput(char *str)
{
	std::ifstream file(str);
	std::string line;
	int i = 0;

	if(file.is_open())
		while (std::getline(file, line))
			parseLine(line.data(), ++i);
	else
		throw std::runtime_error("Could not access file");
	file.close();
}



//Parse file line by line and add to container
void BitcoinExchange::parseLine(char *str, int i)
{
	inData d;
	std::regex format(R"(\s*([dD][aA][tT][eE])\s*\|\s*([vV][aA][lL][uU][eE])\s*)");
	std::regex line(R"(\s*(\d+-\d+-\d+)\s*\|\s*((\+?|-?)(\d*\.?\d*))\s*)");
	std::regex date(R"((\d{4})-(\d{2})-(\d{2}))");
	std::regex value(R"((\+?|-?)(\d+)|(\d*\.\d+)|(\d+\.\d*))");
	std::cmatch lm;
	std::cmatch dm;
	std::cmatch vm;

	if (std::regex_match(str, format) && i == 1)
		return;
	d.setInput(str, i);
	if (std::regex_match(str, lm, line))
	{
		if (std::regex_match(lm.str(1).data(), dm, date))
			d.checkDate(dm.str(1), dm.str(2), dm.str(3));
		else
			d.setError("Bad date format. Expected: YYYY-MM-DD");
		if (std::regex_match(lm.str(2).data(), vm, value))
			d.checkValue(vm.str());
		else
			d.setError("Invalid btc ammount format (only int or double)");
	}
	else
		d.setError("Invalid input type. Expected: 'YYYY-MM-DD | btc ammount (int or double)'");

	addData(d);
}



//validate Data
void inData::checkDate(std::string year_str, std::string month_str, std::string day_str)
{
	int year = std::stoi(year_str);
	int month = std::stoi(month_str);
	int day = std::stoi(day_str);

	if (year < 2009 || year > 2022)
		setError("Year outside of database (2009 - 2022)");
	if (month < 1 || month > 12)
		setError("Month out of range (1 - 12)");
	if (day < 1 || day > 31)
		setError("Day out of range (1 - 31)");

	setDate(year, month, day);
}

void inData::checkValue(std::string value_str)
{
	double value = std::stod(value_str);

	if (value > std::numeric_limits<int>::max())
		setError("Too large number");
	else if (value < 0.0)
		setError("Not a positive ammount");

	setValue(value);
}



//BitcoinExchange Util functions
void BitcoinExchange::addData(inData d)
{
	this->in_data.push_back(d);
}



//inData Setters
void inData::setDate(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

void inData::setValue(double value)
{
	this->value = value;
}

void inData::setError(std::string msg)
{
	this->invalid = true;
	if (!this->msg.size())
		this->msg = "Error: " + msg;
	else
		this->msg += " | " + msg;
}

void inData::setInput(std::string input, int line)
{
	this->input = input;
	this->line = line;
}



//inData getters
int inData::getYear(void) const
{
	return this->year;
}

int inData::getMonth(void) const
{
	return this->month;
}

int inData::getDay(void) const
{
	return this->day;
}

double inData::getValue(void) const
{
	return this->value;
}



//Sorting utility
bool customSort(const inData &a, const inData &b)
{
	if (a.getYear() < b.getYear())
		return true;
	else if (a.getYear() == b.getYear())
		return (a.getMonth() < b.getMonth());
	else if (a.getYear() == b.getYear() && a.getMonth() == b.getMonth())
		return (a.getDay() < b.getDay());
	else
		return false;
	// return (a.getYear() <= b.getYear() && a.getMonth() < b.getMonth() && a.getDay() < b.getDay());
}

void BitcoinExchange::sortInput()
{
	std::sort(this->in_data.begin(), this->in_data.end(), customSort);
}



//Printing
void BitcoinExchange::printContainer() const
{
	std::cout << "Printing Container..." << std::endl;
	for(auto &it: this->in_data)
		it.printValues();
}

void inData::printValues(void) const
{
	if (this->invalid)
		std::cerr << this->msg << " | Input line " << this->line << ": '" + this->input + "'" << std::endl;
	else
		std::cout << this->year << "-" << this->month << "-" << this->day << " | " << std::fixed << this->value << std::endl;
}
