#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

class	RPN
{
	private :
		std::stack<int>	_stack;

	public :
		// OCCF
		RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();

		// constructor
		RPN(char *);
		void	run(const std::string&);

		// method
		void	printErrorWithExit();

};

#endif