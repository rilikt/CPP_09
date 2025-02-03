/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:15 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/03 07:26:04 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <tuple>

typedef struct s_int_pair
{
	int a;
	int b;
} t_int_pair;

typedef struct s_pair
{
	t_int_pair a;
	t_int_pair b;
} t_pair;

class Pair
{
	private:
	int smol;
	int big;
	public:
	void checkSort(void);
};

class ListSort
{
	public:
	std::list<int> list;
};

// template <typename T>
// class Arr
// {
// 	public:
// 	std::arr<int, T> arr;
// };

class Vec
{
	public:
	// std::vector<std::vector<int>> pair;
	std::vector<std::pair<std::vector<int>, std::vector<int>>> pair;
	// std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> pair;
	std::vector<int> unpaired;

	//Argument handling
	void storeArgs(int argc, char **argv);
	//Pairing
	void recursivePairs(void);
	//Printing
	void print(void) const;
};
