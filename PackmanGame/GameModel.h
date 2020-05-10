#ifndef _GAME_MODEL_
#define _GAME_MODEL_

#include <QOpenGLFunctions>

struct Color
{
    GLfloat _red;
    GLfloat _green;
    GLfloat _blue;
    GLfloat _alpha;
};

class GameModel
{

// public declaration
public:
    explicit GameModel();
    
    void setBackgroundColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat aplha);
    void setBackgroundColor(const Color &backgroundColor);
    Color backgroundColor();

// private declaration
private:
    Color _backgroundColor;
};

#endif