#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &rhs);
        ~Span();

        void addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            if(std::distance(begin, end) > static_cast<long>(_maxSize - _numbers.size()))
                throw std::runtime_error("Not enough space to add all elements in range");
            _numbers.insert(_numbers.end(), begin, end);
        }

        unsigned int getMaxSize() const;
        const std::vector<int> &getNumbers() const;
};