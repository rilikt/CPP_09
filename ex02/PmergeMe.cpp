/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:10:30 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/17 15:40:54 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int jnum[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

// Input / Argument handling
void Vec::storeArgs(int argc, char **argv)
{
	int i = 1;
	int a;
	int b;
	for (int j = 0; i+1 < argc; i+=2, j++)
	{
		if ((a = std::stoi(argv[i])) < 0 || (b = std::stoi(argv[i+1])) < 0)
			throw std::runtime_error("Only positve values accepted.");

		this->pair.push_back(std::make_pair(std::vector<int>(), std::vector<int>()));

		this->pair[j].first.push_back(a);
		this->pair[j].second.push_back(b);
		if (pair[j].first.back() > pair[j].second.back())
			std::swap(pair[j].first, pair[j].second);
		count++;
	}
	if (i != argc)
	{
		if ((a = std::stoi(argv[i])) < 0)
			throw std::runtime_error("Only positve values accepted.");
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
		count++;
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

		if (it == main.begin() || !(std::distance(main.begin(), it)+1 % 2))
			mc.push_back(tmp);
		else
			pend.push_back(std::make_pair(tmp, tmp2.back()));
		mc.push_back(tmp2);
	}
	main = mc;

	std::cout << "-- After Splitting:" << std::endl;
	printMP();

	jInsert();

	std::cout << "-- After Insertion:" << std::endl;
	pend.clear();
	printMP();

	size /= 2;
	insert();
}


void Vec::binSearch(int e)
{
	auto it = findPartner(e);
	int range = std::distance(main.begin(), it);
	if (range == 0)
		throw std::runtime_error("Error in binSearch, invalid range");
	std::cout << "Range: " << range << std::endl;

	std::cout << "Pair Nr: "<< e << " | " << pend[e].first.back() << " " << pend[e].second << std::endl;

	auto first = main.begin();
	auto it2 = first;
	int step;

	while (range > 0)
	{
		it2 = first;
		step = range / 2;
		std::advance(it2, step);
		std::cout << it2->back() << std::endl;
		if (pend[e].first.back() > it2->back())
		{
			std::cout << "larger" << std::endl;
			first = ++it2;
			range -= step + 1;
		}
		else
			range = step;
		count++;
	}
	main.insert(it2, pend[e].first);
}


void Vec::jInsert(void)
{
	int i  = 1;
	int size = pend.size();
	while (size >= jnum[i] - jnum[i-1])
	{
		for (int e = jnum[i] - 2; e >= jnum[i-1]-1; e--, size--)
		{
			std::cout << "e: " << e << std::endl;
			binSearch(e);
		}
		i++;
	}
	while (unpaired.size() >= main[0].size())
	{
		std::vector<int> tmp(unpaired.begin(), std::next(unpaired.begin(), main[0].size()));
		unpaired.erase(unpaired.begin(),  std::next(unpaired.begin(), main[0].size()));
		pend.push_back(std::make_pair(tmp, main.back().back()));
		// binSearch(pend.size() -1);
		size++;
	}
	while (size)
	{
		std::cout << "LEFTOVERS" << std::endl;
		for (int b = pend.size() - 1; b != jnum[i-1] -2; b--, size--)
			binSearch(b);
	}
}



std::vector<std::vector<int>>::iterator Vec::findPartner(int e)
{
	for (auto it = main.begin(); it != main.end(); it++)
	{
		if (pend[e].second == it->back())
			return it;
	}
	return(main.end());
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
	std::cout << std::endl;
	std::cout << "Pend:" << std::endl;
	for (auto it : pend)
	{
		for (auto it2 : it.first)
			std::cout << it2 << " ";
		std::cout << "a: " << it.second;
		std::cout << "| ";
	}
	std::cout << std::endl;
	std::cout << "Unpaired: ";
	for (auto it: unpaired)
		std::cout << it << " ";
	
	std::cout << std::endl;
	std::cout << "Count: " << count << std::endl;
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

