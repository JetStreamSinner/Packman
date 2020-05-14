#include "SceneBound.h"

SceneBound::SceneBound()
{
    _vertexes = {
        Vertex(QVector3D(-0.8f,  0.8f, 1.0f), QVector3D(1.0f, 0.0f, 0.0f)),
        Vertex(QVector3D(0.8f, 0.8f, 1.0f), QVector3D(0.0f, 1.0f, 0.0f)),
        Vertex(QVector3D(0.8f, -0.8f, 1.0f), QVector3D(0.0f, 0.0f, 1.0f)),
        Vertex(QVector3D(-0.8f, -0.8f, 1.0f), QVector3D(0.0f, 0.0f, 1.0f))
    };

    _drawMode = Mode::LineLoop;
}