#pragma once

#include <QCloseEvent>
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
            bool quitRequested = false;

            inline void createViewport();
            void updateVelocity(float scalar);
            void closeEvent(QCloseEvent *event) { this->quitRequested = true; event->accept(); };

        public:
            bool allowUserInput();
            bool needsQuit() { return this->quitRequested; };
            void simulate(double delta);
    };
}
