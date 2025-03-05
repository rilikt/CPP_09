/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:16:19 by timschmi          #+#    #+#             */
/*   Updated: 2025/03/04 15:40:54 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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