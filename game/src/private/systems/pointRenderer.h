#include <vector>

#include "system.h"

#include <jumpy_engine/vector3D.h>


namespace {
    using Vertices = std::vector<math::Vector3D>;
}


namespace game
{
    namespace systems
    {
        class PointRenderer : public System
        {
            public:
                PointRenderer() {}
                PointRenderer(Vertices const &vertices) : vertices(vertices) {}

                virtual void render() override
                {
                }

            private:
                Vertices vertices;
        };
    }
}
