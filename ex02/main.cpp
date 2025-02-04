/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:33 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/04 15:46:19 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
Notes:
decide on Containers, prlly vector and list.
what is the best way to nest pairs?
	TUPLES? PAIRS? NESTED CONTAINERS?

*/
void firstContainer(int argc, char **argv)
{
	Vec vec;

	vec.storeArgs(argc, argv);
	vec.print();
	vec.recursivePairs();
	// vec.print();

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
