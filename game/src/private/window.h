#pragma once

#include <QtOpenGL/QGLWidget>

namespace game {
    class Window : public QGLWidget {
        protected:
            virtual void initializeGL();
    };
};
