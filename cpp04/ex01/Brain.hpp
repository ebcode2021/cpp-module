#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class	Brain
{
	private :
		std::string _ideas[100];

	public :
		// OCCF
		Brain();
		Brain(const Brain&);
		Brain& operator=(const Brain&);
		~Brain();

		// add constructor
		Brain(std::string);
		
		// getter setter
		std::string	getIdeas() const;
		void		setIdeas(const std::string);
};
#endif