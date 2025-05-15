#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0){
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    fixedPointValue = other.fixedPointValue;
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->fixedPointValue = other.fixedPointValue;
    // std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    fixedPointValue = raw;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;    
}
Fixed::Fixed (const int rawInt)
{
    fixedPointValue = rawInt * 256;
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float rawFloat)
{
    fixedPointValue = roundf(rawFloat * 256);
    // std::cout << "Float constructor called" << std::endl;

}

float Fixed::toFloat(void) const{
    return (float)fixedPointValue / 256;
}

int Fixed::toInt(void) const{
    return fixedPointValue / 256;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
    out << value.toFloat();
    return out;
}

/*comparison operators*/
bool Fixed::operator<(const Fixed& rhs) const
{
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>(const Fixed& rhs) const
{
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return this->getRawBits() != rhs.getRawBits();
}

/*arithmetic operators*/
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;

    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;

    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(Fixed const & rhs) const {
    return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) const {
    return (this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++ ()
{
    ++fixedPointValue;
    return *this;
}

Fixed Fixed::operator++ (int)
{
    Fixed tmp = *this;
    ++fixedPointValue;
    return tmp;
}

Fixed& Fixed::operator-- ()
{
    --fixedPointValue;
    return *this;
}

Fixed Fixed::operator-- (int)
{
    Fixed tmp = *this;
    --fixedPointValue;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
