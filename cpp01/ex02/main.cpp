/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:43:59 by eunson            #+#    #+#             */
/*   Updated: 2023/02/02 21:03:00 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_stringPTR(std::string *stringPTR)
{
	std::cout << "-- stringPTR -- " << std::endl;
	std::cout << "address of stringPTR : " << stringPTR << std::endl;
	std::cout << "value of stringPTR : " << *stringPTR << std:: endl;
}

void	print_stringREF(std::string &stringREF)
{
	std::cout << "-- stringREF -- " << std::endl;
	std::cout << "address of stringREF : " << &stringREF << std::endl;
	std::cout << "value of stringREF : " << stringREF << std:: endl;
}

int main(void)
{
	std::string init = "HI THIS IS BRAIN";
	std::string *stringPTR = &init;
	std::string &stringREF = init;
	
	std::cout << "-- string -- " << std::endl;
	std::cout << "address of string : " << &init << std::endl;
	std::cout << "value of string : " << init << std:: endl;
	
	print_stringPTR(stringPTR);
	print_stringREF(stringREF);
}