#include "seconddialog.h"


SecondDialog::SecondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondDialog)
{
    ui->setupUi(this);
}

SecondDialog::~SecondDialog()
{
    delete ui;
}

/**
 * Action to send data to First Window
 * using the emit with the signal
 * sendTextSignalToFirst(data to send)
 * @brief SecondDialog::sendTextDataToFirst()
 */
void SecondDialog::sendTextDataToFirst()
{
//    qDebug() << "Send data to First...";
    QString str_text = ui->secondFormLineEdit->text();
    emit this->sendTextSignalToFirst(str_text);
}

/**
 * Action to send data to Main Window
 * using the emit with the signal
 * sendTextSignalToMain(data to send)
 * @brief SecondDialog::sendTextDataToMain()
 */
void SecondDialog::sendTextDataToMain()
{
//    qDebug() << "Send data to Main...";
    QString str_text = ui->secondFormLineEdit->text();
    emit this->sendTextSignalToMain(str_text);
}

/**
 * Action to send command to the main window
 * to send some kind of data. Using the
 * emit askTextSignalToMain().
 * @brief SecondDialog::sendCommanToMain()
 */
void SecondDialog::sendCommanToMain()
{
    emit this->askTextSignalToMain();
}

/**
 * Action to receive data from anyone.
 * Can receive data from second window or
 * main window.
 * @brief SecondDialog::secondReceiveDataFromAnyOne
 * @param text
 */
void SecondDialog::secondReceiveDataFromAnyOne(const QString &text)
{
    QString str_text = "\nReceived data: " + text;
//    qDebug() << "Receive data to First..." << str_text;
    // Adding a new item to the list widget
    ui->secondFormTextEdit->insertPlainText(str_text);
}




