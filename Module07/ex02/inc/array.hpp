/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:14:37 by volmer            #+#    #+#             */
/*   Updated: 2025/09/30 15:45:36 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array {
	private:
		T*				_data;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array & other);
		Array& operator=(const Array & other);
		~Array();
		
		T&	operator[](unsigned int n);
		const T& operator[](unsigned int n) const;
		unsigned int	size() const;
};

#include "array.tpp"

#endif