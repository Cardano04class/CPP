#include "Span.hpp"

Span::Span() : _maxSize(0){}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers){}

Span::~Span(){}

Span &Span::operator=(const Span &rhs)
{
    if(this != &rhs)
    {
        _maxSize = rhs._maxSize;
        _numbers = rhs._numbers;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if(_numbers.size() >= _maxSize)
        throw std::runtime_error("Span Full");
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("No enough numbers to find a span");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    for(size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int span = static_cast<unsigned int>(sorted[i]- sorted[i -1]);
        if(span < minSpan)
            minSpan = span;

    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if(_numbers.size() <= 1)
        throw std::runtime_error("No enough numbers to find a span");
    
    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int> (*maxIt-*minIt);
}

unsigned int Span::getMaxSize() const
{
    return _maxSize;
}

const std::vector<int> &Span::getNumbers() const
{
    return _numbers;
}