#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <cmath>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _exchangeRates;

        bool isValidDate(const std::string &date) const;
        bool isValidValue(const std::string &value) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &rhs);

        void loadDatabase(const std::string &filename);
        void processInputFile(const std::string &filename) const;
        double getExchangeRate(const std::string &date) const;
};