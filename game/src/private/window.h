#pragma once

#include <QCloseEvent>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/qgl.h>  // Needed for `GLuint`

#include "world.h"


class QKeyEvent;

namespace game {
    class Window : public QGLWidget {
        public:
            Window (game::World *world) : world(world) {}

            bool allowUserInput();
            bool needsQuit() { return this->quitRequested; };
            void simulate(double delta);

        protected:
            virtual void initializeGL();
            virtual void paintGL();

        private:
            GLuint vertexBufferId;  // A bind point for the OpenGL data
            game::World *world;

            bool quitRequested = false;

            inline void createViewport();
            void updateVelocity(float scalar);
            void closeEvent(QCloseEvent *event) { this->quitRequested = true; event->accept(); };
    };
}
