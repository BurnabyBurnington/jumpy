#include <cassert>
#include <ctest.h>
#include <matrix2D.h>
#include <vector2D.h>

// TODO: Add tests with a huge float value
// TODO: Add tests to ensure the + operator can be chained repeatedly

CTEST(matrixMultiplication, vector) {
    engine::Matrix2D matrix{2, -3, 4, -5};
    engine::Vector2D vector{3, 9};

    auto result = matrix * vector;

    ASSERT_EQUAL(-21, result.x);
    ASSERT_EQUAL(-33, result.y);
}
