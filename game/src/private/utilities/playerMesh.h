#include <jumpy_engine/vector3D.h>

#include "../types/renderable.h"


namespace {
    auto const SQUARE_ROOT_ZERO_POINT_ZERO_TWO {0.141421356f};

    const std::vector<math::Vector3D> VERTICES = {
        {-0.0f, SQUARE_ROOT_ZERO_POINT_ZERO_TWO, 1},
        {-0.1f, -0.1f, 1},
        {+0.1f, -0.1f, 1},
    };
}


namespace game
{
    namespace utilities
    {
        game::types::Vertices makePlayerMesh()
        {
            return VERTICES;
        }
    }
}
