#ifndef _SCENE_OBJECT_
#define _SCENE_OBJECT_

#include <vector>
#include "../Vertex.h"

enum class Mode {
    Points = 0x0000,
    Lines = 0x0001,
    LineLoop = 0x0002,
    LineStrip = 0x0003,
    Triangles = 0x0004,
    TriangleStrip = 0x0005,
    TriangleFan = 0x0006,
    Quads = 0x0007,
    QuadsStrip = 0x0008,
    Polygon = 0x0009
};

class SceneObject
{
public:
    virtual std::vector<Vertex> sourceData() const
    {
        return _vertexes;
    }
    virtual Mode drawMode() const
    {
        return _drawMode;
    }
protected:
    Mode _drawMode;
    std::vector<Vertex> _vertexes;
};

#endif