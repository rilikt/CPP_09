/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:10:30 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/07 14:59:52 by timschmi         ###   ########.fr       */
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
	std::vector<int> up;
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
	}
	for (;it != pair.end(); it++)
	{
		for (auto it2 : it->first)
			up.push_back(it2);
		for (auto it2 : it->second)
			up.push_back(it2);
		for (auto it2 : unpaired)
			up.push_back(it2);
		this->unpaired.clear();
		this->unpaired = up;
	}
	this->pair.clear();
	this->pair = p;
	recursivePairs();
}

void Vec::insert(void)
{
	static int size = this->pair.at(0).first.size();
	std::vector<std::vector<int>> mc;
	std::cout << "Element Size: " << size << std::endl;

	if (!size)
		return;

	if (size == this->pair.at(0).first.size())
	{
		for (auto it: pair)
		{
			main.push_back(it.first);
			main.push_back(it.second);
		}
		size /= 2;
		printMP();
		insert();
		return;
	}

	for(auto it = main.begin(); it != main.end(); it++)
	{
		std::vector<int> tmp(it->begin(), std::next(it->begin(), size));
		std::vector<int> tmp2(std::next(it->begin(), size), it->end());

		mc.push_back(tmp);
		mc.push_back(tmp2);
	}
	main = mc;

	for (auto it = std::next(main.begin(), 2); it != main.end(); it = std::next(it, 2))
	{
		pend.push_back(*it);
	}
	if (size == 1)
		size = 0;
	else
		size /= 2;
	printMP();
	pend.clear();
	insert();
}













void Vec::printMP(void) const
{
	std::cout << "Main:" << std::endl;
	for (auto it : main)
	{
		for (auto it2 : it)
			std::cout << it2 << " ";
		std::cout << "| ";
	}
	
	std::cout << "Pend:" << std::endl;
	for (auto it : pend)
	{
		for (auto it2 : it)
			std::cout << it2 << " ";
		std::cout << "| ";
	}

	std::cout << "Unpaired: ";
	for (auto it: unpaired)
		std::cout << it << " ";
	
	std::cout << std::endl;
}


















































// Utility
void Vec::print(void) const
{
	std::cout << "Pair size: " << pair.size() << std::endl;
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
