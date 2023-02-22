#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class ICharacter;

class	AMateria
{
	protected :
		std::string	_type;

	public :
		// OCCF
		AMateria();
		AMateria(const AMateria&);
		AMateria& operator=(const AMateria&);
		virtual ~AMateria();

		// additional constructor
		AMateria(std::string const &type);

		std::string const& getType() const; //Returns the materia type

		// member function
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif