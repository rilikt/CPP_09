/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:07:40 by timschmi          #+#    #+#             */
/*   Updated: 2025/03/10 15:49:18 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <cstring>
#include <algorithm>
#include <list>
#include <iterator>

class inData
{
  private:
	int year = 0;
	int month = 0;
	int day = 0;
	double value = 0;
	double result = 0;
	bool invalid = false;
	std::string input;
	int line = 0;
	std::string msg;

  public:
	//Con- Destructor
	inData() = default;
	inData(const inData &other) = default;
	inData &operator=(const inData &other) = default;
	~inData() = default;
	//setters
	void setDate(int year, int month, int day);
	void setValue(double value);
	void setError(std::string msg);
	void setInput(std::string input, int line);
	void setResult(double input, std::string mode);
	//getters
	int getYear(void) const;
	int getMonth(void) const;
	int getDay(void) const;
	double getValue(void) const;
	bool isInvalid(void) const;
	int getLine(void) const;
	double getResult(void) const;
	//printer
	void printValues(void) const;
	//checks
	void	checkDate(std::string year_str, std::string month_str, std::string day_str);
	void	checkValue(std::string value_str);
};

class BitcoinExchange
{
  private:
	std::list<inData> in_data;
	std::list<inData> in_data_cpy;
	std::list<inData> csv;

  public:
	//Con- Destructor
	BitcoinExchange() = default;
	BitcoinExchange(const BitcoinExchange &other) = default;
	BitcoinExchange& operator=(const BitcoinExchange &other) = default;
	~BitcoinExchange() = default;
	//Adding elements to container
	void addData(inData d, std::string container);
	//Printing
	void printContainer(int i) const;
	//Handling file input
	void parseLine(char *str, int line);
	void readInput(const char *str);
	void sortInput(void);
	void readData(void);
	//Matching values
	void findMatch();
	// Setter
	void setValue();

};
