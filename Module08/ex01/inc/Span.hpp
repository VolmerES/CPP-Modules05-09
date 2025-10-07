/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:55:01 by volmer            #+#    #+#             */
/*   Updated: 2025/10/07 17:10:44 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Span {
	public:
		Span(unsigned int max);
		Span(const Span & other);
		Span& operator=(const Span & other);
		~Span();

		void	addNumber(int nb);
		void	shortestSpan();
		void	longestSpan();
};