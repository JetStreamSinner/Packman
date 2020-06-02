//
// Created by alex on 03.06.2020.
//

#include "GameModel.h"

GameModel::GameModel() : _backgroundColor(0.5f, 0.5f, 0.5f, 1.0f)
{

}

Color GameModel::backgroundColor() const
{
    return _backgroundColor;
}
