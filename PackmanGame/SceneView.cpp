#include <QOpenGLFunctions>
#include "SceneView.h"
SceneView::SceneView(QOpenGLWidget * parent) : QOpenGLWidget(parent)
{

}

void SceneView::initializeGL()
{
    QOpenGLFunctions * openGLFunctions = QOpenGLContext::currentContext()->functions();
    openGLFunctions->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void SceneView::paintGL()
{

}

void SceneView::resizeGL(int width, int height)
{

}

