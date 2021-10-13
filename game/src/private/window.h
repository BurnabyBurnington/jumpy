#pragma once

#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/qgl.h>  // Needed for `GLuint`

namespace game {
    class Window : public QGLWidget {
        private:
            GLuint vertexBufferId;

        protected:
            virtual void initializeGL();
            virtual void paintGL();
    };
};
