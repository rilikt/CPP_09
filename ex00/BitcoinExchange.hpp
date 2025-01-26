/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:07:40 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/26 10:36:59 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>

class inData
{
  private:
	int year = 0;
	int month = 0;
	int day = 0;
	double value = 0;
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
	//getters
	int getYear(void) const;
	int getMonth(void) const;
	int getDay(void) const;
	double getValue(void) const;
	//printer
	void printValues(void) const;
	//checks
	void	checkDate(std::string year_str, std::string month_str, std::string day_str);
	void	checkValue(std::string value_str);
};

class BitcoinExchange
{
  private:
	std::vector<inData> in_data;

  public:
	//Con- Destructor
	BitcoinExchange() = default;
	BitcoinExchange(const BitcoinExchange &other) = default;
	BitcoinExchange& operator=(const BitcoinExchange &other) = default;
	~BitcoinExchange() = default;
	//Adding elements to container
	void addData(inData d);
	//Printing
	void printContainer(void) const;
	//Handling file input
	void parseLine(char *str, int line);
	void readInput(char *str);
	void sortInput(void);
};
