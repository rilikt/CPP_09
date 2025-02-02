/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:10:30 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/02 15:40:00 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


// Input / Argument handling
void Vec::storeArgs(int argc, char **argv)
{
	int i = 1;
	int a;
	int b;
	for (; i+1 < argc; i+=2)
	{
		if ((a = std::stoi(argv[i])) < 0 || (b = std::stoi(argv[i+1])) < 0)
			throw std::runtime_error("Only positve vales accepted.");
		if (a > b)
			this->pair.push_back({b, a});
		else
			this->pair.push_back({a, b});
	}
	if (i != argc)
	{
		if ((a = std::stoi(argv[i])) < 0)
			throw std::runtime_error("Only positve vales accepted.");
		this->unpaired.push_back(a);
	}
}

void Vec::recursivePairs(void)
{

	for (auto it = pair.begin(); it != pair.end() -1; it++)
	{
		if (std::next(it) != pair.end())
		{
			for (auto it2: *std::next(it))
				it->push_back(it2);
	
			std::next(it)->clear();
			pair.erase(std::next(it));
			std::cout << "eyo" << std::endl;
		}
	}
}




























































// Utility
void Vec::print(void) const
{
	for (auto it: pair)
		std::cout << it.front() << " " << it.back() << std::endl;
	for (auto it: unpaired)
		std::cout << it << std::endl;
}








// void Pair::checkSort(void)
// {
// 	int tmp;
// 	if (this->smol > big)
// 	{
// 		tmp = big;
// 		big = smol;
// 		smol = tmp;
// 	}
// }
