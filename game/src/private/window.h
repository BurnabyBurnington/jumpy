#pragma once

#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/qgl.h>  // Needed for `GLuint`

class QKeyEvent;

namespace game {
    class Window : public QGLWidget {
        protected:
            virtual void initializeGL();
            virtual void paintGL();

        private:
            GLuint vertexBufferId;  // A bind point for the OpenGL data

            void updateVelocity(float scalar);
            void rotateShip(float scalar);

        public:
            void simulate(double delta);
    };
}
