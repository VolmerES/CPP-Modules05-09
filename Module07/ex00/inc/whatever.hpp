/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:02:06 by volmer            #+#    #+#             */
/*   Updated: 2025/09/29 14:06:33 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename type>
type	max(type a, type b)
{
	if (a > b)	return(a);
	if (b > a)	return(b);
	else		return(b);
}

template <typename type>
type	min(type a, type b)
{
	if (a > b)	return(b);
	if (b > a)	return(a);
	else		return(b);
}

template <typename Type1>
void	swap(Type1& a, Type1& b) 
{
	Type1 swap;

	swap = a;
	a = b;
	b = swap;
}