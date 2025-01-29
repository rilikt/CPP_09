/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:25 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/29 16:26:41 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


//Input parsing
void RPN::parseInput(std::string str)
{
	std::regex pattern(R"((\d+|\*|\+|-|/)|(\S+))");
	
	auto begin = std::sregex_iterator(str.begin(), str.end(), pattern);
	auto end = std::sregex_iterator();

	for (auto it = begin; it != end; it++)
	{
		if (it->str(2).length() || it->str(1).length() > 1)
			throw std::runtime_error("Invalid input: '" + it->str(2) + "' only values up to 9 and : '+ - / *' operators allowed.");
		this->queue.push_back(it->str(1));
	}
}


double RPN::matchOperand(std::string *str, std::string op)
{
	double arr[2] = {std::stod(str[0]), std::stod(str[1])};
	std::cout << "MATH: " << arr[0] << " "+op+" " << arr[1] << std::endl;
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

int opCheck(std::string op)
{
	if (op == "+" || op == "-" || op == "*" || op == "/")
		return (1);
	else
		return (0);
}

void RPN::doMath(void)
{
	std::string arr[3];
	double tmp;
	int i = 0;

	while (!this->queue.empty())
	{	
		std::cout << "------------------------" << std::endl;
		printQueue();
		std::cout << "------------------------" << std::endl;
		for (; !this->queue.empty() && !opCheck(this->queue.front()); this->queue.pop_front(), i++)
		{
			std::cout << this->queue.front() << std::endl;

			arr[i] = this->queue.front();
		}
		if (i > 2)
		{
			tmp = matchOperand(arr+1, this->queue.front());
			this->queue.pop_front();
			this->queue.push_front(std::to_string(tmp));
			this->queue.push_front(arr[0]);
			i = 0;
		}
		else
		{
			tmp = matchOperand(arr, this->queue.front());
			this->queue.pop_front();
			this->queue.push_front(std::to_string(tmp));
			i = 0;
		}

		// if (tmp)
		// {
		// 	arr[1] = matchOperand(arr+1, this->queue.front());
		// 	this->queue.pop_front();
		// 	// str = this->queue.front();
		// 	// this->queue.pop_front();
		// 	this->queue.push_front(std::to_string(arr[1]));
		// 	this->queue.push_front(std::to_string(arr[0]));
		// 	// this->queue.push_front(str);
		// 	std::cout << " = " << arr[1] << std::endl;
		// 	arr[0] = 0;
		// 	arr[1] = 0;
		// 	arr[2] = 0;
		// 	i = 0;
		// 	tmp = false;
		// }
		// else
		// {
		// 	arr[0] = matchOperand(arr, this->queue.front());
		// 	this->queue.pop_front();
		// 	this->queue.push_front(std::to_string(arr[0]));
		// 	std::cout << " = " << arr[0] << std::endl;
		// 	arr[0] = 0;
		// 	arr[1] = 0;
		// 	arr[2] = 0;
		// 	i = 0;
		// }
	}
}



//Printing
void RPN::printQueue(void) const
{
	std::deque<std::string> q = this->queue;
	for (;!q.empty(); q.pop_front())
		std::cout << q.front();
	std::cout << std::endl << "size: " <<  this->queue.size() << std::endl;
}


double RPN::getTemp(void)
{
	if (temp_set)
	{
		this->temp_set = false;
		return (this->tmp);
	}
	return 0;
}

void RPN::setTemp(double d)
{
	{
		if(temp_set)
			throw std::runtime_error("temp already set");
		this->tmp = d;
	}
}