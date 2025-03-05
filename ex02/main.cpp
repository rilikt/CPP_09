/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:33 by timschmi          #+#    #+#             */
/*   Updated: 2025/03/05 16:11:48 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
// #include "deque.cpp"
// #include "temp.cpp"

/*
Notes:
decide on Containers, prlly vector and list.
what is the best way to nest pairs?
	TUPLES? PAIRS? NESTED CONTAINERS?

`jot -r 21 10 | tr '\n' ' '`

Error handling for input

*/
// void firstContainer(int argc, char **argv)
// {
// 	Vec vec;

// 	std::cout << "First Container:" << std::endl;
// 	storeArgs(vec.pair, vec.unpaired, argc, argv);
// 	auto start_time = std::chrono::high_resolution_clock::now();
// 	recursivePairs(vec.pair, vec.unpaired);
// 	insert(vec.pair, vec.unpaired, vec.main, vec.pend);
// 	vec.printMP();
// 	auto end_time = std::chrono::high_resolution_clock::now();
// 	auto elapsed = std::chrono::duration<double>(end_time - start_time);
// 	std::cout << "Time: " <<  elapsed.count() << std::endl;

// }

void secondContainer(int argc, char **argv)
{
	Dq dq;
	FordJohnson(dq, dq.unpaired, argc, argv);
	// std::cout << "Second Container:" << std::endl;
	// auto start_time = std::chrono::high_resolution_clock::now();
	// storeArgs(dq.pair, dq.unpaired, argc, argv);
	// // dq.printPairs();
	// recursivePairs(dq.pair, dq.unpaired);
	// // dq.printPairs();
	// insert(dq.pair, dq.unpaired, dq.main, dq.pend);
	// dq.printMain();
	// auto end_time = std::chrono::high_resolution_clock::now();
	// auto elapsed = std::chrono::duration<double>(end_time - start_time);
	// std::cout << "Time: " <<  elapsed.count() << std::endl;


}


int main(int argc, char **argv)
{
	try
	{
		// firstContainer(argc, argv);
		secondContainer(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
