#pragma once

#include <QMainWindow>
#include "UserArea.h"

class MainWindow : public QMainWindow {
public:
    MainWindow();

private:
    QSize getInitialSize();
    QWidget* m_userArea{ new UserArea{this} };
};