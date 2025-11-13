/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:52:21 by volmer            #+#    #+#             */
/*   Updated: 2025/11/13 14:57:17 by volmer           ###   ########.fr       */
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
		void	sortMaxVector(std::vector<int> & A, std::vector<int> & B);
		void	sortVector(std::vector<int> & A, std::vector<int> & B, bool hasOdd, int oddVal);
		size_t	findInsertPos(const std::vector<int> &v, int value) const;
		size_t	jacobsthal(size_t n) const;
		std::vector<size_t> generateInsertionOrder(size_t size) const;
		
		void	pairDeque(const std::deque<int> &src,
			std::deque<int> &A,
			std::deque<int> &B,
			bool &hasOdd, int &oddVal);
		void	sortMaxDeque(std::deque<int> &A, std::deque<int> &B);
		size_t	findInsertPos(const std::deque<int> &v, int value) const;
		void	sortDeque(std::deque<int> &A, std::deque<int> &B, bool hasOdd, int oddVal);
		std::deque<size_t> generateInsertionOrderDeque(size_t size) const;
			
	public:
		PmergeMe();
		PmergeMe(const int argc, char **argv);
		PmergeMe(const PmergeMe & other);
		PmergeMe& operator=(const PmergeMe & other);
		~PmergeMe();
			
		void	sortAllDeque();
		void	sortAll();
		void	printBefore() const;
		void	printAfter() const;
};