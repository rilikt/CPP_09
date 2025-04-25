/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:43:58 by timschmi          #+#    #+#             */
/*   Updated: 2025/03/10 15:59:18 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Open file and read from it
void BitcoinExchange::readInput(const char *str)
{
	std::ifstream file(str);
	std::string line;
	int i = 0;
	bool is_csv = (std::string(str) == "data.csv");

	if(!file.is_open())
		throw std::runtime_error("Could not access file");

	while (std::getline(file, line))
	{
		if (line.empty()) continue;
		parseLine(line.data(), is_csv ? -1 : ++i);
	}

	file.close();
}

void BitcoinExchange::findMatch()
{
	auto it = this->in_data_cpy.begin();
	auto csv_it = this->csv.begin();

	while (it != this->in_data_cpy.end())
	{
		if (it->isInvalid())
		{
			it++;
			continue;
		}
		
		while (csv_it != this->csv.end() && *csv_it < *it)
			csv_it++;
		if (csv_it != this->csv.end() && *csv_it == *it)
			it->setResult(csv_it->getValue(), "calc");
		else if (csv_it != this->csv.begin())
			it->setResult(std::prev(csv_it)->getValue(), "calc");
		it++;
	}
	setValue();
}

void BitcoinExchange::setValue()
{
	auto it = this->in_data.begin();

	while (it != this->in_data.end())
	{
		for (auto it2 = this->in_data_cpy.begin(); it2 != this->in_data_cpy.end(); it2++)
		{
			if (it2->getLine() == it->getLine())
				it->setResult(it2->getResult(), "set");
		}
		it++;
	}

}

int inData::getLine(void) const
{
	return this->line;
}

void inData::setResult(double input, std::string mode)
{
	if (mode == "calc")
		this->result = this->value * input;
	else if (mode == "set")
		this->result = input;
}

bool inData::isInvalid(void) const
{
	return (this->invalid);
}

double inData::getResult(void) const
{
	return this->result;
}

//Parse file line by line and add to container
void BitcoinExchange::parseLine(char *str, int i)
{
	inData d;
	std::regex format(R"((\s*(date)\s*\|\s*(value)\s*)|(\s*date\s*,\s*exchange_rate\s*))", std::regex_constants::icase);
	std::regex line(R"(\s*(\d+-\d+-\d+)\s*\|\s*((\+?|-?)(\d*\.?\d*))\s*)");
	std::regex csvline(R"(\s*(\d+-\d+-\d+)\s*,\s*((\+?|-?)(\d*\.?\d*))\s*)");
	std::regex date(R"((\d{4})-(\d{2})-(\d{2}))");
	std::regex value(R"((\+?|-?)(\d+)|(\d*\.\d+)|(\d+\.\d*))");
	std::cmatch lm;
	std::smatch dm;
	std::smatch vm;

	if (std::regex_match(str, format))
		return;
	d.setInput(str, i);
	if (std::regex_match(str, lm, line) || (i == -1 && std::regex_match(str, lm, csvline)))
	{
		std::string date_val = lm.str(1);
		std::string val_val = lm.str(2);
		if (std::regex_match(date_val, dm, date))
			d.checkDate(dm.str(1), dm.str(2), dm.str(3));
		else
			d.setError("Bad date format. Expected: YYYY-MM-DD");
		if (std::regex_match(val_val, vm, value))
			d.checkValue(vm.str());
		else
			d.setError("Invalid btc ammount format (only int or double)");
	}
	else
		d.setError("Invalid input type. Expected: 'YYYY-MM-DD | btc ammount (int or double)'");
	if (i >= 0)
		addData(d, "in_data");
	else
		addData(d, "csv");
}



//validate Data
void inData::checkDate(std::string year_str, std::string month_str, std::string day_str)
{
	int year = std::stoi(year_str);
	int month = std::stoi(month_str);
	int day = std::stoi(day_str);
	int max = 31;
	
	if ((year > 2022 || (year == 2022 && (month > 3 || (month == 3 && day > 29)))) || (year < 2009 || (year == 2009 && month == 1 && day == 1)))
	{
		setError("Date out of database range");
		setDate(year, month, day);
		return;
	}
	if (year < 2009 || year > 2022)
		setError("Year outside of database (2009 - 2022)");
	if (month < 1 || month > 12)
		setError("Month out of range (1 - 12)");

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		max = 31;
	else if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				max = 29;
		else
			max = 28;
	}
	else
		max = 30;
	if (day < 1 || day > max)
		setError("Day out of range (1 - " + std::to_string(max) + ")");

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
void BitcoinExchange::addData(inData d, std::string container)
{
	if (container == "csv")
		this->csv.push_back(d);
	else
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
void BitcoinExchange::sortInput()
{
	this->in_data_cpy = this->in_data;
	
	this->in_data_cpy.sort();
	this->csv.sort();
}

bool inData::operator<(const inData &other) const
{
	if (year != other.year) return year < other.year;
	if (month != other.month) return month < other.month;
	return day < other.day;
}

bool inData::operator==(const inData &other) const
{
	return year == other.year && month == other.month && day == other.day;
}


//Printing
void BitcoinExchange::printContainer(int i) const
{
	if (i == 1)
	{
		std::cout << "Printing Container in_data..." << std::endl;
		for(const auto &it: this->in_data)
			it.printValues();
	}
	else if (i == 2)
	{
		std::cout << "Printing Container csv..." << std::endl;
		for(const auto &it: this->csv)
			it.printValues();
	}
	else
	{
		std::cout << "Printing Container in_data_cpy..." << std::endl;
		for(const auto &it: this->in_data_cpy)
			it.printValues();
	}
}

void inData::printValues(void) const
{
	if (this->invalid)
		std::cerr << this->msg << " | Input line " << this->line << ": '" + this->input + "'" << std::endl;
	else
	{
		std::cout << this->year;  
		(this->month < 10) ? std::cout << "-0" : std::cout << "-"; 
		std::cout << this->month;
		(this->day < 10) ? std::cout << "-0" : std::cout << "-"; 
		std::cout << this->day << " | " << std::defaultfloat << this->value << " => " << this->result << std::endl;	
	}
}

