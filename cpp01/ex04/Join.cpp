/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunbison <eunbison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:10:14 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/04 22:37:12 by eunbison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Join.hpp"

void	Join::replace(std::ifstream &infile, std::ofstream &outfile, std::string to_find, std::string replace)
{
	std::string oneLine;

	while (std::getline(infile, oneLine))
	{
		while (1)
		{
			int	idx = oneLine.find(to_find);
			if (idx == -1)
				break ;
			oneLine = oneLine.substr(0, idx) + replace + oneLine.substr(idx + replace.length(), oneLine.length());
		}
		outfile << oneLine << std::endl;
	}
}