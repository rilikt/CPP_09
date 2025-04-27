/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:54 by timschmi          #+#    #+#             */
/*   Updated: 2025/04/27 13:25:10 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;
	if (argc != 2)
	{
		std::cerr << "Please provide a string of arguments as an input." << std::endl;
		return 1;
	}
	try
	{
		rpn.parseInput(argv[1]);
		rpn.printStack();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}