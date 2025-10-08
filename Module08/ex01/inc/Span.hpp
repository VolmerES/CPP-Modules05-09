/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:55:01 by volmer            #+#    #+#             */
/*   Updated: 2025/10/08 13:16:26 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Span {
	private:
		unsigned int _max;
    	std::vector<int> _data;
	public:
		Span(unsigned int max);
		Span(const Span & other);
		Span& operator=(const Span & other);
		~Span();

		template<typename T>
		void	addRange(T first, T last)
		{
			unsigned int	distance;
			
			distance = std::distance(first, last);
			if (distance < 0)
           		throw std::runtime_error("Invalid range");
			if (_data.size() + distance > _max)
				throw (std::runtime_error("Not enough space in Span"));
			_data.insert(_data.end(), first, last);
			
		}
		
		void			addNumber(int nb);
		unsigned long	shortestSpan() const;
		unsigned long	longestSpan() const;
};