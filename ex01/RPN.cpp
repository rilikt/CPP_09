/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:25 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/29 11:51:56 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


//Input parsing
void RPN::parseInput(std::string str)
{
	std::regex pattern(R"((\d|\*|\+|-|/)|(\S+))");
	
	auto begin = std::sregex_iterator(str.begin(), str.end(), pattern);
	auto end = std::sregex_iterator();

	for (auto it = begin; it != end; it++)
	{
		if (it->str(2).length())
			throw std::runtime_error("Invalid input: '" + it->str(2) + "' only values up to 9 and : '+ - / *' operators allowed.");
		this->queue.push(it->str(1));
	}
}


double RPN::matchOperand(double *arr, std::string op)
{
	if (op == "+")
		return(arr[0] + arr[1]);
	else if (op == "-")
		return(arr[0] - arr[1]);
	else if (op == "*")
		return(arr[0] * arr[1]);
	else if (op == "/")
		return(arr[0] / arr[1]);
	else
		throw std::runtime_error("Input invalid");
}


void RPN::doMath(void)
{
	double arr[2];
	int i = 0;

	for (;!this->queue.empty(); this->queue.pop())
	{	
		for (; !this->queue.empty() && i < 2; this->queue.pop(), i++)
			arr[i] = std::stod(this->queue.front());
		std::cout << std::fixed << "val1: " << arr[0] << " | val2: " << arr[1];
		arr[0] = matchOperand(arr, this->queue.front());
		std::cout << " " << this->queue.front() << "= " << arr[0] << std::endl;
		i = 1;
	}
}



//Printing
void RPN::printQueue(void) const
{
	std::queue<std::string> q = this->queue;
	for (;!q.empty(); q.pop())
		std::cout << q.front();
	std::cout << std::endl << "size: " <<  this->queue.size() << std::endl;
}


