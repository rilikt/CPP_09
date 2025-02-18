/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:33 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/18 17:48:47 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
Notes:
decide on Containers, prlly vector and list.
what is the best way to nest pairs?
	TUPLES? PAIRS? NESTED CONTAINERS?

`jot -r 21 10 | tr '\n' ' '`

Error handling for input

*/
void firstContainer(int argc, char **argv)
{
	Vec vec;

	vec.storeArgs(argc, argv);
	auto start_time = std::chrono::high_resolution_clock::now();
	vec.recursivePairs();
	vec.insert();
	vec.printMP();
	auto end_time = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration<double>(end_time - start_time);
	std::cout << "Time: " <<  elapsed.count() << std::endl;

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
