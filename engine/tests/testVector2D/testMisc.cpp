#include <ctest.h>
#include <vector2D.h>

CTEST(vector_basics, test_initialization)
{
    engine::Vector2D vector {};

    ASSERT_EQUAL(vector.x, 0);
    ASSERT_EQUAL(vector.y, 0);
}
