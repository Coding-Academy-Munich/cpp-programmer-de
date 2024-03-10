// Copyright (c) 2023 Dr. Matthias Hölzl. All rights reserved.

#ifndef COMPLETED_ADVENTURE_V6A_LIB_ACTIONS_INVESTIGATEACTION_H
#define COMPLETED_ADVENTURE_V6A_LIB_ACTIONS_INVESTIGATEACTION_H

#include "Action.h"
#include "ActionTag.h"

namespace adventure::v6a {

class InvestigateAction : public Action {
public:
    InvestigateAction() = default;

    [[nodiscard]] std::string Description() const override;
    [[nodiscard]] ActionTagSet Tags() const override;
    void Perform(Player& instigator) const override;

protected:
    [[nodiscard]] bool Equals(const Action& other) const override;
};

} // namespace adventure::v6a

#endif // COMPLETED_ADVENTURE_V6A_LIB_ACTIONS_INVESTIGATEACTION_H
