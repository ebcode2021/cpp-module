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
		std::list<int>		_origin;
		

	public :
		// OCCF
		PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();
		PmergeMe(char *[]);

		// method
		void	run();
		void	parseArguments(char *[]);
		
		// print method
		void	printSortChange();
		void	printTimeStamp(clock_t, clock_t);
};

#endif