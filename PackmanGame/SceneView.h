#ifndef _SCENE_
#define _SCENE_

#include <QOpenGLWidget>
#include "GameModel.h"

class SceneView : public QOpenGLWidget
{
    Q_OBJECT

// public declaration
public:
    explicit SceneView(QOpenGLWidget * parent = nullptr);

// private declaration
private:

    std::unique_ptr<GameModel> _model = nullptr;

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
};

#endif