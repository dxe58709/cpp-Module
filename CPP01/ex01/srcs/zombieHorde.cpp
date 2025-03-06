/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:26:25 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/12 21:42:43 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	if (N <= 0){
		return NULL;
	}
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; ++i){
		horde[i].setName(name);
	}
	return horde;
}