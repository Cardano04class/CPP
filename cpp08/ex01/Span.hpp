#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <limits>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _data;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &src);
        Span &operator=(const Span &rhs);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            if(_data.size() + std::distance(begin, end) > _maxSize)
                throw std::runtime_error("No Space left");
            _data.insert(_data.end(), begin, end);
        }
};
