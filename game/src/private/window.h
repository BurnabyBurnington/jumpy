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

            bool allowedUserInput();
            void updateVelocity(float scalar);
            void rotateShip(float scalar);
            void closeEvent(QCloseEvent *event) { this->quitRequested = true; event->accept(); };

        public:
            void simulate(double delta);
            bool needsQuit() { return this->quitRequested; };
    };
}
