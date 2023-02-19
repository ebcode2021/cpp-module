#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected :
		std::string	_type;

	public :
		// OCCF
		Animal();
		Animal(const Animal&);
		Animal& operator=(const Animal&);
		virtual ~Animal();

		// getter
		std::string	getType() const;
		
		// method
		virtual void	makeSound() const = 0;
};

#endif