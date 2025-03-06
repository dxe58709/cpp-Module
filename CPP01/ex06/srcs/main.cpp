/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:01:08 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/18 17:19:35 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;
	if (argc != 2){
		std::cout << "Error: Invalid arguments." << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return 0;
}
