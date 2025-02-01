/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:25 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/31 13:59:48 by timschmi         ###   ########.fr       */
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
			throw std::runtime_error("Invalid input: '" + it->str() + "' only values up to 9 and : '+ - / *' operators allowed.");
		if (!opCheck(it->str(1)))
			this->queue.push_front(it->str(1));
		else
		{
			op = it->str(1);
			doMath(op);
		}
	}
	if (this->queue.size() == 2)
		doMath(op);

}


double RPN::matchOperation(double *arr, std::string op)
{
	// std::cout << "MATH: " << arr[0] << " "+op+" " << arr[1] << std::endl;
	if (op == "+")
		return(arr[0] + arr[1]);
	else if (op == "-")
		return(arr[0] - arr[1]);
	else if (op == "*")
		return(arr[0] * arr[1]);
	else if (op == "/")
	{
		if (arr[0] == 0 || arr[1] == 0)
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

	if (this->queue.size() < 2)
		throw std::runtime_error("Invalid operation");
	for (int i = 1; i >= 0; i--, this->queue.pop_front())
		arr[i] = std::stod(this->queue.front());
	this->queue.push_front(std::to_string(matchOperation(arr, op)));
}



//Printing
void RPN::printQueue(void) const
{
	// std::cout << "--------\nPrinting Queue:" << std::endl; 
	// std::deque<std::string> q = this->queue;
	// for (;!q.empty(); q.pop_front())
	// 	std::cout << q.front() << "|";
	// std::cout << std::endl << "size: " <<  this->queue.size() << std::endl;
	if (this->queue.size() != 1)
		throw std::runtime_error("Invalid operation, please check your input.");
	else
		std::cout << std::defaultfloat << std::stod(this->queue.front()) << std::endl;
}
