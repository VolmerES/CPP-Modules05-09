/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:52:28 by volmer            #+#    #+#             */
/*   Updated: 2025/11/11 14:36:16 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <vector>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : _deq(other._deq), _vec(other._vec)  {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		if (!isValidNumber(argv[i]))
			throw std::runtime_error("Invalid number: Not a number");
		int num = toInt(str);
		if (num < 0)
			throw std::runtime_error("Invalid number: Negative number");
		_vec.push_back(num);
		_deq.push_back(num);
	}
}

bool	PmergeMe::isValidNumber(const std::string & str) const
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned int>(str[i])))
			return (false);
	}
	long value;

	//value = std::stol(str);
	//if (value <= 0 || value > INT_MAX)
	//	return (false);
	return (true);
}

int		PmergeMe::toInt(const std::string & str) const
{
	return (std::atoi(str.c_str()));
}

void	PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		std::cout << _vec[i];
		if (i != _vec.size() - 1)
			std::cout << ' ';
	}
	std::cout << std::endl;
}

void	PmergeMe::pairVector(const std::vector<int> & src,
							std::vector<int> & A,
							std::vector<int> & B,
							bool & hasOdd, int & oddVal)
{
	A.clear();
	B.clear();
	hasOdd = false;
	
	const size_t size = src.size();
	const size_t pairs = size / 2;

	A.reserve(pairs);
	B.reserve(pairs);

	for (size_t i = 0; i < pairs; ++i)
	{
		int first = src[i * 2];
		int second = src[i * 2 + 1];
		if (first < second)
		{
			A.push_back(first);
			B.push_back(second);
		}
		else
		{
			A.push_back(second);
			B.push_back(first);
		}
	}
		if (size % 2 != 0)
		{
			oddVal = src.back();
			hasOdd = true;
		}
}

void	PmergeMe::sortMaxVector(std::vector<int> & A)
{
	if (A.size() <= 1)
		return;
	const size_t half = A.size() / 2;

	std::vector<int> left(A.begin(), A.begin() + half);
	std::vector<int> right(A.begin() + half, A.end());
	
	sortMaxVector(left);
	sortMaxVector(right);

	A.clear();
	A.reserve(left.size() + right.size());

	size_t leftIndex = 0;
	size_t rightIndex = 0;

	while (leftIndex < left.size() && rightIndex < right.size())
	{
		if (left[leftIndex] > right[rightIndex])
		{
			A.push_back(left[leftIndex]);
			++leftIndex;
		}
		else
		{
			A.push_back(right[rightIndex]);
			++rightIndex;
		}

	}
	while (leftIndex < left.size())
	{
		A.push_back(left[leftIndex]);
		++leftIndex;
	}
	while (rightIndex < right.size())
	{
		A.push_back(right[rightIndex]);
		++rightIndex;
	}
}
void	PmergeMe::printAfter() const {}