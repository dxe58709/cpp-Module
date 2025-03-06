/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:34:14 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/17 16:14:01 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &initialType) : type(initialType)
{
}

const std::string &Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string &newType)
{
	type = newType;
}