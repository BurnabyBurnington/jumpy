#pragma once

#include "components/components.h"


// TODO : Review the code here to understand it better
namespace game
{
    namespace componentMask
    {
        class Mask {
            public:
                bool isMatch(Mask const &other) const;

                //Returns true if the system is now matched, but didn't used to be (based on `old`)
                bool isNewMatch(Mask const &old, Mask const &reference) const;

                //Returns true if the system is not matched, but used to be matched
                bool isNoLongerMatched(Mask const &old, Mask const &reference) const;

                template<typename Type>
                void addComponent() {
                    this->mask |= (1 << game::components::Component<Type>::family());
                }

            private:
                unsigned int mask {0};
        };
    }
}
