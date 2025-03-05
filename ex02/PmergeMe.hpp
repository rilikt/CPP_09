/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:15 by timschmi          #+#    #+#             */
/*   Updated: 2025/03/05 16:25:13 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <deque>
#include <type_traits>

#include "template.tpp"

class Vec
{
	private:
	
	//Insertion
	void jInsert(void);
	void binSearch(int e);
	std::vector<std::vector<int>>::iterator findPartner(int e);
	
	public:
		std::vector<std::pair<std::vector<int>, std::vector<int>>> pair;
		std::vector<int> unpaired; //myb nested vector would be better
		int count = 0;
		std::vector<std::vector<int>> main;
		std::vector<std::pair<std::vector<int>, int>> pend;
		//De- Constructor
		Vec() = default;
		Vec(const Vec &other) = default;
		Vec& operator=(const Vec &other) = default;
		~Vec() = default;

		//Argument handling
		void storeArgs(int argc, char **argv);
		//Pairing
		void recursivePairs(void);
		//Printing
		void print(void) const;
		void printMP(void) const;
		//Insertion
		void insert(void);
};

class Dq
{
	private:
	// int count = 0;
		int argc;
		char **argv;
	
	public:
		std::deque<std::pair<std::deque<int>, std::deque<int>>> pair;
		std::deque<int> unpaired;
		std::deque<std::deque<int>> main;
		std::deque<std::pair<std::deque<int>, int>> pend;
		//De- Constructor
		Dq() = default;
		Dq(const Dq &other) = default;
		Dq& operator=(const Dq &other) = default;
		~Dq() = default;

		void printPairs(void) const;
		void printMain(void) const;

		//Getters
		std::deque<std::pair<std::deque<int>, std::deque<int>>>& getPair(void) {return pair;};
		std::deque<int>& getUnpaired(void) {return unpaired;};

		//Setters
		void setArgs(int c, char **v) {argc = c, argv = v;};


};


template <typename Class, typename TestContainer, typename = std::enable_if_t<ContainerCheck<TestContainer>::value>>
void FordJohnson(Class c, TestContainer &unpaired, int argc, char **argv);

template <typename ContainerPair, typename ContainerUnPaired>
void storeArgs(ContainerPair &pair, ContainerUnPaired &unpaired, int argc, char **argv);

template <typename ContainerPair, typename ContainerUnPaired>
void recursivePairs(ContainerPair &pair, ContainerUnPaired &unpaired);

template <typename Main, typename Pend>
auto findPartner(int e, Main &main, Pend &pend);

template <typename Main, typename Pend>
void binSearch(int e, Main &main, Pend &pend);

template <typename Main, typename Pend, typename Unpaired>
void jInsert(Main &main, Pend &pend, Unpaired &unpaired);

template <typename Pair, typename Unpaired, typename Main, typename Pend>
void insert(Pair &pair, Unpaired &unpaired, Main &main, Pend &pend);






void Dq::printPairs(void) const
{
	for (auto e : pair)
	{
		for (auto f : e.first)
			std::cout << f << " ";
		std::cout << "| ";
		for (auto s : e.second)
			std::cout << s << " ";
		std::cout << std::endl;
	}
}


void Dq::printMain(void) const
{
	for(auto e : main)
	{
		for (auto n : e)
			std::cout << n << " ";
	}
	std::cout << std::endl;
}

void Vec::printMP(void) const
{
	std::cout << "Main:" << std::endl;
	for (auto it : main)
	{
		for (auto it2 : it)
			std::cout << it2 << " ";
		// std::cout << "| ";
	}
	std::cout << std::endl;
	// std::cout << "Pend:" << std::endl;
	// for (auto it : pend)
	// {
	// 	for (auto it2 : it.first)
	// 		std::cout << it2 << " ";
	// 	std::cout << "a: " << it.second;
	// 	std::cout << "| ";
	// }
	// std::cout << std::endl;
	// std::cout << "Unpaired: ";
	// for (auto it: unpaired)
	// 	std::cout << it << " ";
	
	// std::cout << std::endl;
	std::cout << "Count: " << count << std::endl;
}