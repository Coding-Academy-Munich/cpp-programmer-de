// Copyright (c) 2023 Dr. Matthias Hölzl. All rights reserved.

#pragma once
#ifndef COMPLETED_ADVENTURE_V3C_LOCATION_H
#define COMPLETED_ADVENTURE_V3C_LOCATION_H

#include "LocationData.h"
#include <ostream>
#include <string>

namespace adventure::v3c {

class Location {
public:
    Location(std::string name, std::string description);
    explicit Location(const data::LocationData& locationData);

    [[nodiscard]] const std::string& GetName() const { return name; }
    [[nodiscard]] const std::string& GetDescription() const { return description; }

    [[nodiscard]] const Location& GetConnectedLocation(const std::string& direction) const;
    void SetConnectedLocation(const std::string& direction, Location& location);
    [[nodiscard]] std::vector<std::string> GetConnectedDirections() const;

    bool operator==(const Location& rhs) const;
    bool operator!=(const Location& rhs) const;

private:
    std::string name;
    std::string description;
    std::unordered_map<std::string, Location*> connectedLocations{};
};

std::ostream& operator<<(std::ostream& os, const Location& location);
}

#endif // COMPLETED_ADVENTURE_V3C_LOCATION_H
