/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:01:08 by nsakanou          #+#    #+#             */
/*   Updated: 2024/11/23 18:46:50 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
	Replace	fr;

	fr.handleArgs(argc, argv);
	fr.setArgs(argv[1], argv[2], argv[3]);
	fr.fileReplace();
	return 0;
}
