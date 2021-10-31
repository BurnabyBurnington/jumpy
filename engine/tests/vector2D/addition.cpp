#include <cassert>
#include <ctest.h>
#include <vector2D.h>

// TODO: Add tests with a huge int value
// TODO: Add tests to ensure the + operator can be chained repeatedly

CTEST(additionConstOperators, scalar) {
    auto const first = math::Vector2D {10, 12};

    auto const vector1 = first + 2;
    ASSERT_EQUAL(12, vector1.x);
    ASSERT_EQUAL(14, vector1.y);

    auto const vector2 = first + -20;
    ASSERT_EQUAL(-10, vector2.x);
    ASSERT_EQUAL(-8, vector2.y);
}

CTEST(additionConstOperators, vector) {
    auto const first = math::Vector2D {10, 12};
    auto const second = math::Vector2D {-2, 100};

    auto const vector1 = first + second;

    ASSERT_EQUAL(8, vector1.x);
    ASSERT_EQUAL(112, vector1.y);

    auto const vector2 = second + first;

    ASSERT_EQUAL(8, vector2.x);
    ASSERT_EQUAL(112, vector2.y);
}

// TODO: Is reflexive addition possible in C++ if the types differ?
// Double-check this. Do the same for multiplication, too
//
CTEST(additionOperators, test_scalar) {
    auto first = math::Vector2D {10, 12};

    auto vector1 = first + 2;
    ASSERT_EQUAL(12, vector1.x);
    ASSERT_EQUAL(14, vector1.y);

    auto vector2 = first + -20;
    ASSERT_EQUAL(-10, vector2.x);
    ASSERT_EQUAL(-8, vector2.y);
}

CTEST(additionOperators, vector) {
    auto first = math::Vector2D {10, 12};
    auto second = math::Vector2D {-2, 100};

    auto vector1 = first + second;

    ASSERT_EQUAL(8, vector1.x);
    ASSERT_EQUAL(112, vector1.y);

    auto vector2 = second + first;

    ASSERT_EQUAL(8, vector2.x);
    ASSERT_EQUAL(112, vector2.y);
}
