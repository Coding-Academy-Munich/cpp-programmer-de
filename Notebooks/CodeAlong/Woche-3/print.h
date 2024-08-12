#pragma once
#ifndef PRINT_H
#define PRINT_H

#include "nlohmann/json.hpp"
#include <iostream>

template <typename T>
void print(std::string_view type_name, const T& value)
{
    std::cout << type_name << ": m1 = " << value.m1 << ", m2 = " << value.m2
              << ", addr = " << addr(value) << '\n';
}

template <typename T>
std::string addr_(const T* ptr)
{
    std::stringstream ss;
    ss << std::hex << ptr;
    return ss.str();
}

template <typename T>
std::string addr(const T& ref)
{
    return addr_(&ref);
}

#endif // PRINT_H