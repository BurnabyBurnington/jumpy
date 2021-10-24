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
            void keyPressEvent(QKeyEvent * event);

        private:
            GLuint vertexBufferId;  // A bind point for the OpenGL data
            QTimer timer;

            void checkKeyState();

        // TODO : Check if I can make tis private
        // TODO : Rename this method later
        //
        public slots:
            void myUpdate();
    };
};
