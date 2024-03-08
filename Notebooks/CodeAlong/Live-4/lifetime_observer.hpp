#pragma once
#ifndef LIFETIME_OBSERVER_HPP
#define LIFETIME_OBSERVER_HPP

#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include "type_name.hpp"
#include "nlohmann/json.hpp"

struct Obs;
std::ostream& operator<<(std::ostream& os, const Obs& obs);

struct Obs
{
    int next_id() {
        static int count{0};
        return ++count;
    }

    Obs() : id{next_id()} { std::cout << "Obs(): " << *this << "\n"; }

    explicit Obs(int value) : value{value}, id{next_id()}
    {
        std::cout << "Obs(" << value << "): " << *this << "\n";
    }

    Obs(const Obs& other)
    {
        std::cout << "Obs(const Obs&): " << *this << ", " << other << "\n";
        value = other.value;
        id = next_id();
        std::cout << "            >>>: " << *this << "\n";
    }

    Obs(Obs&& other)
    {
        std::cout << "Obs(Obs&&): " << *this << ", " << other << "\n";
        value = std::move(other.value);
        id = next_id();
        std::cout << "       >>>: " << *this << "\n";
    }

    Obs& operator=(const Obs& other)
    {
        std::cout << "Obs::operator=(const Obs&): " << *this << ", " << other << "\n";
        value = other.value;
        id = next_id();
        std::cout << "                       >>>: " << *this << "\n";
        return *this;
    }

    Obs& operator=(Obs&& other)
    {
        std::cout << "Obs::operator=(Obs&&): " << *this << ", " << other << "\n";
        value = std::move(other.value);
        id = next_id();
        std::cout << "                  >>>: " << *this << "\n";
        return *this;
    }

    ~Obs() { std::cout << "~Obs(): " << *this << "\n"; }

    int value{0};
    int id{-1};
};

inline nl::json mime_bundle_repr(const Obs& obs)
{
    std::stringstream ss{};
    ss << "Obs{" << obs.value << ", " << obs.id << "} @" << &obs;
    auto bundle = nl::json::object();
    bundle["text/plain"] = ss.str();
    return bundle;
}

std::ostream& operator<<(std::ostream& os, const Obs& obs)
{
    // os << "Obs{" << obs.value << ", " << obs.id << "} @" << &obs;
    os << "Obs{" << obs.value << ", " << obs.id << "}";
    return os;
}

std::string to_string(const Obs& obs)
{
    std::stringstream ss{};
    ss << obs;
    return ss.str();
}

DEFINE_TYPE_NAME(Obs);

#endif // LIFETIME_OBSERVER_HPP