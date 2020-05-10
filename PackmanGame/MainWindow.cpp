#include "MainWindow.h"

MainWindow::MainWindow(QMainWindow * parent) : QMainWindow(parent)
{
    _view = std::make_unique<SceneView>();

    auto model = std::make_shared<GameModel>();
    model->setBackgroundColor(127, 255, 0, 1);
    _view->setModel(model);


    setCentralWidget(_view.get());
}
