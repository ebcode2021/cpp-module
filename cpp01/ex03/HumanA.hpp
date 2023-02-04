/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:12:58 by eunson            #+#    #+#             */
/*   Updated: 2023/02/02 22:03:41 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private :
		Weapon &_weapon;
		std::string _name;

	public :
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();
};

#endif