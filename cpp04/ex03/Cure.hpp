#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria
{
	public :
		// OCCF
		Cure();
		Cure(const Cure&);
		Cure& operator=(const Cure&);
		~Cure();

		// member funciton
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif