#include <cassert>
#include <ctest.h>
#include <vector3D.h>

// TODO: Add tests with a huge int value
// TODO: Add tests to ensure the + operator can be chained repeatedly

CTEST(additionConstOperators, scalar) {
    auto const first = math::Vector3D {10, 12, -32};

    auto const vector1 = first + 2;
    ASSERT_FLOAT_EQUAL(12, vector1.x);
    ASSERT_FLOAT_EQUAL(14, vector1.y);
    ASSERT_FLOAT_EQUAL(-30, vector1.z);

    auto const vector2 = first + -20;
    ASSERT_FLOAT_EQUAL(-10, vector2.x);
    ASSERT_FLOAT_EQUAL(-8, vector2.y);
    ASSERT_FLOAT_EQUAL(-52, vector2.z);
}

CTEST(additionConstOperators, vector) {
    auto const first = math::Vector3D {10, 12, -341};
    auto const second = math::Vector3D {-2, 100, 10};

    auto const vector1 = first + second;

    ASSERT_FLOAT_EQUAL(8, vector1.x);
    ASSERT_FLOAT_EQUAL(112, vector1.y);
    ASSERT_FLOAT_EQUAL(-331, vector1.z);

    auto const vector2 = second + first;

    ASSERT_FLOAT_EQUAL(8, vector2.x);
    ASSERT_FLOAT_EQUAL(112, vector2.y);
    ASSERT_FLOAT_EQUAL(-331, vector2.z);
}

// TODO: Is reflexive addition possible in C++ if the types differ?
// Double-check this. Do the same for multiplication, too
//
CTEST(additionOperators, scalar) {
    auto first = math::Vector3D {10, 12, -32};

    auto vector1 = first + 2;
    ASSERT_FLOAT_EQUAL(12, vector1.x);
    ASSERT_FLOAT_EQUAL(14, vector1.y);
    ASSERT_FLOAT_EQUAL(-30, vector1.z);

    auto vector2 = first + -20;
    ASSERT_FLOAT_EQUAL(-10, vector2.x);
    ASSERT_FLOAT_EQUAL(-8, vector2.y);
    ASSERT_FLOAT_EQUAL(-52, vector2.z);
}

CTEST(additionOperators, vector) {
    auto first = math::Vector3D {10, 12, -341};
    auto second = math::Vector3D {-2, 100, 10};

    auto vector1 = first + second;

    ASSERT_FLOAT_EQUAL(8, vector1.x);
    ASSERT_FLOAT_EQUAL(112, vector1.y);
    ASSERT_FLOAT_EQUAL(-331, vector1.z);

    auto vector2 = second + first;

    ASSERT_FLOAT_EQUAL(8, vector2.x);
    ASSERT_FLOAT_EQUAL(112, vector2.y);
    ASSERT_FLOAT_EQUAL(-331, vector2.z);
}
