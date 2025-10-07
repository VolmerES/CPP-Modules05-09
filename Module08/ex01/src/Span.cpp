/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:04:23 by volmer            #+#    #+#             */
/*   Updated: 2025/10/07 18:43:22 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <stdexcept>
#include <vector>

Span::Span(unsigned int max) : _max(max) {
	_data.reserve(max);
}

Span::Span(const Span & other) : _max(other._max), _data(other._data) {}

Span& Span::operator=(const Span & other) 
{
    if (this != &other)
	{
        _max = other._max;
        _data = other._data;
    }
    return (*this);
}

Span::~Span() {}

void	Span::addNumber(int nb)
{
	if (_data.size() <= _max)
		throw std::runtime_error("Cannot add more numbers, Span in full");
	_data.push_back(nb);
}
template<typename T>
void			Span::addRange(T first, T last)
{
	
}

unsigned long	Span::shortestSpan() const
{
	if (_data.size() <= 2)
		throw std::runtime_error("Not enough numbers");
	std::vector<int> sortedata = _data;
	std::sort(sortedata.begin(), sortedata.end());

	unsigned int	best;
	best = std::numeric_limits<unsigned int>::max();
	
	for (std::size_t i = 0; i + 1 < sortedata.size(); ++i) 
	{
		long diff = static_cast<long>(sortedata[i + 1]) - static_cast<long>(sortedata[i]);
		unsigned int di = static_cast<unsigned int>(std::abs(diff));
		if (di < best)
			best = di;
	}
}

unsigned long	Span::longestSpan() const
{
	
}