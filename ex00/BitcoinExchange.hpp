/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:07:40 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/25 08:19:44 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <vector>

class inData
{
  private:
	int year = 0;
	int month = 0;
	int day = 0;
	double value = 0;

	bool invalid = false;

	std::string input;
	std::string msg;

  public:
	inData() = default;
	inData(const inData &other) = default;
	inData &operator=(const inData &other) = default;
	~inData() = default;

	//setters
	void setDate(int year, int month, int day);
	void setValue(double value);
	void setError(std::string msg);

	//getters
	void getValues(void) const;

	//checks
	void	checkDate(std::string year_str, std::string month_str, std::string day_str);
	void	checkValue(std::string value_str);

};

class BitcoinExchange
{
  private:
	std::vector<inData> in_data;

  public:
	void addData(inData d);
	void printContainer(void) const;
	void parseLine(char *str);
};

void	validateInput(char *str);