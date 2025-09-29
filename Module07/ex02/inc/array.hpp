/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:14:37 by volmer            #+#    #+#             */
/*   Updated: 2025/09/29 18:20:43 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array& Array(const Array & other);
		Array& operator=(const Array & other);
		
		T&	operator[unsigned int n]:
		unsigned int	size() const;
};