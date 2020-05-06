#ifndef _SCENE_
#define _SCENE_

#include <QOpenGLWidget>

class SceneView : public QOpenGLWidget
{
    Q_OBJECT

// public declaration
public:
    explicit SceneView(QOpenGLWidget * parent = nullptr);

// private declaration
private:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
};

#endif