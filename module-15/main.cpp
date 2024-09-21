#include <QApplication>
#include <QMainWindow>
#include <QScreen>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <map>

class UserArea : public QWidget {
public:
    UserArea(QMainWindow* parent = nullptr) : QWidget(parent) {
        initUI();

    }

private:
    void initUI();


    QVBoxLayout m_topLayout{ this };
    QFormLayout m_formLayout;

    std::map<QString, QWidget*> m_convertControls{
        {"Input", new QLineEdit{this}},
        {"Currency", new QComboBox{this}}
    };

    QPushButton* m_button{ new QPushButton{this} };
    QLineEdit* m_resultLine{ new QLineEdit{this} };
};

class MainWindow : public QMainWindow {
public:
    MainWindow();

private:
    QSize getInitialSize();
    QWidget* m_userArea{ new UserArea{this} };
};

int main(int argc, char* argv[])
{
    QApplication app{ argc, argv };

    MainWindow mw{};

    mw.show();

    return app.exec();
}

void UserArea::initUI() {
    m_button->setText("Convert");

    m_topLayout.addLayout(&m_formLayout);
    m_topLayout.addWidget(m_button);
    m_topLayout.addWidget(m_resultLine);


    for (const auto& [k, v] : m_convertControls) {
        m_formLayout.addRow(k, v);

    }

    if (auto comboBox = dynamic_cast<QComboBox*>(m_convertControls["Currency"]); comboBox) {
        comboBox->addItems({ "USA", "RUB", "EUR" });
    }

    m_resultLine->setReadOnly(true);
}

MainWindow::MainWindow() {
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