/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Containers.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:45:45 by timschmi          #+#    #+#             */
/*   Updated: 2025/03/10 15:21:34 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <vector>
#include <iostream>


class Vec
{
	private:
		std::string name = "First";
		// int count = 0;
		
		std::vector<std::pair<std::vector<int>, std::vector<int>>> pair;
		std::vector<int> unpaired; //myb nested vector would be better
		std::vector<std::vector<int>> main;
		std::vector<std::pair<std::vector<int>, int>> pend;
	
	
	public:
		//De- Constructor
		Vec() = default;
		Vec(const Vec &other) = default;
		Vec& operator=(const Vec &other) = default;
		~Vec() = default;
		
		//Getters
		std::vector<int> &getUP(void);
		std::vector<std::pair<std::vector<int>, std::vector<int>>> &getP(void);
		std::vector<std::vector<int>> &getM(void);
		std::vector<std::pair<std::vector<int>, int>> &getPe(void);

		std::string getName(void) const;
};

class Dq
{
	private:
		std::string name = "Second";
		// int count = 0;
		
		std::deque<std::pair<std::deque<int>, std::deque<int>>> pair;
		std::deque<int> unpaired;
		std::deque<std::deque<int>> main;
		std::deque<std::pair<std::deque<int>, int>> pend;
	
	public:
		//De- Constructor
		Dq() = default;
		Dq(const Dq &other) = default;
		Dq& operator=(const Dq &other) = default;
		~Dq() = default;

		//Getters
		std::deque<int> &getUP(void);
		std::deque<std::pair<std::deque<int>, std::deque<int>>> &getP(void);
		std::deque<std::deque<int>> &getM(void);
		std::deque<std::pair<std::deque<int>, int>> &getPe(void);

		std::string getName(void) const;
};