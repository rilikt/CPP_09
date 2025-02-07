/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:15 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/07 15:03:39 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>

class Vec
{
	public:
	std::vector<std::pair<std::vector<int>, std::vector<int>>> pair;
	std::vector<int> unpaired; //myb nested vector would be better

	std::vector<std::vector<int>> main;
	std::vector<std::pair<std::vector<int>, std::vector<int>::iterator>> pend;

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
