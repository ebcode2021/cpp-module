/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunbison <eunbison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:19:50 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/04 22:38:50 by eunbison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Join.hpp"

static void	print_error_with_exit(std::string msg)
{
	std::cout << "Error :: " << msg << std::endl;
	exit (EXIT_FAILURE);
}

static void openFile(std::string fileName, std::ifstream &infile, std::ofstream &outfile)
{
	infile.open(fileName);
	if (infile.fail())
		print_error_with_exit("Check infile existence or Permission");
	outfile.open(fileName + ".replace");
}

static void closeFile(std::ifstream &infile, std::ofstream &outfile)
{
	infile.close();
	outfile.close();
}

int main(int argc, char *argv[])
{
	std::ifstream	infile;
	std::ofstream	outfile;
	
	if (argc != 4)
		print_error_with_exit("Check arguements count");
	openFile(std::string(argv[1]), infile, outfile);
	Join::replace(infile, outfile, std::string(argv[2]), std::string(argv[3]));
	closeFile(infile, outfile);
}
