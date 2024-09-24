#pragma once

#include <QWidget>

class QMainWindow;
class QLineEdit;
class QPushButton;
class QMessageBox;
class QComboBox;
class QVBoxLayout;
class QFormLayout;

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

    QVBoxLayout* m_topLayout;
    QFormLayout* m_formLayout;

    std::map<QString, QWidget*> m_convertControls;

    QPushButton* m_button;
    QLineEdit* m_resultLine;

    QMessageBox* m_errorMsg;
};