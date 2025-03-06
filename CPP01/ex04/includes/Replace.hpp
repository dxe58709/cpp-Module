/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:44:58 by nsakanou          #+#    #+#             */
/*   Updated: 2024/11/23 18:44:59 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Replace {
	private:
		std::string filename;
		std::string s1;
		std::string s2;

	public:
		void	handleArgs(int argc, char **argv);
		void	setArgs(char *argv1, char *argv2, char *argv3);
		void	fileReplace();
};
#endif