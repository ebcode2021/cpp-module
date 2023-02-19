#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	protected :
		std::string	_type;

	public :
		// OCCF
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		WrongAnimal& operator=(const WrongAnimal&);
		virtual ~WrongAnimal();

		// getter
		std::string	getType() const;
		
		// method
		void	makeSound() const;
};

#endif