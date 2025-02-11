/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:33 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/11 15:13:14 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
Notes:
decide on Containers, prlly vector and list.
what is the best way to nest pairs?
	TUPLES? PAIRS? NESTED CONTAINERS?

Error handling for input

*/
void firstContainer(int argc, char **argv)
{
	Vec vec;

	vec.storeArgs(argc, argv);
	// vec.print();
	vec.recursivePairs();
	// vec.print();
	vec.insert();
	std::cout << "--- after ---" << std::endl;
	vec.printMP();

}


int main(int argc, char **argv)
{
	try
	{
		firstContainer(argc, argv);
		// secondContainer(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
