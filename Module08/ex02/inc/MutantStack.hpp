/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:05:50 by volmer            #+#    #+#             */
/*   Updated: 2025/10/09 16:33:55 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
	MutantStack();
	MutantStack(const MutantStack & other);
	MutantStack& 	operator=(const MutantStack & other);
	~MutantStack();
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	
	iterator			begin();
	iterator			end();
	const_iterator		begin() const;
	const_iterator		end() const;
};

#include "MutantStack.tpp"