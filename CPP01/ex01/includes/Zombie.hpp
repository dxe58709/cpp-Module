/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 02:04:16 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/12 21:43:12 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
	private:
		std::string name;

	public:
		Zombie();
		~Zombie();
		void	announce();
		void	setName(const std::string &name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif