#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
	public :
		// OCCF
		Cat();
		Cat(const Cat&);
		Cat& operator=(const Cat&);
		~Cat();

		// override
		void	makeSound() const;
};

#endif