#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _exchangeRates(src._exchangeRates){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        _exchangeRates = rhs._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

static std::string& ltrim(std::string &s)
{
    s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
    return s;
}
static std::string& rtrim(std::string &s)
{
    size_t end = s.find_last_not_of(" \t\n\r\f\v");

    if (std::string::npos != end)
        s.erase(end + 1);
    else
        s.clear();
    return s;
}

static std::string& trim(std::string &s)
{
    rtrim(s);
    ltrim(s);
    return s;
}

static bool split_once(const std::string &s, char sep, std::string &left, std::string &right)
{
    size_t pos = s.find(sep);
    if (pos == std::string::npos)
        return false;

    left = s.substr(0, pos);
    right = s.substr(pos + 1);

    trim(left);
    trim(right);

    return true;
}

static bool is_digits(const std::string &s)
{
    if(s.empty())
        return false;

    return s.find_first_not_of("0123456789") == std::string::npos;
}

static bool isLeapYear(int y) 
{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

static int daysInMonth(int year, int month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
        
    default:
        return 0;
    }
}

static bool parseDoubleSafely(const std::string& s, double& out)
{
    if (s.empty())
        return false;

    std::istringstream iss(s);

    iss >> out ;

    if (iss.fail() || !iss.eof())
        return false;
    if(!std::isfinite(out))
        return false;

    return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::string s_year = date.substr(0, 4);
    std::string s_month = date.substr(5, 2);
    std::string s_day = date.substr(8, 2);

    if (!is_digits(s_year) || !is_digits(s_month) || !is_digits(s_day))
        return false;
    
    int year, month, day;
    try
    {
        year = std::stoi(s_year);
        month = std::stoi(s_month);
        day = std::stoi(s_day);
    }
    catch(const std::exception& e)
    {
        return false;
    }

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > daysInMonth(year, month))
        return false;
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string &string_value) const
{
    double value;

    if (!parseDoubleSafely(string_value, value))
    {
        std::cerr << "Error: bad input => " << string_value << std::endl;
        return false;
    }

    if (value < 0) 
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (value > 1000) 
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{

}