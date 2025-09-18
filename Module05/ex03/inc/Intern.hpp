/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:54:20 by volmer            #+#    #+#             */
/*   Updated: 2025/09/18 12:10:00 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AForm;

class Intern {
	private:
		typedef AForm* (*formFunction)(const std::string & target);

		static AForm*	createShrubbery(const std::string & target);
		static AForm*	createRobotomy(const std::string & target);
		static AForm*	createPresidential(const std::string & target);

	public:
		Intern();
		Intern(const Intern & other);
		Intern& operator=(const Intern & other);
		~Intern();

		AForm*	makeForm(const std::string & formName, const std::string & target) const;
};