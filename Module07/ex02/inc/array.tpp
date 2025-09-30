/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:19:37 by volmer            #+#    #+#             */
/*   Updated: 2025/09/30 15:03:51 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

template<typename T>
Array<T>::Array() : _data(NULL), _size(0) {}


template<typename T>
unsigned int	Array<T>::size() const { return this->_size; }

template<typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n) {
	if (_size > 0) {
		_data = T[_size]();
	}
}