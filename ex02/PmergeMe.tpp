/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:12:54 by timschmi          #+#    #+#             */
/*   Updated: 2025/04/27 16:56:15 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int jnum[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

template <typename C>
struct ContainerCheck : std::disjunction<
std::is_same<std::decay_t<C> , std::deque<typename std::decay_t<C>::value_type>>,
std::is_same<std::decay_t<C> , std::vector<typename std::decay_t<C>::value_type>> 
>
{};

template <typename Main>
void printMain(Main &main)
{
	for (auto it : main)
	{
		for (auto it2 : it)
			std::cout << it2 << " ";
	}
	std::cout << std::endl;
}

template <typename ContainerPair, typename ContainerUnPaired>
void storeArgs(ContainerPair &pair, ContainerUnPaired &unpaired, int argc, char **argv)
{
	int i = 1;
	int a;
	int b;
	for (int j = 0; i+1 < argc; i+=2, j++)
	{
		if ((a = std::stoi(argv[i])) < 0 || (b = std::stoi(argv[i+1])) < 0)
			throw std::runtime_error("Only positve values accepted.");
		
		pair.push_back(std::make_pair(ContainerUnPaired(), ContainerUnPaired()));
		
		pair[j].first.push_back(a);
		pair[j].second.push_back(b);
		if (pair[j].first.back() > pair[j].second.back())
			std::swap(pair[j].first, pair[j].second);
	}
	if (i != argc)
	{
		if ((a = std::stoi(argv[i])) < 0)
			throw std::runtime_error("Only positve values accepted.");
		unpaired.push_back(a);
	}
}

template <typename ContainerPair, typename ContainerUnPaired>
void recursivePairs(ContainerPair &pair, ContainerUnPaired &unpaired)
{
	int i = 0;
	auto it = pair.begin();
	ContainerPair p;
	ContainerUnPaired up;
	
	if (pair.size() == 1)
		return;
	
	for (; it != pair.end() && std::next(it) != pair.end(); i++, it+=2)
	{
		p.push_back(std::make_pair(ContainerUnPaired(), ContainerUnPaired()));
		
		for (auto it2 : it->first)
			p[i].first.push_back(it2);
		for (auto it2 : it->second)
			p[i].first.push_back(it2);
		
		for (auto it2 : std::next(it)->first)
			p[i].second.push_back(it2);
		for (auto it2 : std::next(it)->second)
			p[i].second.push_back(it2);
		
		if (p[i].first.back() > p[i].second.back())
			std::swap(p[i].first, p[i].second);
	}
	for (;it != pair.end(); it++)
	{
		for (auto it2 : it->first)
			up.push_back(it2);
		for (auto it2 : it->second)
			up.push_back(it2);
		for (auto it2 : unpaired)
			up.push_back(it2);
		unpaired.clear();
		unpaired = up;
	}
	pair.clear();
	pair = p;
	recursivePairs(pair, unpaired);
}

template <typename Main, typename Pend>
auto findPartner(int e, Main &main, Pend &pend)
{
	int size = main.size();
	if (pend[e].second <= size)
		return (main.begin() + pend[e].second);
	return(main.end());
}

template <typename Pend>
void updateIndex(Pend &pend, int index)
{
	auto it = pend.begin();

	while (it != pend.end())
	{
		if (it->second >= index)
			break;
		it++;
	}
	while (it != pend.end())
	{
		it++->second++;
	}
}

template <typename Main, typename Pend>
void binSearch(int e, Main &main, Pend &pend)
{
	auto it = findPartner(e, main, pend);
	auto first = main.begin();
	int range = std::distance(first, it);
	auto it2 = first;
	int step;
	
	if (range == 0)
		throw std::runtime_error("Error in binSearch, invalid range");
	
	while (range > 0)
	{
		it2 = first;
		step = range / 2;
		std::advance(it2, step);
		if (pend[e].first.back() > it2->back())
		{
			first = ++it2;
			range -= step + 1;
		}
		else
			range = step;
	}
	auto insit = main.insert(it2, pend[e].first);
	updateIndex(pend, std::distance(main.begin(), insit));
}

template <typename Main, typename Pend, typename Unpaired>
void jInsert(Main &main, Pend &pend, Unpaired &unpaired)
{
	int i  = 1;
	int size = pend.size();
	
	while (size >= jnum[i] - jnum[i-1])
	{
		for (int e = jnum[i] - 2; e >= jnum[i-1]-1; e--, size--)
			binSearch(e, main, pend);
		i++;
	}
	while (unpaired.size() >= main[0].size())
	{
		Unpaired tmp(unpaired.begin(), std::next(unpaired.begin(), main[0].size()));
		unpaired.erase(unpaired.begin(),  std::next(unpaired.begin(), main[0].size()));
		pend.push_back(std::make_pair(tmp, main.size()));
		size++;
	}
	while (size)
	{
		for (int b = pend.size() - 1; b != jnum[i-1] -2; b--, size--)
			binSearch(b, main, pend);
	}
}

template <typename Pair, typename Unpaired, typename Main, typename Pend>
void insert(Pair &pair, Unpaired &unpaired, Main &main, Pend &pend)
{
	static long unsigned int size = pair.at(0).first.size();
	Main mc;
	
	if (!size)
	{
		if (unpaired.size())
			jInsert(main, pend, unpaired);
		return;
	}
	
	if (size == pair.at(0).first.size())
	{
		for (auto it: pair)
		{
			main.push_back(it.first);
			main.push_back(it.second);
		}
		size /= 2;
		insert(pair, unpaired, main, pend);
		return;
	}
	
	int i = 2;
	for(auto it = main.begin(); it != main.end(); it++)
	{
		Unpaired tmp(it->begin(), std::next(it->begin(), size));
		Unpaired tmp2(std::next(it->begin(), size), it->end());
		
		if (it == main.begin() || !(std::distance(main.begin(), it)+1 % 2))
			mc.push_back(tmp);
		else
			pend.push_back(std::make_pair(tmp, i++));
		mc.push_back(tmp2);
	}
	main = mc;
	jInsert(main, pend, unpaired);
	pend.clear();
	size /= 2;
	insert(pair, unpaired, main, pend);
}

template<typename Main>
void checkicheck(Main &main, unsigned long argc)
{
	std::vector<int> vec;

	for (auto e : main)
	{
		for (auto n : e)
			vec.push_back(n);
	}
	if (std::is_sorted(vec.begin(), vec.end()) && vec.size() == argc -1)
		return;
	else
		exit (1);
}

template<typename Class, typename TestContainer, typename>
void FordJohnson(Class c, TestContainer &unpaired, int argc, char **argv)
{
	auto &pair = c.getP();
	auto &main = c.getM();
	auto &pend = c.getPe();
	std::string msg;

	auto start_time = std::chrono::high_resolution_clock::now();
	storeArgs(pair, unpaired, argc, argv);
	recursivePairs(pair, unpaired);
	insert(pair, unpaired, main, pend);
	auto end_time = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration<double>(end_time - start_time);
	if (c.getName() == "First")
	{
		msg = "std::vector";
		std::cout << "Before: ";
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl << "After:  ";
		printMain(main);
	}
	else
		msg = "std:deque";
	std::cout << "Time with " + msg + ": " <<  std::fixed << elapsed.count() << std::endl;
	checkicheck(main, argc);
}
