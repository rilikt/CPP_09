/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:15 by timschmi          #+#    #+#             */
/*   Updated: 2025/02/03 11:51:08 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <tuple>

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
