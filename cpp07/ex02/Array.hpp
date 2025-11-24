#pragma once

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
    private:
        T *elements;
        unsigned int _size;
    public:
        Array() : elements(NULL), _size(0){}
        Array(unsigned int n) : _size(n)
        {
            elements = new T[n]();
        }
        Array(const Array &other) : elements(NULL), _size(0) {*this = other;}

        Array &operator=(const Array &other)
        {
            if (this != &other)
            {
                if(elements)
                    delete[] elements;
                _size = other._size;
                elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    elements[i] = other.elements[i];
            }
            return *this;
        }
        ~Array()
        {
           if (elements)
            delete[] elements; 
        }
        T &operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::exception();
            return elements[index];
        }

        const T &operator[](unsigned int index) const
        {
            if (index >= _size)
                throw std::exception();
            return elements[index];
        }

        unsigned int size() const
        {
            return _size;
        }
};