#include <iomanip>
#include <iostream>
#include <string>

#include "PhoneBook.hpp"

void	deadSignalCheck(void);

void	PhoneBook::add(int idx)
{
	this->contact[idx].add();
}

void	printHeader(void)
{
	const char*	header[4] = {"index", "first name", "last name", "nickname"};
	
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::setw(10);
		std::cout << header[i];
		if (i < 3)
			std::cout << "|";
		else
			std::cout << std::endl;
	}
}

void	PhoneBook::searchInformation(void)
{
	int			idx;
	std::string input;

	std::cout << "Please enter the index of the contact you want to see : ";
	std::getline(std::cin, input);
	for (int i = 0; i < input.length(); i++)
	{
		if (std::isdigit(input[i]) == 0)
		{
			std::cout << "Error::it's not number" << std::endl;
			return ;
		}
	}
	idx = std::atoi(input.c_str());
	if (idx >= 1 && idx <= 8)
		this->contact[idx - 1].showDetail();
	else
		std::cout << "Error::Invalid number" << std::endl;
}

void	PhoneBook::search(void)
{
	printHeader();
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10);
		std::cout << i + 1;
		std::cout << "|";
		this->contact[i].show();
		std::cout << std::endl;
	}
	deadSignalCheck();
	searchInformation();
}
