#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double>_data;

		bool	isDigit(const std::string &data);
		bool	isValidDate(const std::string &date);
		static bool	isValidYear(const std::string &data, int &month, bool &isLeapYear);
		static bool	isValidMonth(const std::string &data, int &month, bool &isLeapYear);
		static bool	isValidDay(const std::string &data, int &month, bool &isLeapYear);

		bool	isValidPrice(const std::string &priceData, double &price);
		bool	isValidRate(const std::string &rateData, double &price);
		double	getRate(const std::string &date);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	printInputFile(const std::string &filename);
};

#endif
