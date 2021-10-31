#include <cassert>
#include <ctest.h>
#include <vector3D.h>

// TODO: Add tests with a huge int value
// TODO: Add tests to ensure the + operator can be chained repeatedly

// TODO: Is reflexive plus_equal possible in C++ if the types differ?
// Double-check this. Do the same for multiplication, too
//
CTEST(plusEqualOperators, scalar) {
    auto vector_1 = math::Vector3D {10, 12, -134};
    vector_1 += 2;
    ASSERT_EQUAL(12, vector_1.x);
    ASSERT_EQUAL(14, vector_1.y);
    ASSERT_EQUAL(-132, vector_1.z);

    auto vector_2 = math::Vector3D {10, 12, -231};
    vector_2 += -20;
    ASSERT_EQUAL(-10, vector_2.x);
    ASSERT_EQUAL(-8, vector_2.y);
    ASSERT_EQUAL(-251, vector_2.z);
}

CTEST(plusEqualOperators, vector) {
    auto vector1 = math::Vector3D {10, 12, -100};
    auto vector2 = math::Vector3D {-2, 100, 451};

    vector1 += vector2;
    ASSERT_EQUAL(8, vector1.x);
    ASSERT_EQUAL(112, vector1.y);
    ASSERT_EQUAL(351, vector1.z);

    auto vector3 = math::Vector3D {-30, -34, 130};
    auto vector4 = math::Vector3D {4, 300, -800};

    vector4 += vector3;
    ASSERT_EQUAL(-26, vector4.x);
    ASSERT_EQUAL(266, vector4.y);
    ASSERT_EQUAL(-670, vector4.z);
}
