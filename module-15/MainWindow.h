#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow {
public:
    MainWindow();

private:
    QSize getInitialSize();

    QWidget* m_userArea;
};