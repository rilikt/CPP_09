/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h4ns <h4ns@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:23 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/30 11:44:44 by h4ns             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <regex>
#include <cctype>
#include <iomanip>

class RPN
{
	private:
	std::deque<std::string> queue;

	public:
	//Con- Destructors
	RPN() = default;
	RPN(const RPN &other) = default;
	RPN& operator=(const RPN &other) = default;
	~RPN() = default;
	//Input Parsing
	void parseInput(std::string str);
	//Print queue
	void printQueue(void) const;
	//Do math
	void doMath(std::string op);
	double matchOperation(double *arr, std::string op);
	//Checker
	int opCheck(std::string op);
};