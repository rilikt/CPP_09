/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Containers.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:30:58 by timschmi          #+#    #+#             */
/*   Updated: 2025/03/10 15:26:47 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Containers.hpp"


//Vec
std::vector<int> &Vec::getUP(void)
{
	return this->unpaired;
}

std::vector<std::pair<std::vector<int>, std::vector<int>>> &Vec::getP(void)
{
	return this->pair;
}

std::vector<std::vector<int>> &Vec::getM(void)
{
	return this->main;
}

std::vector<std::pair<std::vector<int>, int>> &Vec::getPe(void)
{
	return this->pend;
}

std::string Vec::getName(void) const
{
	return this->name;
}


//Dq
std::deque<int> &Dq::getUP(void)
{
	return this->unpaired;
}

std::deque<std::pair<std::deque<int>, std::deque<int>>> &Dq::getP(void)
{
	return this->pair;
}

std::deque<std::deque<int>> &Dq::getM(void)
{
	return this->main;
}

std::deque<std::pair<std::deque<int>, int>> &Dq::getPe(void)
{
	return this->pend;
}

std::string Dq::getName(void) const
{
	return this->name;
}
