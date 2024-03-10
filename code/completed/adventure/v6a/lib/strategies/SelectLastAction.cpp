// Copyright (c) 2023 Dr. Matthias Hölzl. All rights reserved.

#include "SelectLastAction.h"

namespace adventure::v6a {

ActionPtr SelectLastAction::SelectAction(
    const Player& player, const ActionVec& actions) const
{
    return actions.back();
}

} // namespace adventure::v6a