#include "firstdialog.h"

FirstDialog::FirstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstDialog)
{
    ui->setupUi(this);   
}

FirstDialog::~FirstDialog()
{
    delete ui;
}

/**
 * Action to send data to Second Window
 * using the emit with the signal
 * sendTextSignalToSecond(data to send)
 * @brief FirstDialog::sendTextDataToSecond
 */
void FirstDialog::sendTextDataToSecond()
{
//    qDebug() << "Send data to Second...";
    QString str_text = ui->firstFormLineEdit->text();
    emit this->sendTextSignalToSecond(str_text);
}

/**
 * Action to send data to Main Window
 * using the emit with the signal
 * sendTextSignalToMain(data to send)
 * @brief FirstDialog::sendTextDataToMain
 */
void FirstDialog::sendTextDataToMain()
{
//    qDebug() << "Send data to Main...";
    QString str_text = ui->firstFormLineEdit->text();
    emit this->sendTextSignalToMain(str_text);
}

/**
 * Action to send command to the main window
 * to send some kind of data. Using the
 * emit askTextSignalToMain().
 * @brief FirstDialog::sendCommanToMain()
 */
void FirstDialog::sendCommanToMain()
{
//    qDebug() << "Ask Text data to Main...";
    emit this->askTextSignalToMain();
}

/**
 * Action to receive data from anyone.
 * Can receive data from second window or
 * main window.
 * @brief FirstDialog::firstReceiveDataFromAnyOne
 * @param text
 */
void FirstDialog::firstReceiveDataFromAnyOne(const QString &text)
{
    QString str_text = "\nReceived data: " + text;
    qDebug() << "Receive data from Second..." << str_text;
    // Adding a new item to the list widget
    ui->firstFormTextEdit->insertPlainText(str_text);
}


