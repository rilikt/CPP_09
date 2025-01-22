/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:43:56 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/22 11:16:05 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
Notes:

-Dates are ordered in the .csv file
	- so maybe using a orderd map with the date as key and populating it by date value(ascending)
	- then keeping track what line we are in csv, to avoid reading through the entire document more than once


*/


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
