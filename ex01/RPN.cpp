/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:25 by timschmi          #+#    #+#             */
/*   Updated: 2025/04/27 16:00:40 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//Input parsing
void RPN::parseInput(std::string str)
{
	std::regex pattern(R"((\d+|\*|\+|-|/)|(\S+))");
	std::string op;
	
	auto begin = std::sregex_iterator(str.begin(), str.end(), pattern);
	auto end = std::sregex_iterator();

	for (auto it = begin; it != end; it++)
	{
		if (it->str(2).length() || it->str(1).length() > 1)
			throw std::runtime_error("Invalid input: '" + it->str() + "' only values up to 9 and '+ - / *' operators allowed.");
		if (!opCheck(it->str(1)))
			this->stack.push(std::stod(it->str(1)));
		else
		{
			op = it->str(1);
			doMath(op);
		}
	}
}

double RPN::matchOperation(double *arr, std::string op)
{
	if (op == "+")
		return(arr[0] + arr[1]);
	else if (op == "-")
		return(arr[0] - arr[1]);
	else if (op == "*")
		return(arr[0] * arr[1]);
	else if (op == "/")
	{
		if (arr[1] == 0)
			throw std::runtime_error("Dividision by 0 not possible");
		return(arr[0] / arr[1]);
	}
	else
		throw std::runtime_error("Input invalid");
}

int RPN::opCheck(std::string op)
{
	if (op == "+" || op == "-" || op == "*" || op == "/")
		return (1);
	else
		return (0);
}

void RPN::doMath(std::string op)
{
	double arr[2];

	if (this->stack.size() < 2)
		throw std::runtime_error("Invalid operation");
	for (int i = 1; i >= 0; i--, this->stack.pop())
		arr[i] = (this->stack.top());
	this->stack.push(matchOperation(arr, op));
}

//Printing
void RPN::printStack(void) const
{
	if (this->stack.size() != 1)
		throw std::runtime_error("Invalid operation, please check your input.");
	else
		std::cout << std::defaultfloat << (this->stack.top()) << std::endl;
}
