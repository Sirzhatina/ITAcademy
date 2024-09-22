#include <QApplication>
#include <QMainWindow>
#include <QScreen>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>
#include <map>

class UserArea : public QWidget {
public:
    Q_OBJECT
public:
    UserArea(QMainWindow* parent = nullptr) : QWidget(parent) {
        initUI();

        connect(m_button, &QPushButton::clicked, [this]() { m_resultLine->setText(convertCurrency()); });
    }

private:
    void initUI();
    QString convertCurrency() {
        if (auto lineEdit = dynamic_cast<QLineEdit*>(m_convertControls["Input"]); lineEdit) {
            const auto inputText = lineEdit->text();

            if (!inputText.isEmpty()) {
                return convertImpl(inputText);
            }
        }
        return "";
    }
    QString convertImpl(const QString& curr) {
        auto cb = getComboBox();
        if (!cb) {
            return "";
        }

        bool ok = false;
        double res = curr.toDouble(&ok);
        if (!ok) {
            m_errorMsg->show();
            return "";
        }

        res *= (cb->currentIndex() + 1) * 100;
        return QVariant(res).toString();
    }


    QComboBox* getComboBox() { return dynamic_cast<QComboBox*>(m_convertControls["Currency"]); }


    QVBoxLayout m_topLayout{ this };
    QFormLayout m_formLayout;

    std::map<QString, QWidget*> m_convertControls{
        {"Input", new QLineEdit{this}},
        {"Currency", new QComboBox{this}}
    };

    QPushButton* m_button{ new QPushButton{this} };
    QLineEdit* m_resultLine{ new QLineEdit{this} };

    QMessageBox* m_errorMsg{ new QMessageBox{
                        QMessageBox::Critical,
                        "Error!",
                        "Invalid input!",
                        QMessageBox::Ok,
                        this 
    }};
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

    if (auto comboBox = getComboBox(); comboBox) {
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

#include "main.moc"