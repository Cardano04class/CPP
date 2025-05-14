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

        /*comparison operators*/
        bool operator<(const Fixed& rhs) const;
        bool operator>(const Fixed& rhs) const;
        bool operator<=(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs) const;
        bool operator==(const Fixed& rhs) const;
        bool operator!=(const Fixed& rhs) const;    
        /*arithmetic operators*/
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        /*increment/decrement*/
        Fixed& operator++ ();
        Fixed& operator-- ();
        Fixed operator++ (int);
        Fixed operator-- (int);
        /* min/max */
        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b); 
        static const Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream& operator<< (std::ostream& out, const Fixed& value);

#endif