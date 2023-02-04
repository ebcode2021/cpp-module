/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunbison <eunbison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:07:30 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/04 22:17:41 by eunbison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOIN_HPP
# define JOIN_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Join
{
	public :
		static void replace(std::ifstream &in, std::ofstream &out, std::string to_find, std::string replace);
};

#endif