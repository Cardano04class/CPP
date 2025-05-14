#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int fixedPointValue;
        static const int fractionalBits;
    public:
        Fixed();
        Fixed(const int rawInt);
        Fixed(const float rawFloat);
        Fixed (const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat(void) const;
        int toInt(void) const;
};
    std::ostream& operator<< (std::ostream& out, const Fixed& value);
#endif