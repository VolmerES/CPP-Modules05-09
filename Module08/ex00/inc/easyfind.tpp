/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:51:12 by volmer            #+#    #+#             */
/*   Updated: 2025/10/07 16:43:38 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T& container, int nb)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), nb);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}