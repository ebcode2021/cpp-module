/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:07:30 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/05 19:06:14 by eunson           ###   ########.fr       */
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
		static void replace(std::string file_name, std::string to_find, std::string replace);
};

#endif