/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:12:05 by eunson            #+#    #+#             */
/*   Updated: 2023/02/11 15:15:26 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private :
		std::string _type;

	public :
		Weapon();
		Weapon(std::string type);
		~Weapon();
		std::string& getType(void);
		void setType(std::string type);
};

#endif