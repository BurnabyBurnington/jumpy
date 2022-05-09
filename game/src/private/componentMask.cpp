#include "componentMask.h"

namespace game
{
    namespace componentMask
    {
        bool Mask::isMatch(Mask const &other) const
        {
            return (this->mask & other.mask) == other.mask;
        }

        bool Mask::isNewMatch(Mask const &old, Mask const &reference) const
        {
            return this->isMatch(reference) && !old.isMatch(reference);
        }

        bool Mask::isNoLongerMatched(Mask const &old, Mask const &reference) const
        {
            return old.isMatch(reference) && !this->isMatch(reference);
        }
    }
}
