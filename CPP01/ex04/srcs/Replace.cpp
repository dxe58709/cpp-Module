/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:45:12 by nsakanou          #+#    #+#             */
/*   Updated: 2024/11/23 18:45:13 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Replace.hpp"
#include <cstdlib>

void	Replace::handleArgs(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (argv[1][0] == '\0' || argv[2][0] == '\0') {
		std::cout << "Error: empty argument" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void	Replace::setArgs(char *argv1, char *argv2, char *argv3) {
    filename = argv1;
    s1 = argv2;
    s2 = argv3;
}

void	Replace::fileReplace() {
    std::ifstream ifs(filename.c_str());//const char *
    std::string line;
    std::string::size_type n;

    if (ifs.fail()) {
        std::cerr << "Failed to open file." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::ofstream ofs((filename + ".replace").c_str());
    if (ofs.fail()) {
        std::cerr << "Failed to create/overwrite file: " << filename + ".replace" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    while (1) {
        std::getline(ifs, line);
        while (1) {
            n = line.find(s1);
            if (n == std::string::npos) {
                break; //find が s1 を見つけられなかった場合
            }
            ofs << line.substr(0, n) << s2;
            line = line.substr(n + s1.length());
        }
        ofs << line;
        if (ifs.eof()) {
            break;
        }
        ofs << std::endl;
    }
	ifs.close();
	ofs.close();
}
