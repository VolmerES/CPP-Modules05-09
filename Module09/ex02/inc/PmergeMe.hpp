/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:52:21 by volmer            #+#    #+#             */
/*   Updated: 2025/11/11 13:12:32 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class PmergeMe {
	private:
		std::deque<int> _deq;
		std::vector<int> _vec;
		
		bool	isValidNumber(const std::string & str);
		int		toInt(const std::string & str);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe & other);
		PmergeMe& operator=(const PmergeMe & other);
		~PmergeMe();

		void	printBefore();
		void	printAfter();
};