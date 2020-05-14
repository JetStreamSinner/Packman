#ifndef _BASE_TYPES_
#define _BASE_TYPES_
#include <QOpenGLWidget>

struct Color
{
    GLfloat _red;
    GLfloat _green;
    GLfloat _blue;
    GLfloat _alpha;

    Color() { }
    Color(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) :
        _red(red), _green(green), _blue(blue), _alpha(alpha) {}
};

#endif