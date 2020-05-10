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

void SceneView::initializeGL()
{
    QOpenGLFunctions * openGLFunctions = QOpenGLContext::currentContext()->functions();
    openGLFunctions->initializeOpenGLFunctions();

    openGLFunctions->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    vertexShader = std::make_unique<QOpenGLShader>(QOpenGLShader::Vertex);
    bool vertexShaderStatus = vertexShader->compileSourceFile("D:/Work/PackmanGame/PackmanGame/Shaders/VertexShader.glsl");

    fragmentShader = std::make_unique<QOpenGLShader>(QOpenGLShader::Fragment);
    bool fragmentShaderStatus = fragmentShader->compileSourceFile("D:/Work/PackmanGame/PackmanGame/Shaders/FragmentShader.glsl");

    shaderProgram = std::make_unique<QOpenGLShaderProgram>();
    shaderProgram->addShader(vertexShader.get());
    shaderProgram->addShader(fragmentShader.get());
    bool shaderProgramStatus = shaderProgram->link();
    shaderProgram->bind();



    qDebug() << "Shader program state:" << shaderProgramStatus;
    qDebug() << "Vertex shader state:" << vertexShaderStatus;
    qDebug() << "Fragment shader state:" << fragmentShaderStatus;

    VBO = std::make_unique<QOpenGLBuffer>(QOpenGLBuffer::VertexBuffer);
    bool vboStatus = VBO->create();
    VBO->bind();
    VBO->setUsagePattern(QOpenGLBuffer::StaticDraw);
    VBO->allocate(sg_vertexes, sizeof(sg_vertexes));

    VAO = std::make_unique<QOpenGLVertexArrayObject>();
    VAO->create();
    VAO->bind();

    shaderProgram->enableAttributeArray(0);
    shaderProgram->enableAttributeArray(1);
    shaderProgram->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
    shaderProgram->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

    VBO->release();
    VAO->release();
    shaderProgram->release();

  
}

void SceneView::paintGL()
{

    QOpenGLFunctions * openGLFunctions = QOpenGLContext::currentContext()->functions();
    openGLFunctions->glClear(GL_COLOR_BUFFER_BIT);
    shaderProgram->bind();
    VAO->bind();
    openGLFunctions->glDrawArrays(GL_TRIANGLES, 0, sizeof(sg_vertexes) / sizeof(sg_vertexes[0]));
    VAO->release();
    shaderProgram->release();
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