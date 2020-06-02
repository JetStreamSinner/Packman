//
// Created by alex on 03.06.2020.
//

#ifndef PACKMANGAME_RENDERER_H
#define PACKMANGAME_RENDERER_H

#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GameModel.h"

class Renderer {
public:
    explicit Renderer(const std::shared_ptr<GameModel> model);
    void render();

private:
    void renderBackground();
    std::shared_ptr<GameModel> _model;
};


#endif //PACKMANGAME_RENDERER_H
