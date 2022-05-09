#include <jumpy_engine/vector3D.h>

#include "../types/renderable.h"
#include "components.h"


namespace game
{
    namespace components
    {
        class MeshPoints : public Component<Renderable>
        {
            public:
                MeshPoints() = default;
                MeshPoints(game::types::Vertices vertices) : vertices(vertices) {}

            private:
                game::types::Vertices vertices;
        };
    }
}
