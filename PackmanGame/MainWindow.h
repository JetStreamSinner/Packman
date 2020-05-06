#ifndef _MAIN_WINDOW_
#define _MAIN_WINDOW_

#include <QMainWindow>
#include <memory>
#include "SceneView.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
// Public declarations
public:
    explicit MainWindow(QMainWindow * parent = nullptr);
    //private declarations
private:
    std::unique_ptr<SceneView> _view = nullptr;
};


#endif