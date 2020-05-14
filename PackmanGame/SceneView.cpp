#include "SceneView.h"
#include "Vertex.h"
#include <QDebug>

static const Vertex sg_vertexes[] = {
  Vertex(QVector3D(0.00f,  0.75f, 1.0f), QVector3D(1.0f, 0.0f, 0.0f)),
  Vertex(QVector3D(0.75f, -0.75f, 1.0f), QVector3D(0.0f, 1.0f, 0.0f)),
  Vertex(QVector3D(-0.75f, -0.75f, 1.0f), QVector3D(0.0f, 0.0f, 1.0f))
};

SceneView::SceneView(std::shared_ptr<GameModel> model, QOpenGLWidget* parent) : _model(model), 
    QOpenGLWidget(parent)
{

}

void SceneView::initializePipeline()
{
    vertexShader = std::make_unique<QOpenGLShader>(QOpenGLShader::Vertex);
    bool vertexShaderStatus = vertexShader->compileSourceFile("D:/Work/PackmanGame/PackmanGame/Shaders/VertexShader.glsl");

    fragmentShader = std::make_unique<QOpenGLShader>(QOpenGLShader::Fragment);
    bool fragmentShaderStatus = fragmentShader->compileSourceFile("D:/Work/PackmanGame/PackmanGame/Shaders/FragmentShader.glsl");

    shaderProgram = std::make_unique<QOpenGLShaderProgram>();
    shaderProgram->addShader(vertexShader.get());
    shaderProgram->addShader(fragmentShader.get());
    bool shaderProgramStatus = shaderProgram->link();
    shaderProgram->bind();

    shaderProgram->enableAttributeArray(0);
    shaderProgram->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
    shaderProgram->enableAttributeArray(1);
    shaderProgram->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

    qDebug() << "Shader program state:" << shaderProgramStatus;
    qDebug() << "Vertex shader state:" << vertexShaderStatus;
    qDebug() << "Fragment shader state:" << fragmentShaderStatus;
}

void SceneView::initializeGL()
{
    QOpenGLFunctions * openGLFunctions = QOpenGLContext::currentContext()->functions();
    openGLFunctions->initializeOpenGLFunctions();

    openGLFunctions->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    auto sceneObjects = _model->sceneObjects();
    for (const auto& sceneObject : sceneObjects)
        _drawingObjects.push_back(makeObjectFromSource(sceneObject));

/*
    VAO = std::make_unique<QOpenGLVertexArrayObject>();
    VAO->create();
    VAO->bind();

    VBO = std::make_unique<QOpenGLBuffer>(QOpenGLBuffer::VertexBuffer);
    VBO->create();
    VBO->setUsagePattern(QOpenGLBuffer::StaticDraw);
    VBO->bind();
    VBO->allocate(_model->sceneObjects().at(0).sourceData().data(), sizeof(Vertex) * sizeof(sceneBound.sourceData().data()));

    
    VBO->release();
    VAO->release();*/
}

SceneView::DrawingObject SceneView::makeObjectFromSource(const SceneObject &sceneObject)
{
    DrawingObject object;
    object.drawMode = sceneObject.drawMode();

    object.vao = std::make_unique<QOpenGLVertexArrayObject>();
    object.vao->create();
    object.vao->bind();

    object.vbo = std::make_unique<QOpenGLBuffer>(QOpenGLBuffer::VertexBuffer);
    object.vbo->create();
    object.vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
    object.vbo->bind();
    object.vbo->allocate(sceneObject.sourceData().data(), sizeof(Vertex) * sizeof(sceneObject.sourceData().data()));

    object.vbo->release();
    object.vao->release();
    return object;
}

void SceneView::paintGL()
{

    QOpenGLFunctions * openGLFunctions = QOpenGLContext::currentContext()->functions();
    openGLFunctions->glClear(GL_COLOR_BUFFER_BIT);

    shaderProgram->bind();

    for (const auto &drawingObject : _drawingObjects) {
        drawingObject.vao->bind();
        openGLFunctions->glDrawArrays(static_cast<int>(drawingObject.drawMode), 0, 4);
    }
   /* VAO->bind();
    openGLFunctions->glDrawArrays(GL_LINE_LOOP, 0, 4);
    */
}

void SceneView::resizeGL(int width, int height)
{
    QOpenGLFunctions * openGLFunctions = QOpenGLContext::currentContext()->functions();
    openGLFunctions->glViewport(0, 0, width, height);
}

void SceneView::setModel(std::shared_ptr<GameModel> model)
{
    _model = model;
}

GameModel SceneView::model() const
{
    return *_model;
}