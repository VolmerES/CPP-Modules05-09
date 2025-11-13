/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:52:28 by volmer            #+#    #+#             */
/*   Updated: 2025/11/13 14:57:17 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <vector>
#include <climits>

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

void	PmergeMe::sortMaxVector(std::vector<int> & A, std::vector<int> & B)
{
	if (A.size() <= 1)
		return;
	const size_t half = A.size() / 2;

	std::vector<int> leftA(A.begin(), A.begin() + half);
	std::vector<int> rightA(A.begin() + half, A.end());
	std::vector<int> leftB(B.begin(), B.begin() + half);
	std::vector<int> rightB(B.begin() + half, B.end());
	
	sortMaxVector(leftA, leftB);
	sortMaxVector(rightA, rightB);

	A.clear();
	B.clear();
	A.reserve(leftA.size() + rightA.size());
	B.reserve(leftB.size() + rightB.size());

	size_t leftIndex = 0;
	size_t rightIndex = 0;

	while (leftIndex < leftA.size() && rightIndex < rightA.size())
	{
		if (leftB[leftIndex] < rightB[rightIndex])
		{
			A.push_back(leftA[leftIndex]);
			B.push_back(leftB[leftIndex]);
			++leftIndex;
		}
		else
		{
			A.push_back(rightA[rightIndex]);
			B.push_back(rightB[rightIndex]);
			++rightIndex;
		}
	}
	while (leftIndex < leftA.size())
	{
		A.push_back(leftA[leftIndex]);
		B.push_back(leftB[leftIndex]);
		++leftIndex;
	}
	while (rightIndex < rightA.size())
	{
		A.push_back(rightA[rightIndex]);
		B.push_back(rightB[rightIndex]);
		++rightIndex;
	}
}

size_t PmergeMe::findInsertPos(const std::vector<int> &v, int value) const
{
    size_t left = 0;
    size_t right = v.size();

    while (left < right)
    {
        size_t mid = (left + right) / 2;
        if (v[mid] < value)  // Cambio: < en lugar de >
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

size_t PmergeMe::jacobsthal(size_t n) const
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	size_t prev2 = 0;  // J(0)
	size_t prev1 = 1;  // J(1)
	size_t current = 1;
	
	for (size_t i = 2; i <= n; ++i)
	{
		current = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = current;
	}
	return current;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(size_t size) const
{
	std::vector<size_t> order;
	if (size <= 1)
		return order;
	
	order.reserve(size - 1);
	
	size_t jacobIdx = 3;
	size_t lastPos = 1;
	
	while (lastPos < size)
	{
		size_t jacobNum = jacobsthal(jacobIdx);
		
		// Si el número de Jacobsthal excede el tamaño, usar el tamaño - 1
		if (jacobNum >= size)
			jacobNum = size - 1;
		
		// Insertar desde jacobNum hacia abajo hasta lastPos
		size_t i = jacobNum;
		while (i >= lastPos && i < size)
		{
			order.push_back(i);
			if (i == 0)
				break;
			--i;
		}
		
		lastPos = jacobNum + 1;
		++jacobIdx;
		
		if (jacobNum >= size - 1)
			break;
	}
	
	return order;
}

void	PmergeMe::sortVector(std::vector<int> & A, std::vector<int> & B, bool hasOdd, int oddVal)
{
	sortMaxVector(A, B);
	
	std::vector<int> mainChain = B;

	// Insertar el primer elemento de A al principio
	if (!A.empty())
	{
		mainChain.insert(mainChain.begin(), A[0]);
		
		// Generar el orden de inserción usando Jacobsthal
		std::vector<size_t> insertOrder = generateInsertionOrder(A.size());
		
		// Insertar el resto de elementos de A usando el orden de Jacobsthal
		for (size_t i = 0; i < insertOrder.size(); ++i)
		{
			size_t idx = insertOrder[i];
			if (idx < A.size())
			{
				size_t pos = findInsertPos(mainChain, A[idx]);
				mainChain.insert(mainChain.begin() + pos, A[idx]);
			}
		}
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

void	PmergeMe::pairDeque(const std::deque<int> &src,
							std::deque<int> &A,
							std::deque<int> &B,
							bool &hasOdd, int &oddVal)
{
	A.clear();
	B.clear();
	hasOdd = false;
	
	const size_t size = src.size();
	const size_t pairs = size / 2;

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

void	PmergeMe::sortMaxDeque(std::deque<int> &A, std::deque<int> &B)
{
	if (A.size() <= 1)
		return;
	const size_t half = A.size() / 2;

	std::deque<int> leftA(A.begin(), A.begin() + half);
	std::deque<int> rightA(A.begin() + half, A.end());
	std::deque<int> leftB(B.begin(), B.begin() + half);
	std::deque<int> rightB(B.begin() + half, B.end());
	
	sortMaxDeque(leftA, leftB);
	sortMaxDeque(rightA, rightB);

	A.clear();
	B.clear();

	size_t leftIndex = 0;
	size_t rightIndex = 0;

	while (leftIndex < leftA.size() && rightIndex < rightA.size())
	{
		if (leftB[leftIndex] < rightB[rightIndex])
		{
			A.push_back(leftA[leftIndex]);
			B.push_back(leftB[leftIndex]);
			++leftIndex;
		}
		else
		{
			A.push_back(rightA[rightIndex]);
			B.push_back(rightB[rightIndex]);
			++rightIndex;
		}
	}
	while (leftIndex < leftA.size())
	{
		A.push_back(leftA[leftIndex]);
		B.push_back(leftB[leftIndex]);
		++leftIndex;
	}
	while (rightIndex < rightA.size())
	{
		A.push_back(rightA[rightIndex]);
		B.push_back(rightB[rightIndex]);
		++rightIndex;
	}
}

size_t PmergeMe::findInsertPos(const std::deque<int> &v, int value) const
{
    size_t left = 0;
    size_t right = v.size();

    while (left < right)
    {
        size_t mid = (left + right) / 2;
        if (v[mid] < value)  // Cambio: < en lugar de >
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

std::deque<size_t> PmergeMe::generateInsertionOrderDeque(size_t size) const
{
	std::deque<size_t> order;
	if (size <= 1)
		return order;
	
	size_t jacobIdx = 3;
	size_t lastPos = 1;
	
	while (lastPos < size)
	{
		size_t jacobNum = jacobsthal(jacobIdx);
		
		if (jacobNum >= size)
			jacobNum = size - 1;
		
		size_t i = jacobNum;
		while (i >= lastPos && i < size)
		{
			order.push_back(i);
			if (i == 0)
				break;
			--i;
		}
		
		lastPos = jacobNum + 1;
		++jacobIdx;
		
		if (jacobNum >= size - 1)
			break;
	}
	
	return order;
}

void	PmergeMe::sortDeque(std::deque<int> &A, std::deque<int> &B, bool hasOdd, int oddVal)
{
	sortMaxDeque(A, B);
	
	std::deque<int> mainChain = B;

	// Insertar el primer elemento de A al principio
	if (!A.empty())
	{
		mainChain.insert(mainChain.begin(), A[0]);
		
		// Generar el orden de inserción usando Jacobsthal
		std::deque<size_t> insertOrder = generateInsertionOrderDeque(A.size());
		
		// Insertar el resto de elementos de A usando el orden de Jacobsthal
		for (size_t i = 0; i < insertOrder.size(); ++i)
		{
			size_t idx = insertOrder[i];
			if (idx < A.size())
			{
				size_t pos = findInsertPos(mainChain, A[idx]);
				mainChain.insert(mainChain.begin() + pos, A[idx]);
			}
		}
	}
	
	if (hasOdd)
	{
		size_t pos = findInsertPos(mainChain, oddVal);
		mainChain.insert(mainChain.begin() + pos, oddVal);
	}
	_deq = mainChain;
}

void	PmergeMe::sortAllDeque()
{
    if (_deq.size() <= 1)
        return;

    std::deque<int> A;
    std::deque<int> B;
    bool hasOdd = false;
    int oddVal = 0;

    pairDeque(_deq, A, B, hasOdd, oddVal);
    sortDeque(A, B, hasOdd, oddVal);
}
