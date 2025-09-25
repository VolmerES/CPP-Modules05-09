/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:14:57 by volmer            #+#    #+#             */
/*   Updated: 2025/09/25 18:23:31 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base {
	private:
		Base();
		Base(const Base &other);
		Base& operator=(const Base & other);
		virtual ~Base();

	public:
		
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);