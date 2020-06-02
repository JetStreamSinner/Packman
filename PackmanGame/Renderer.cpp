//
// Created by alex on 03.06.2020.
//

#include "Renderer.h"
Renderer::Renderer(const std::shared_ptr<GameModel> model) : _model(model)
{

}

void Renderer::renderBackground()
{
    Color backgroundColor = _model->backgroundColor();
    glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.green,
                 backgroundColor.blue);
}

void Renderer::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    renderBackground();
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(0, 1);
    glVertex2d(1, 1);
    glVertex2d(1, 0);
    glEnd();

}