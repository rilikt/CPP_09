/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:23 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/28 12:13:11 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <regex>

class RPN
{
	private:
	std::stack<char> stack;
	std::queue<char> queue;

	public:
	//Con- Destructors
	RPN() = default;
	RPN(const RPN &other) = default;
	RPN& operator=(const RPN &other) = default;
	~RPN() = default;
	//Input Parsing
	void parseInput(std::string str);

};