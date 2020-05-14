#include "GameModel.h"
GameModel::GameModel()
{
    _sceneObjects.push_back(SceneBound());
}

std::vector<SceneObject> GameModel::sceneObjects() const
{
    return _sceneObjects;
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

Color GameModel::backgroundColor() const
{
    return _backgroundColor;
}