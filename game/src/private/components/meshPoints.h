#include <jumpy_engine/vector3D.h>

#include "../types/renderable.h"
#include "components.h"


namespace game
{
    namespace components
    {
        class MeshPoints : public Component<MeshPoints>
        {
            public:
                MeshPoints() = default;
                MeshPoints(game::types::Vertices vertices) : vertices(vertices) {}

                game::types::Vertex getFromIndex(unsigned int index) { return this->vertices[index]; }

                game::types::Vertices::size_type getSize() { return this->vertices.size(); }

            private:
                game::types::Vertices vertices;
        };
    }
}
