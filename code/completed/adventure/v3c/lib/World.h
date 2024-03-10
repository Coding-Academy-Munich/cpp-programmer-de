// Copyright (c) 2023 Dr. Matthias Hölzl. All rights reserved.

#pragma once
#ifndef COMPLETED_ADVENTURE_V3C_WORLD_H
#define COMPLETED_ADVENTURE_V3C_WORLD_H

#include "Location.h"
#include <ostream>
#include <string>
#include <unordered_map>

namespace adventure::v3c {

class World {
public:
    World(const World&) = delete;
    World(World&&) noexcept = default;
    World& operator=(const World&) = delete;
    World& operator=(World&&) = default;

    [[nodiscard]] const Location& GetLocation(const std::string& name) const;
    [[nodiscard]] Location& GetLocation(const std::string& name);

    [[nodiscard]] const std::unordered_map<std::string, Location>& GetLocations() const;
    [[nodiscard]] const std::string& GetInitialLocationName() const;

private:
    explicit World(std::string initialLocationName);
    friend class WorldFactory;

    std::unordered_map<std::string, Location> locations;
    std::string initialLocationName;
};

std::ostream& operator<<(std::ostream& os, const World& world);
} // namespace adventure::v3c

#endif // COMPLETED_ADVENTURE_V3C_WORLD_H
