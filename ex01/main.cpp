/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:54 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/28 11:43:31 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
NOTES:
arguments have to be passed as a single string because of how the terminal interprets certain operators eg *


*/

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
		//parse argument
		rpn.parseInput(argv[1]);
		//check for syntax error
		//push elements onto stack
		//pop elements and do operation
		//print result
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}