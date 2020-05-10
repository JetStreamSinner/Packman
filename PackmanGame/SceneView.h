#ifndef _SCENE_
#define _SCENE_

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include "GameModel.h"

class SceneView : public QOpenGLWidget
{
    Q_OBJECT

// public declaration
public:
    explicit SceneView(std::shared_ptr<GameModel> model = nullptr, QOpenGLWidget * parent = nullptr);

    void setModel(std::shared_ptr<GameModel> model);
    GameModel model() const;

// private declaration
private:


    std::shared_ptr<GameModel> _model = nullptr;

    std::unique_ptr<QOpenGLBuffer> VBO = nullptr;
    std::unique_ptr<QOpenGLBuffer> EBO = nullptr;
    std::unique_ptr<QOpenGLVertexArrayObject> VAO = nullptr;



    std::unique_ptr<QOpenGLShader> vertexShader = nullptr;
    std::unique_ptr<QOpenGLShader> fragmentShader = nullptr;
    std::unique_ptr<QOpenGLShaderProgram> shaderProgram = nullptr;
    std::unique_ptr<QOpenGLVertexArrayObject> vertexArrayObject = nullptr;

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
};

#endif