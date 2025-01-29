/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:23 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/29 16:07:06 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <regex>
#include <cctype>

class RPN
{
	private:
	std::stack<char> stack;
	std::deque<std::string> queue;
	double tmp;
	bool temp_set = false;
	// double result;

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
	void doMath(void);
	double matchOperand(std::string *str, std::string op);
	//Getter
	double getTemp(void);
	//Setter
	void setTemp(double d);

};