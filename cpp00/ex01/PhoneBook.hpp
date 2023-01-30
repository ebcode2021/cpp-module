#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	private :
		// member variable
		Contact	contact[8];

	public : 
		// member function
		void		add(int idx);
		void		search();
		void		searchInformation();

};

#endif