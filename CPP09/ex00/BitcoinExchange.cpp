#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream csvfile("data.csv");//data.csvを読み込む
	if (!csvfile)
		throw std::runtime_error("data.csv: could not open file.");
	std::string line;
	std::getline(csvfile, line);
	if (line != "date,exchange_rate") {
		throw std::runtime_error("data.csv: wrong format");
	}
	while (std::getline(csvfile, line)) {//一行ずつ詠み込む
		std::stringstream ss(line);
		std::string date;
		std::string rateData;
		double price;

		if (std::getline(ss, date, ',') && std::getline(ss, rateData)) {
			if (!isValidDate(date) || !isValidRate(rateData, price))
				throw std::runtime_error("data.csv: invalid date format");
			_data[date] = price;//日付をキーにして価格をdataに登録
		} else {
			throw std::runtime_error("data.csv: wrong format");
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
		_data = other._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::printInputFile(const std::string &filename) {
	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
		throw std::runtime_error(filename + ": could not open file.");
	std::string line;
	std::getline(inputFile, line);
	if (line != "date | value") {
		throw std::runtime_error(filename + ": wrong format");
	}
	while (std::getline(inputFile, line)) {
		std::stringstream ss(line);
		// 日付
		std::string date;
		if (!std::getline(ss, date, ' ') || !isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		// " | "のvalidate
		std::string token;
		if (!std::getline(ss, token, ' ') || token != "|") {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		// price && rate
		std::string priceData;
		double price;
		if (!std::getline(ss, priceData) || !isValidPrice(priceData, price)) {
			continue;
		}
		double rate;
		try {
			rate = getRate(date);
		} catch (std::runtime_error& e) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		// 出力
		std::cout << date << " => " << price << " = " << rate*price << std::endl;
	}
}

bool	BitcoinExchange::isDigit(const std::string& data) {
	for (std::string::const_iterator it = data.begin(); it != data.end(); ++it) {
		if (!std::isdigit(*it)) {
			return false;
		}
	}
	return true;
}

bool	BitcoinExchange::isValidYear(const std::string &data, int &month, bool &isLeapYear) {
	(void)month;
	int year = std::atoi(data.c_str());
	if (year < 2009 || 2100 < year) {
		return false;
	}
	if (year % 4 == 0) {
		if (year % 100 != 0)
			isLeapYear = true;
	}
	return true;
}

bool	BitcoinExchange::isValidMonth(const std::string &data, int &month, bool &isLeapYear) {
	int month_tmp = std::atoi(data.c_str());
	if (month_tmp < 1 || 12 < month_tmp) {
		return false;
	}
	if (isLeapYear && month_tmp != 2) {
		isLeapYear = false;
	}
	month = month_tmp;
	return true;
}

bool	BitcoinExchange::isValidDay(const std::string &data, int &month, bool &isLeapYear) {
	int dayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear) {
		dayInMonth[1] = 29;
	}
	int day = std::atoi(data.c_str());
	if (day < 1 || dayInMonth[month-1] < day) {
		return false;
	}
	return true;
}

//YYYY-MM-DD
bool	BitcoinExchange::isValidDate(const std::string &date) {
	if (date.length() != 10)
		return false;
	
	int	month;
	bool	isLeapYear = false;
	
	typedef bool (*Validator)(const std::string&, int&, bool&);
	Validator	validators[3] = {isValidYear, isValidMonth, isValidDay};

	std::istringstream	ss(date);
	for (size_t i = 0; i < 3; ++i) {
		std::string token;
		if (!std::getline(ss, token, '-')) {
			return false;
		}
		if (!isDigit(token)) {
			return false;
		}
		if (!validators[i](token, month, isLeapYear)) {
			return false;
		}
	}
	return true;
}

bool	BitcoinExchange::isValidPrice(const std::string &priceData, double &price) {
	std::stringstream ss(priceData);

	if (!(ss >> price)) {//文字列をdouble型に変換
		std::cerr << "Error: Invalid format." << std::endl;
		return false;
	}
	if (price < 0.0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	} else if (1000.0 < price) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::isValidRate(const std::string &rateData, double &price) {
	std::stringstream ss(rateData);

	ss >> price;//文字列をdouble型に変換
	if (ss.fail() || !ss.eof())
		return false;
	return true;
}

double BitcoinExchange::getRate(const std::string &date) {
	std::map<std::string, double>::iterator it = _data.upper_bound(date);//upper_boundは指定された日付より後の最初の要素を指すイテレータを返す
	if (it != _data.end()) {
		if (it == _data.begin())
			throw std::runtime_error("Error: date is out of range");
		--it;
		return it->second;
	} else {
		throw std::runtime_error("Error: date is out of range");
	}
}