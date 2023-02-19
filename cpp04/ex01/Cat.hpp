#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private :
		Brain* _brain;

	public :
		// OCCF
		Cat();
		Cat(const Cat&);
		Cat& operator=(const Cat&);
		~Cat();

		// override
		void	makeSound() const;

		// getter setter
		std::string	getBrain() const;
		void		setBrain(const std::string);
};

#endif