#include <GL/glew.h>

#include <jumpy_engine/vector3D.h>

#include "../componentHandler.h"
#include "pointRenderer.h"

namespace game
{
    namespace systems
    {
        void PointRenderer::render()
        {
            // TODO: Change all foo.component.bar calls to just foo.bar. Overload operator-> or something
            for (auto &entity : this->registeredEntities)
            {
                game::componentHandler::Handler<game::components::Transform> transform;
                game::componentHandler::Handler<game::components::MeshPoints> points;
                this->world->unpack(entity, points);

                // To get OpenGL to send the data to RAM so it becomes part of
                // the processing pipeline, you have to tell OpenGL about some
                // attribute. Attribute `0` is an arbitrary value, it could be
                // any number, really. But because we only have 1 attribute
                // (position), we use 0 as the 1st index in order to mean
                // "position".
                //
                // TODO: Move this later to a global variable, probably
                //
                GLuint attributeIndex {0};
                glEnableVertexAttribArray(attributeIndex);

                // We now need to describe the attribute and data to OpenGL. We say
                // that the attribute is a float with a size of 3 (because it's a Vector3D).
                //
                glVertexAttribPointer(
                    attributeIndex,
                    math::Vector3D::size,
                    GL_FLOAT,
                    GL_FALSE,
                    0,
                    0
                );

                auto count = points.component.getSize();
                math::Vector3D transformedVertices[count];

                auto const fullTransform = transform.component.get();

                for (unsigned int index = 0; index < count; ++index)
                {
                    transformedVertices[index] = fullTransform * points.component.getFromIndex(index);
                }

                // Send data to OpenGL
                glBufferSubData(
                    GL_ARRAY_BUFFER,
                    0,
                    sizeof(transformedVertices),
                    transformedVertices
                );

                // Draw the points
                glDrawArrays(GL_TRIANGLES, 0, count);
            }
        }
    }
}
