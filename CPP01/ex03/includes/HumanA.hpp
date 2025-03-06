/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:46:03 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/17 16:09:55 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon	&weapon;// 参照として保持する（必ず武器があるため）

	public:
		HumanA(const std::string &name, Weapon &weapon);
		void	attack() const;
};
#endif