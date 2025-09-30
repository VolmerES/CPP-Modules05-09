/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:19:37 by volmer            #+#    #+#             */
/*   Updated: 2025/09/30 15:15:52 by volmer           ###   ########.fr       */
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

template<typename T>
Array<T>::~Array() {
	delete[] _data;
}

template<typename T>
Array<T>::Array(const Array & other) : _data(NULL), _size(other.size) {
	if (_size > 0) {
		_data = new T[_size]();
		for (size_t i = 0; i < _size; i++){
			_data[i] = other._data[i];
		}
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array & other) {
	if (this != &other){
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++){
			_data[i] = other._data[i];
		}
	}
	return (*this);
}