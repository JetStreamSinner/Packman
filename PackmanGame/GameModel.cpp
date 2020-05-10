#include "GameModel.h"
GameModel::GameModel()
{

}

void GameModel::setBackgroundColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    _backgroundColor._red = red;
    _backgroundColor._green = green;
    _backgroundColor._blue = blue;
    _backgroundColor._alpha = alpha;
}

void GameModel::setBackgroundColor(const Color &backgroundColor)
{
    _backgroundColor = backgroundColor;
}

Color GameModel::backgroundColor()
{
    return _backgroundColor;
}