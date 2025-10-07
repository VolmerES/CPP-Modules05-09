/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:04:23 by volmer            #+#    #+#             */
/*   Updated: 2025/10/07 17:56:04 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(unsigned int max) : _max(max) {}

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

void	addNumber(int nb)
{
	//will be used in order to fill it. Any attempt to add a new element if there.
	//are already N elements stored should throw an exception.
}