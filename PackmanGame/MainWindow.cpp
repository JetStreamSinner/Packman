#include "MainWindow.h"

MainWindow::MainWindow(QMainWindow * parent) : QMainWindow(parent)
{
    _view = new SceneView;
    setCentralWidget(_view);
}