#include <vector>

#include "../components/components.h"
#include "../components/meshPoints.h"
#include "../world.h"
#include "system.h"


namespace game
{
    namespace systems
    {
        class PointRenderer : public System
        {
            public:
                PointRenderer()
                {
                    this->signature.addComponent<game::components::MeshPoints>();
                    this->signature.addComponent<game::components::Renderable>();
                }

                virtual void render() override;
        };
    }
}
