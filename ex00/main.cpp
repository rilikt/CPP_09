/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:43:56 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/22 10:23:12 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			//Open, Read input file
			validateInput(argv[1]);
			//Parse input
			//Find corresponding dates in data file and calc value
			//Print results
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Invalid ammount of arguments given. (file with contents in the format date | value expected)" << std::endl;

	return (0);
}
