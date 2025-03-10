/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:33 by timschmi          #+#    #+#             */
/*   Updated: 2025/03/10 15:24:22 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Containers.hpp"

/*
Notes:
`jot -r 21 10 | tr '\n' ' '`
*/

void firstContainer(int argc, char **argv)
{
	Vec vec;

	FordJohnson(vec, vec.getUP(), argc, argv);
}

void secondContainer(int argc, char **argv)
{
	Dq dq;
	FordJohnson(dq, dq.getUP(), argc, argv);
}

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		try
		{
			firstContainer(argc, argv);
			secondContainer(argc, argv);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Not enough arguments provided. Please enter a list of postive interger values to be sorted." << std::endl;
	}
	return(0);
}
