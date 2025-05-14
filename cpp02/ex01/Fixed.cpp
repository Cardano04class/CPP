#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPointValue(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    fixedPointValue = other.fixedPointValue;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->fixedPointValue = other.fixedPointValue;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    fixedPointValue = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;    
}
Fixed::Fixed (const int rawInt)
{
    fixedPointValue = rawInt << fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float rawFloat)
{
    fixedPointValue = roundf(rawFloat *(1 << fractionalBits));
        std::cout << "Float constructor called" << std::endl;

}

float Fixed::toFloat(void) const{
    float floatValue;

    floatValue = fixedPointValue / float(1 << fractionalBits);
    return floatValue;
}

int Fixed::toInt(void) const{
    int intValue;
    intValue = fixedPointValue >> fractionalBits;
    return intValue;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
    out << value.toFloat();
    return out;
}