#!/bin/bash
echo "Compiling..."
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o convert

echo -e "\nTesting all cases:\n"

./convert 0
./convert nan
./convert nanf
./convert 42
./convert -42
./convert a
./convert 'z'
./convert '*'
./convert 2147483647          # INT_MAX
./convert -2147483648         # INT_MIN
./convert 2147483648          # > int
./convert -2147483649         # < int
./convert 42.0f
./convert 42.0
./convert -42.1f
./convert 4.2f
./convert -4.2f
./convert 4.2
./convert -inff
./convert +inff
./convert -inf
./convert +inf
./convert 123.456f
./convert 123.456
./convert 999999999999999999999.9   # huge double
./convert ""                        # empty string
./convert "hello"                   # invalid
./convert "42a42"                   # invalid
./convert "42.42.42"                # invalid
./convert "f42"                     # invalid float (no dot)

echo -e "\nAll tests done!\n"