#ifndef _SCENE_
#define _SCENE_

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include "GameModel.h"
#include "SceneObjects/SceneBound.h"

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

    struct DrawingObject
    {
        std::unique_ptr<QOpenGLBuffer> vbo = nullptr;
        std::unique_ptr<QOpenGLVertexArrayObject> vao = nullptr;
        Mode drawMode;
    };


    std::shared_ptr<GameModel> _model = nullptr;
    std::vector <DrawingObject> _drawingObjects;



    std::unique_ptr<QOpenGLShader> vertexShader = nullptr;
    std::unique_ptr<QOpenGLShader> fragmentShader = nullptr;
    std::unique_ptr<QOpenGLShaderProgram> shaderProgram = nullptr;

    DrawingObject makeObjectFromSource(const SceneObject &object);
    void initializePipeline();
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
};

#endif