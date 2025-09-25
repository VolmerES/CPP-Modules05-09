/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:38:19 by volmer            #+#    #+#             */
/*   Updated: 2025/09/25 17:49:00 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "data.hpp"
#include <cstdint>

class	Serializer{
	private:
		Serializer();
		Serializer(const Serializer & other);
		Serializer& operator=(const Serializer & other);
		~Serializer();
	public:
		static uintptr_t	serialize(Data *data);
		static Data*		deserialize(uintptr_t pointer);
};