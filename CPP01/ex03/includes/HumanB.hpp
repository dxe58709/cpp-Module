/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:46:06 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/17 16:15:55 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon	*weapon;// ポインタとして保持する（武器がない場合もあるため）

	public:
		HumanB(const std::string &name);
		void	setWeapon(Weapon &weapon);
		void	attack() const;;
};
#endif