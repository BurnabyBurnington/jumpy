#include <vector>

#include "../componentHandler.h"
#include "../components/components.h"
#include "../components/meshPoints.h"
#include "../types/renderable.h"
#include "../world.h"
#include "system.h"

#include <jumpy_engine/vector3D.h>


namespace game
{
    namespace systems
    {
        class PointRenderer : public System
        {
            public:
                PointRenderer() {
                    this->signature.addComponent<game::components::MeshPoints>();
                    this->signature.addComponent<game::components::Renderable>();
                }

                virtual void render() override
                {
                    for (auto &entity : this->registeredEntities)
                    {
                        game::componentHandler::Handler<game::components::MeshPoints> points;
                        this->world->unpack(entity, points);

                        // TODO: Make this prettier, later. e.g.
                        // `points.rotate()`, instead of
                        // `points.component.rotate()`
                        //
                        std::cout << "Got points maybe\n";
                    }
                }
        };
    }
}
