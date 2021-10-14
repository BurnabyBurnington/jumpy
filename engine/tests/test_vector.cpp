#include <vector2D.h>
#include <cassert>
#include "ctest.h"

CTEST(suite1, test1) {
    auto first {1};
    auto second {1};

    ASSERT_EQUAL(first, second);
}

CTEST(suite1, test2) {
    auto first {1};
    auto second {2};

    ASSERT_EQUAL(first, second);
}

CTEST(suite2, test1) {
    auto first {2};
    auto second {2};

    ASSERT_EQUAL(first, second);
}
