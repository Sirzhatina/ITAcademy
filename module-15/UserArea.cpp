#include "UserArea.h"

#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QMainWindow>
#include <QComboBox>
#include <QVBoxLayout>
#include <QFormLayout>

UserArea::UserArea(QMainWindow* parent) 
    : QWidget(parent)
    , m_topLayout{ new QVBoxLayout{this} }
    , m_formLayout{ new QFormLayout{}  }
    , m_convertControls{ 
        {"Input",    new QLineEdit{this}},
        {"Currency", new QComboBox{this}} 
    }
    , m_button{     new QPushButton{this} }
    , m_resultLine{ new QLineEdit{this} }
    , m_errorMsg{   new QMessageBox{
        QMessageBox::Critical,
        "Error!",
        "Invalid input!",
        QMessageBox::Ok,
        this
    }}
{
    initUI();

    connect(m_button, &QPushButton::clicked, [this]() { m_resultLine->setText(convertCurrency()); });
}

void UserArea::initUI() {
    m_button->setText("Convert");

    m_topLayout->addLayout(m_formLayout);
    m_topLayout->addWidget(m_button);
    m_topLayout->addWidget(m_resultLine);


    for (const auto& [k, v] : m_convertControls) {
        m_formLayout->addRow(k, v);

    }

    if (auto comboBox = getComboBox(); comboBox) {
        comboBox->addItems({ "USA", "RUB", "EUR" });
    }

    m_resultLine->setReadOnly(true);
}

QString UserArea::convertCurrency() {
    if (auto lineEdit = dynamic_cast<QLineEdit*>(m_convertControls["Input"]); lineEdit) {
        const auto inputText = lineEdit->text();

        if (!inputText.isEmpty()) {
            return convertImpl(inputText);
        }
    }
    return "";
}

QString UserArea::convertImpl(const QString& curr) {
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

QComboBox* UserArea::getComboBox() { return dynamic_cast<QComboBox*>(m_convertControls["Currency"]); }