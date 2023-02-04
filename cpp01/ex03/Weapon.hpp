/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:12:05 by eunson            #+#    #+#             */
/*   Updated: 2023/02/03 09:50:14 by eunson           ###   ########.fr       */
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
		Weapon(const Weapon&);
		Weapon &operator=(const Weapon&);
		~Weapon();
		std::string& getType(void);
		void setType(std::string type);
};

#endif