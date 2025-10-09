/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:05:50 by volmer            #+#    #+#             */
/*   Updated: 2025/10/09 16:22:57 by volmer           ###   ########.fr       */
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
	
	typedef typename std::stack<T>::container_type::iterator it;
	typedef typename std::stack<T>::container_type::const_iterator const_it;
	
	it			begin();
	it			end();
	const_it	begin() const;
	const_it	end() const;
};

#include "../src/MutantStack.tpp"

