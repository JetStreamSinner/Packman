//
// Created by alex on 03.06.2020.
//

#ifndef PACKMANGAME_GAMEMODEL_H
#define PACKMANGAME_GAMEMODEL_H

struct Color
{
    Color(float _red, float _green, float _blue, float _alpha) :
    red(_red), green(_green), blue(_blue), alpha(_alpha)
    {

    }

    float red;
    float green;
    float blue;
    float alpha;
};

struct Vertex
{
    float x;
    float y;
    float z;
};

class GameModel
{
public:
    GameModel();
    Color backgroundColor() const;

private:
    Color _backgroundColor;
};


#endif //PACKMANGAME_GAMEMODEL_H
