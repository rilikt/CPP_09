/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:15 by timschmi          #+#    #+#             */
/*   Updated: 2025/03/10 14:48:55 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <utility>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <type_traits>

#include <deque>
#include <vector>

#include "PmergeMe.tpp"

template <typename Class, typename TestContainer, typename = std::enable_if_t<ContainerCheck<TestContainer>::value>>
void FordJohnson(Class c, TestContainer &unpaired, int argc, char **argv);

template <typename ContainerPair, typename ContainerUnPaired>
void storeArgs(ContainerPair &pair, ContainerUnPaired &unpaired, int argc, char **argv);

template <typename ContainerPair, typename ContainerUnPaired>
void recursivePairs(ContainerPair &pair, ContainerUnPaired &unpaired);

template <typename Main, typename Pend>
auto findPartner(int e, Main &main, Pend &pend);

template <typename Main, typename Pend>
void binSearch(int e, Main &main, Pend &pend);

template <typename Main, typename Pend, typename Unpaired>
void jInsert(Main &main, Pend &pend, Unpaired &unpaired);

template <typename Pair, typename Unpaired, typename Main, typename Pend>
void insert(Pair &pair, Unpaired &unpaired, Main &main, Pend &pend);

template <typename Main>
void printMain(Main &main);
