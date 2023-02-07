#ifndef CONTACT_H
#define CONTACT_H

#include <iomanip>
#include <iostream>
#include <string>

class Contact
{
	private :
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public :
		void	add();
		void	show();
		void	showDetail();
};

#endif