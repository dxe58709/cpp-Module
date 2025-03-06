/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:01:08 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/12 21:42:08 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(){
	int n = 10;
	if (n < 1) {
		std::cout << "Error: Invalid values." << std::endl;
	}
	Zombie *zombies = zombieHorde(n, "Nao");
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);	
}
