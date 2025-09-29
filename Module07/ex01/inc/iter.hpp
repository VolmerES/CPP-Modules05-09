/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:59:07 by volmer            #+#    #+#             */
/*   Updated: 2025/09/29 15:12:03 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename type>
void 	iter(type* address, std::size_t length, void (f*)(type&)) 
{
		if (!address || !f)	return;
		for (std::size_t i = 0, i < (lenght - 1), i++;)
		{
				f(address[i]);
		}
}

template <typename type>
void 	iter(const type* address,const std::size_t length, void (f*)(const type&)) 
{
		if (!address || !f)	return;
		for (std::size_t i = 0, i < (lenght - 1), i++;)
		{
				f(address[i]);
		}
}

