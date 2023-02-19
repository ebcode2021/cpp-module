#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private :
		Brain* _brain;

	public :
		// OCCF
		Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);
		~Dog();

		// override
		void	makeSound() const;

		// getter setter
		std::string	getBrain() const;
		void		setBrain(const std::string);
};

#endif