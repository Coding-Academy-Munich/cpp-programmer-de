// Copyright (c) 2023 Dr. Matthias Hölzl. All rights reserved.

#pragma once
#ifndef COMPLETED_ADVENTURE_V6A_LIB_STRATEGIES_SELECTHELPFULACTION_H
#define COMPLETED_ADVENTURE_V6A_LIB_STRATEGIES_SELECTHELPFULACTION_H

#include "SelectActionStrategy.h"

namespace adventure::v6a {

class SelectHelpfulAction : public SelectActionStrategy {
public:
    SelectHelpfulAction() = default;
    [[nodiscard]] ActionPtr SelectAction(
        const Player& player, const ActionVec& actions) const override;
};

} // namespace adventure::v6a

#endif // COMPLETED_ADVENTURE_V6A_LIB_STRATEGIES_SELECTHELPFULACTION_H
