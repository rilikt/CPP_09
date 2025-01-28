/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:25 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/28 12:45:45 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void RPN::parseInput(std::string str)
{
	std::regex pattern(R"((\d{1,2}|\*|\+|-|/)|(\S*))");
	
	auto begin = std::sregex_iterator(str.begin(), str.end(), pattern);
	auto end = std::sregex_iterator();

	for (auto it = begin; it != end; it++)
	{
		std::cout << it->str(1);
		if (it->str(2).length())
			throw std::runtime_error("Invalid input: '" + it->str(2) + "' only digits and : '+ - / *' operators allowed.");
	}

	std::cout << std::endl;	
	// std::cout << str << std::endl;
}
