#include "Span.hpp"

Span::Span() : _maxSize(0){}

Span::Span(unsigned int N) : _maxSize(N){}

Span::Span(const Span &src) : _maxSize(src._maxSize), _data(src._data){}

Span::~Span(){}

Span &Span::operator=(const Span &rhs)
{
    if(this != &rhs)
    {
        _maxSize = rhs._maxSize;
        _data = rhs._data;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_data.size() >= _maxSize)
        throw std::runtime_error("Reached Max Size");
    _data.push_back(number);
}

int Span::longestSpan() const
{
    if (_data.size() <= 1)
        throw std::runtime_error("No enough Numbers");
    std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());

    return *maxIt-*minIt;
}

int Span::shortestSpan() const
{
    if (_data.size() <= 1)
        throw std::runtime_error("No enough Numbers");
    std::vector<int>sorted = _data;
    std::sort(sorted.begin(), sorted.end());

    int shortest = std::numeric_limits<int>::max();

    for(size_t i = 1; i < sorted.size(); ++i)
    {
        int span = sorted[i] - sorted[i-1];
        if(span < shortest)
            shortest = span;
    }
    return shortest;
}
