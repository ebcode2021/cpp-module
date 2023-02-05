/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:32:14 by eunson            #+#    #+#             */
/*   Updated: 2023/02/05 19:37:53 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		
	public :
		void	complain(std::string level);
};

#endif