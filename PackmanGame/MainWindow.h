#ifndef _MAIN_WINDOW_
#define _MAIN_WINDOW_

#include <QMainWindow>
#include "SceneView.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
// Public declarations
public:
    explicit MainWindow(QMainWindow * parent = nullptr);
    //private declarations
private:
    SceneView * _view = nullptr;
};


#endif