#pragma once
#ifndef PRINT_INFO_HPP
#define PRINT_INFO_HPP

#include <iostream>
#include <iomanip>
#include <utility>
#include <string_view>

template <typename T>
void print_bool(T&& value)
{
    std::cout
        << "boolean value is "
        << std::boolalpha << bool(std::forward<T>(value)) << "\n";
}

template <typename T>
void print_bool(std::string_view name, T&& value)
{
    std::cout
        << "boolean value of " << name << " is "
        << std::boolalpha << bool(std::forward<T>(value)) << "\n";
}

template <typename T>
void print_null(T&& value)
{
    if (std::forward<T>(value) == nullptr)
    {
        std::cout << "value is nullptr\n";
    } else {
        std::cout << "value is not nullptr" << std:: endl;
    }
}

template <typename T>
void print_null(std::string_view name, T&& value)
{
    if (std::forward<T>(value) == nullptr)
    {
        std::cout << "value of " << name << " is nullptr\n";
    } else {
        std::cout << "value of " << name << " is not nullptr" << std:: endl;
    }
}

template <typename T>
void print_use_count(T&& ptr)
{
    std::cout << "use count is " << std::forward<T>(ptr).use_count() << "\n";
}

template <typename T>
void print_use_count(std::string_view name, T&& ptr)
{
    std::cout << "use count of " << name << " is " << std::forward<T>(ptr).use_count() << "\n";
}

#endif // PRINT_INFO_HPP