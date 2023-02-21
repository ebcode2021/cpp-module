#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);

	public:
		// OCCF
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm&);
		~PresidentialPardonForm();

		PresidentialPardonForm(std::string);

		// virtual function
		void	execute(Bureaucrat const & executor) const;
};

#endif