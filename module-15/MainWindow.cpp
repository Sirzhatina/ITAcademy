#include "MainWindow.h"
#include "UserArea.h"
#include <QScreen>

MainWindow::MainWindow()
    : m_userArea{ new UserArea{this} }
{
    setWindowTitle("Currency converter");

    setFixedSize(getInitialSize());
    setCentralWidget(m_userArea);
}

QSize MainWindow::getInitialSize() {
    const auto screenSize = this->screen()->size();

    const QSize targetSize{
        static_cast<int>(screenSize.width() / 5.0),
        static_cast<int>(screenSize.height() / 5.0)
    };
    return targetSize;
}