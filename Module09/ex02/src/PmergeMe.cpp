/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:52:28 by volmer            #+#    #+#             */
/*   Updated: 2025/11/13 13:04:57 by volmer           ###   ########.fr       */
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

bool PmergeMe::isValidNumber(const std::string &str) const
{
    if (str.empty()) return false;

    for (size_t i = 0; i < str.size(); ++i)
        if (!std::isdigit(str[i]))
            return false;

    long n = std::atol(str.c_str());
    if (n < 0 || n > INT_MAX)
        return false;

    return true;
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

size_t PmergeMe::findInsertPos(const std::vector<int> &v, int value) const
{
    size_t left = 0;
    size_t right = v.size();

    // IMPORTANTE: sortMaxVector ahora mismo ordena en DESCENDENTE (>).
    // Así que aquí buscamos la posición manteniendo ese orden.
    while (left < right)
    {
        size_t mid = (left + right) / 2;
        if (v[mid] > value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}


void	PmergeMe::sortVector(std::vector<int> & A, std::vector<int> & B, bool hasOdd, int oddVal)
{
	sortMaxVector(B);
	
	std::vector<int> mainChain = B;

	for (size_t i = 0; i < A.size(); ++i)
    {
        size_t pos = findInsertPos(mainChain, A[i]);
        mainChain.insert(mainChain.begin() + pos, A[i]);
    }
    if (hasOdd)
    {
        size_t pos = findInsertPos(mainChain, oddVal);
        mainChain.insert(mainChain.begin() + pos, oddVal);
    }
	 _vec = mainChain;
}

void	PmergeMe::sortAll()
{
    if (_vec.size() <= 1)
        return;

    std::vector<int> A;
    std::vector<int> B;
    bool hasOdd = false;
    int oddVal = 0;

    pairVector(_vec, A, B, hasOdd, oddVal);
    sortVector(A, B, hasOdd, oddVal);
}

void	PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); ++i)
    {
        std::cout << _vec[i];
        if (i != _vec.size() - 1)
            std::cout << ' ';
    }
    std::cout << std::endl;
}
