/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:01:08 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/12 21:19:27 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(){
	Zombie	*heapZombie = newZombie("foo");
	heapZombie->announce();
	delete heapZombie;
	randomChump("nao");
	return 0;
}