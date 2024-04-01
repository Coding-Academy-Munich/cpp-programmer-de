#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "nlohmann/json.hpp"

namespace nl = nlohmann;

struct Point
{
    double x;
    double y;
    double z;
};

inline nl::json mime_bundle_repr(const Point& p)
{
    std::stringstream ss{};
    ss << "Point{" << p.x << ", " << p.y << ", " << p.z << "}";
    auto bundle = nl::json::object();
    bundle["text/plain"] = ss.str();
    return bundle;
}

inline nl::json mime_bundle_repr(const std::vector<Point>& path)
{
    std::stringstream ss{};
    ss << "std::vector<Point>{";
    std::string sep{" "};
    for (const auto& point : path) {
        ss << sep << "{" << point.x << ", " << point.y << ", " << point.z << "}";
        sep = ", ";
    }
    ss << " }";

    auto bundle = nl::json::object();
    bundle["text/plain"] = ss.str();
    return bundle;
}

inline std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "Point{" << p.x << ", " << p.y << ", " << p.z << "}";
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const std::vector<Point>& path)
{
    os << "std::vector<Point>{";
    std::string sep{" "};
    for (const auto& point : path) {
        os << sep << "{" << point.x << ", " << point.y << ", " << point.z << "}";
        sep = ", ";
    }
    os << " }";
    return os;
}

#endif // POINT_HPP