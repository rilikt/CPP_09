/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h4ns <h4ns@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:07:40 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/23 20:26:19 by h4ns             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <limits>
#include <vector>

typedef struct s_data
{
    int year;
    int month;
    int day;
    double value;

    bool invalid;

    std::string input;
    std::string msg;

} t_data;

class BitcoinExchange
{
    private:
    std::vector<t_data> in_data;


    public:
    void addData(t_data d);
    void printContainer(void) const;

};

void validateInput(char *str);
t_data parseLine(char *str);
t_data checkDate(std::string year_str, std::string month_str, std::string day_str, t_data d);
void checkValue(std::string value_str, t_data &d);