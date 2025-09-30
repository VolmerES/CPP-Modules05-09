/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:19:37 by volmer            #+#    #+#             */
/*   Updated: 2025/09/30 17:49:09 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include "array.hpp"

template<typename T>
Array<T>::Array() : _data(nullptr), _size(0) {}


template<typename T>
unsigned int	Array<T>::size() const { return this->_size; }

template<typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {
	if (_size > 0) {
		_data = new T[_size]();
	}
}

template<typename T>
Array<T>::~Array() {
	delete[] _data;
}

template<typename T>
Array<T>::Array(const Array<T>& other) : _data(nullptr), _size(other._size) {
	if (_size > 0) {
		_data = new T[_size]();
		for (unsigned int i = 0; i < _size; i++){
			_data[i] = other._data[i];
		}
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        if (_size > 0) {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        } else {
            _data = NULL;
        }
    }
    return *this;
}

template<typename T>
T&	Array<T>::operator[](unsigned int n) {
	if (_size <= n) {
		throw std::out_of_range("Out of bounds");
	}
	return (_data[n]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int n) const {
	if (_size <= n) {
		throw std::out_of_range("Out of bounds");
	}
	return (_data[n]);
}
