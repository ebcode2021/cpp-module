/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:10:14 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/05 19:21:29 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Join.hpp"

void	Join::replace(std::string file_name, std::string to_find, std::string replace)
{
	int			idx;
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string 	pre_oneLine;
	std::string 	oneLine;

	if (to_find.length() == 0 || replace.length() == 0)
		exit(1);
	infile.open(file_name);
	if (infile.fail())
	{
		std::cerr << "ya" << std::endl;
		exit(1);
	}
	outfile.open(file_name + ".replace");
	while (std::getline(infile, oneLine))
	{
		pre_oneLine = "";
		while (1)
		{
			idx = oneLine.find(to_find);
			if (idx == -1)
				break ; 
			pre_oneLine += oneLine.substr(0, idx) + replace;
			oneLine =  oneLine.substr(idx + replace.length(), oneLine.length());
			std::cout << oneLine << std::endl;
		}
		outfile << pre_oneLine + oneLine << std::endl;
	}
	infile.close();
	outfile.close();
}
