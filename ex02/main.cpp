/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:33 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/01 14:25:33 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


/*
Notes:
decide on Containers, prlly vector and list.
what is the best way to nest pairs?

*/

int* convertInput(int argc, char **argv)
{
	argc--;
	int *arr = new int[argc];

	for (int i = 0; i < argc; i++)
	{
		arr[i] = std::stoi(argv[i+1]); 
		std::cout << arr[i] << std::endl;
	}
	return arr;
}

void formPairs(int *arr, int size)
{
	int pair_count = (size-1) / 2;
	int i = 0;
	std::vector<std::pair<int, int>> pairs;
	std::vector<int> unpaired;
	std::cout << "Inital pairs: " << pair_count << std::endl;
	
	for (; i/2 < pair_count; i+=2)
	{
		pairs.push_back({arr[i], arr[i+1]});
	}
	if (i != size)
		unpaired.push_back(arr[i]);
	for (auto it : pairs)
		std::cout << it.first << " " << it.second << std::endl;
	std::cout << "Left alone: " << unpaired.front() << std::endl;
}

int main(int argc, char **argv)
{
	int *arr;
	arr = convertInput(argc, argv);
	formPairs(arr, argc);
}