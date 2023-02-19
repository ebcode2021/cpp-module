#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class	AMateria
{
	protected :

	public :
		// OCCF
		AMateria();
		AMateria(const AMateria&);
		AMateria& operator=(const AMateria&);
		~AMateria();

		// additional constructor
		AMateria(std::string const &type);

		std::string const& getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif