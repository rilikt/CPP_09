/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:33 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/03 08:28:58 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
Notes:
decide on Containers, prlly vector and list.
what is the best way to nest pairs?
	TUPLES? PAIRS? NESTED CONTAINERS?

*/

int main(int argc, char **argv)
{
	Vec vec;
	try
	{
		vec.storeArgs(argc, argv);
		vec.print();
		vec.recursivePairs();
		vec.print();

	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
