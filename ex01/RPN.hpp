/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:23 by timschmi          #+#    #+#             */
/*   Updated: 2025/04/27 15:56:11 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <regex>
#include <cctype>
#include <cmath>
#include <iomanip>

class RPN
{
	private:
	std::stack<double> stack;

	public:
	//Con- Destructors
	RPN() = default;
	RPN(const RPN &other) = default;
	RPN& operator=(const RPN &other) = default;
	~RPN() = default;
	//Input Parsing
	void parseInput(std::string str);
	//Print queue
	void printStack(void) const;
	//Do math
	void doMath(std::string op);
	double matchOperation(double *arr, std::string op);
	//Checker
	int opCheck(std::string op);
};