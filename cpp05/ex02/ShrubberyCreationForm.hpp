#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

	public:
		// OCCF
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string);

		// virtual function
		void	execute(Bureaucrat const & executor) const;
};

#endif