#pragma once

#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QMainWindow>


class UserArea : public QWidget {
public:
    Q_OBJECT
public:
    UserArea(QMainWindow* parent = nullptr);

private:
    void initUI();

    QString convertCurrency();
    QString convertImpl(const QString& curr);


    QComboBox* getComboBox();

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
    } };
};