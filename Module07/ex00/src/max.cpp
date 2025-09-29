/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:56:58 by volmer            #+#    #+#             */
/*   Updated: 2025/09/29 13:58:28 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename type>

type	max(type a, type b)
{
	if (a > b)	return(a);
	if (b > a)	return(b);
	else		return(b);
}


//max: Compares the two values passed as parameters and returns the greatest one.
//If they are equal, it returns the second one.