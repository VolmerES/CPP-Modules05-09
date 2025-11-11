/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:52:21 by volmer            #+#    #+#             */
/*   Updated: 2025/11/11 14:23:40 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {
	private:
		std::deque<int>		_deq;
		std::vector<int>	_vec;
		
		bool	isValidNumber(const std::string & str) const;
		int		toInt(const std::string & str) const;

		void 	pairVector(const std::vector<int> & src,
							std::vector<int> & A,
							std::vector<int> & B,
							bool & hasOdd, int & oddVal);
		void	sortMaxVector(std::vector<int> & A);
		void	sortMinVector(std::vector<int> & B);

	public:
		PmergeMe();
		PmergeMe(const int argc, char **argv);
		PmergeMe(const PmergeMe & other);
		PmergeMe& operator=(const PmergeMe & other);
		~PmergeMe();

		void	printBefore() const;
		void	printAfter() const;
};