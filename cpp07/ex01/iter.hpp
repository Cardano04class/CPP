#pragma once

#include <cstddef>

template <typename T>
void iter(T *arr, size_t const len, void(*fct)(T const &))
{
    if (!arr || !len)
        return;

    for (size_t i = 0; i < len; i++)
        fct(arr[i]);
}

template <typename T>
void iter(T *arr, size_t const len, void(*fct)(T &))
{
    if (!arr || !len)
        return;

    for (size_t i = 0; i < len; i++)
        fct(arr[i]);
}

