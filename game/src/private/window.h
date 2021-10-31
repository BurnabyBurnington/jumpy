#pragma once

#include <QtCore/QTimer>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/qgl.h>  // Needed for `GLuint`

class QKeyEvent;

namespace game {
    class Window : public QGLWidget {
        Q_OBJECT

        protected:
            virtual void initializeGL();
            virtual void paintGL();

        private:
            GLuint vertexBufferId;  // A bind point for the OpenGL data
            QTimer timer;

            void updateVelocity(float scalar);
            void rotateShip(float scalar);

        // TODO : Check if I can make tis private
        // TODO : Rename this method later
        //
        public slots:
            void myUpdate();
    };
};
