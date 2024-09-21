#include <QApplication>
#include <QMainWindow>
#include <QScreen>

class MainWindow : public QMainWindow {
public:
    MainWindow();

private:
    QSize getInitialSize();


};

int main(int argc, char* argv[])
{
    QApplication app{ argc, argv };

    MainWindow mw{};

    mw.show();

    return app.exec();
}


MainWindow::MainWindow() {
    setWindowTitle("Currency converter");
    setFixedSize(getInitialSize());
}

QSize MainWindow::getInitialSize() {
    const auto screenSize = this->screen()->size();

    const QSize targetSize{
        static_cast<int>(screenSize.width() / 2.0),
        static_cast<int>(screenSize.height() / 2.0)
    };
    return targetSize;
}