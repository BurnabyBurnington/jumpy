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

CTEST(additionConstOperators, scalarReflexivity) {
    auto const first = math::Vector3D {10, 12, -10};
    auto const vector3 = first + -100;
    auto const vector4 = -100.0f + first;

    ASSERT_FLOAT_EQUAL(-90, vector3.x);
    ASSERT_FLOAT_EQUAL(-88, vector3.y);
    ASSERT_FLOAT_EQUAL(-110, vector3.z);
    ASSERT_FLOAT_EQUAL(-90, vector4.x);
    ASSERT_FLOAT_EQUAL(-88, vector4.y);
    ASSERT_FLOAT_EQUAL(-110, vector4.z);
    ASSERT_FLOAT_EQUAL(vector3.x, vector4.x);
    ASSERT_FLOAT_EQUAL(vector3.y, vector4.y);
    ASSERT_FLOAT_EQUAL(vector3.z, vector4.z);
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

CTEST(additionConstOperators, vectorReflexivity) {
    auto const first = math::Vector3D {10, 12, -10};
    auto const second = math::Vector3D {25, -35, 3};
    auto const result1 = first + second;
    auto const result2 = second + first;

    ASSERT_FLOAT_EQUAL(35, result1.x);
    ASSERT_FLOAT_EQUAL(-23, result1.y);
    ASSERT_FLOAT_EQUAL(-7, result1.z);
    ASSERT_FLOAT_EQUAL(35, result2.x);
    ASSERT_FLOAT_EQUAL(-23, result2.y);
    ASSERT_FLOAT_EQUAL(-7, result2.z);
    ASSERT_FLOAT_EQUAL(result1.x, result2.x);
    ASSERT_FLOAT_EQUAL(result1.y, result2.y);
    ASSERT_FLOAT_EQUAL(result1.z, result2.z);
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

CTEST(additionOperators, scalarReflexivity) {
    auto first = math::Vector3D {10, 12, -10};
    auto vector3 = first + -100;
    auto vector4 = -100.0f + first;

    ASSERT_FLOAT_EQUAL(-90, vector3.x);
    ASSERT_FLOAT_EQUAL(-88, vector3.y);
    ASSERT_FLOAT_EQUAL(-110, vector3.z);
    ASSERT_FLOAT_EQUAL(-90, vector4.x);
    ASSERT_FLOAT_EQUAL(-88, vector4.y);
    ASSERT_FLOAT_EQUAL(-110, vector4.z);
    ASSERT_FLOAT_EQUAL(vector3.x, vector4.x);
    ASSERT_FLOAT_EQUAL(vector3.y, vector4.y);
    ASSERT_FLOAT_EQUAL(vector3.z, vector4.z);
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

CTEST(additionOperators, vectorReflexivity) {
    auto first = math::Vector3D {10, 12, -10};
    auto second = math::Vector3D {25, -35, 3};
    auto result1 = first + second;
    auto result2 = second + first;

    ASSERT_FLOAT_EQUAL(35, result1.x);
    ASSERT_FLOAT_EQUAL(-23, result1.y);
    ASSERT_FLOAT_EQUAL(-7, result1.z);
    ASSERT_FLOAT_EQUAL(35, result2.x);
    ASSERT_FLOAT_EQUAL(-23, result2.y);
    ASSERT_FLOAT_EQUAL(-7, result2.z);
    ASSERT_FLOAT_EQUAL(result1.x, result2.x);
    ASSERT_FLOAT_EQUAL(result1.y, result2.y);
    ASSERT_FLOAT_EQUAL(result1.z, result2.z);
}
