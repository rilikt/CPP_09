/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:07:40 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/22 12:54:11 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <regex>
#include <fstream>
#include <string>

void validateInput(char *str);
void parseLine(char *str);
void checkDate(std::string year_str, std::string month_str, std::string day_str);
void checkValue(std::string value_str);