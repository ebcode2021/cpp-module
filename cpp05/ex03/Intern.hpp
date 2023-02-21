# ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class	Intern
{
	private :

	public:
		// OCCF
		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();

		// member func
		AForm	*makeForm(std::string name, std::string target);
		AForm	*createShrubbery(std::string target);
		AForm	*createRoboto(std::string target);
		AForm	*createPresident(std::string target);

		// exception
		class	FormNotFoundException : public std::exception
		{
			const char* what() const throw();
		};
};
#endif