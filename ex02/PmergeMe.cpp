/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:10:30 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/03 11:23:18 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Input / Argument handling
void Vec::storeArgs(int argc, char **argv)
{
	int i = 1;
	int a;
	int b;
	for (int j = 0; i+1 < argc; i+=2, j++)
	{
		if ((a = std::stoi(argv[i])) < 0 || (b = std::stoi(argv[i+1])) < 0)
			throw std::runtime_error("Only positve vales accepted.");

		this->pair.push_back(std::make_pair(std::vector<int>(), std::vector<int>()));

		this->pair[j].first.push_back(a < b ? a : b);
		this->pair[j].second.push_back(b > a ? b : a);
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
	if (pair.size() == 1)
		return;

	int i = 0;
	std::vector<std::pair<std::vector<int>, std::vector<int>>> p;
	auto it = pair.begin();

	for (; it != pair.end() && std::next(it) != pair.end(); i++, it+=2)
	{
		p.push_back(std::make_pair(std::vector<int>(), std::vector<int>()));

		for (auto it2 : it->first)
			p[i].first.push_back(it2);
		for (auto it2 : it->second)
			p[i].first.push_back(it2);

		for (auto it2 : std::next(it)->first)
				p[i].second.push_back(it2);
		for (auto it2 : std::next(it)->second)
				p[i].second.push_back(it2);

		if (p[i].first.back() > p[i].second.back())
			std::swap(p[i].first, p[i].second);
		std::cout << "Loop: " << i << std::endl;
	}
	std::cout << "Exit main loop" << std::endl;
	for (;it != pair.end(); it++)
	{
		for (auto it2 : it->first)
			unpaired.push_back(it2);
		for (auto it2 : it->second)
			unpaired.push_back(it2);
	}
	this->pair.clear();
	this->pair = p;
	std::cout << "Pair size: " << pair.size() << std::endl;
	recursivePairs();
}




























































// Utility
void Vec::print(void) const
{
	for (auto it = pair.begin(); it != pair.end(); it++)
	{
		for (auto it2 = it->first.begin(); it2 != it->first.end(); it2++)
			std::cout << *it2 << " ";
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
			std::cout << *it2 << " ";
		std::cout << std::endl;
	}
	std::cout << "Unpaired: ";
	for (auto it: unpaired)
		std::cout << it << " ";
	std::cout << std::endl;
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
