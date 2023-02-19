#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal
{
	public :
		// OCCF
		Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);
		~Dog();

		// override
		void	makeSound() const;
};

#endif