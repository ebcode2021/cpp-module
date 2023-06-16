#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <ctime>
# include <vector>
# include <deque>

class	PmergeMe
{
	private :
		std::deque<int>		_deque;
		std::vector<int>	_vector;

	public :
		// OCCF
		PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();
		PmergeMe(char *[]);

		// method
		void	run();
		void	sort();
		
		// print method
		void		printResult(std::deque<int>, clock_t, clock_t);
		void		printList();
};

#endif