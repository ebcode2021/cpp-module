#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private :
		AMateria* _inventory[4];

	public :
		// OCCF
		MateriaSource();
		MateriaSource(const MateriaSource&);
		MateriaSource& operator=(const MateriaSource&);
		~MateriaSource();

		// member function
		void		learnMateria(AMateria *);
		AMateria*	createMateria(std::string const & type);
};

#endif