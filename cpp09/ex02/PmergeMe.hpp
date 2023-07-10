#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <sstream>
# include <ctime>
# include <deque>
# include <list>

class	PmergeMe
{
	private :
		std::deque<int>		_deque;
		std::list<int>		_list;
		

	public :
		// OCCF
		PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();
		PmergeMe(char *[]);

		// method
		void	run();
		
		// validate
		bool	parseArguments(char *[]);
		
		// print method
		void		printSortChange();
		void		printTimeStamp(size_t, clock_t, clock_t);
};

#endif