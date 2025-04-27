/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:43:56 by timschmi          #+#    #+#             */
/*   Updated: 2025/04/27 10:54:16 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	if (argc == 2)
	{
		try
		{
			//Open, Read input file and given data.csv
			btc.readInput("data.csv");
			btc.readInput(argv[1]);
			//Sort Copy of the container to compare with data.csv
			btc.sortInput();
			//Find closest date sum and calculate value
			btc.findMatch();
			//Print results
			btc.printContainer(1);
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
