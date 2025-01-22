/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:43:58 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/22 11:10:32 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void validateInput(char *str)
{
	std::ifstream file(str);
	std::string line;

	if(file.is_open())
	{
		std::cout << "File opened" << std::endl;
		std::cout << "- Reading input file: -" << std::endl;
		while (std::getline(file, line))
		{
			std::cout << line << std::endl;
			parseLine(line.data());
		}
		std::cout << "---" << std::endl;
	}
	else
		throw std::runtime_error("Could not access file");
	file.close();
}


void parseLine(char *str) //seperate date into parts and check if valid
{
	std::regex values(R"((\d+-\d+-\d+) \s*\|\s* (\d*\.?\d*))");

	std::cmatch cm;

	if (std::regex_match(str, cm, values))
		std::cout << "Match: " << cm.str(2) << std::endl;
	else
		std::cout << "nyo" << std::endl;

}
