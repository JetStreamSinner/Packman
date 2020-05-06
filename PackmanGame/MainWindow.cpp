#include "MainWindow.h"

MainWindow::MainWindow(QMainWindow * parent) : QMainWindow(parent)
{
    _view = std::make_unique<SceneView>();
    setCentralWidget(_view.get());
}
