#include <ctest.h>
#include <vector2D.h>

CTEST(vector_basics, test_initialization)
{
    engine::Vector2D vector {};

    ASSERT_EQUAL(0, vector.x);
    ASSERT_EQUAL(0, vector.y);
}
