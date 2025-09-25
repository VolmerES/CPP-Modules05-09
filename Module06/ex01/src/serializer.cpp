/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:42:27 by volmer            #+#    #+#             */
/*   Updated: 2025/09/25 17:53:51 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/serializer.hpp"

uintptr_t	Serializer::serialize(Data *data) {
	return (reinterpret_cast<uintptr_t>(data));
}

Data*		Serializer::deserialize(uintptr_t pointer) {
	return (reinterpret_cast<Data*>(pointer));
}