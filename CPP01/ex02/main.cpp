/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:49:00 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/12 21:56:29 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(){
	const std::string myString = "HI THIS IS BRAIN";
	const std::string *strPTR = &myString;
	const std::string &strREF = myString;

	std::cout << "[address]" << std::endl;
	std::cout << "myString: " << &myString << std::endl;
	std::cout << "strPTR: " << strPTR << std::endl;
	std::cout << "strREF: " << &strREF << std::endl;

	std::cout << "[value]" << std::endl;
	std::cout << "myString: " << myString << std::endl;
	std::cout << "strPTR: " << *strPTR << std::endl;
	std::cout << "strREF: " << strREF << std::endl;

    return 0;
}
