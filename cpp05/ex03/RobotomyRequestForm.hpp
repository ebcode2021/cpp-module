#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		RobotomyRequestForm& operator=(const RobotomyRequestForm&);

	public:
		// OCCF
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm&);
		~RobotomyRequestForm();

		RobotomyRequestForm(std::string);

		// virtual function
		void	execute(Bureaucrat const & executor) const;
};

#endif