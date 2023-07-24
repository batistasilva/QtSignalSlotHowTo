#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Instantiating the forms
    QObject::connect(this,                                //Extance to Main Window
                     SIGNAL(sendToFirstText(QString)),    //Signal to emit in Main Window
                     &first,                              //Extance to First Window
                     SLOT(firstReceiveDataFromAnyOne(QString)));//Slot to Receive in First Window
    QObject::connect(this,                                //Extance to Main Window
                     SIGNAL(sendToSecondText(QString)),   //Signal to emit in Main Window
                     &second,                              //Extance to Second Window
                     SLOT(secondReceiveDataFromAnyOne(QString)));//Slot to Receive in Second Window
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * Action to Open First Window
 * @brief MainWindow::runFirstWindow
 */
void MainWindow::runFirstWindow()
{
    //First Send to Second...
    QObject::connect(
        &first,                                  //Extance to First Window
        SIGNAL(sendTextSignalToSecond(QString)), //Signal to emit in First Window
        &second,                                 //Extance to Second Window
        SLOT(secondReceiveDataFromAnyOne(QString)));//Slot to Receive in Second Window

    //First Send to Main...
    QObject::connect(
        &first,                               //Extance to First Window
        SIGNAL(sendTextSignalToMain(QString)),//Signal to emit in First Window
        this,                                 //Extance to Main Window
        SLOT(receiveDataFromFirst(QString))); //Slot to Receive in Main Window

    //First Send Command to Main...
    QObject::connect(
        &first,                        //Extance to First Window
        SIGNAL(askTextSignalToMain()), //Signal to emit in First Window
        this,                           //Extance to Main Window
        SLOT(receiveRequestFromFirst()));//Slot to Execute an Action in Main Window

    // Showing them
    first.show();
}

/**
 * Action to Open Second Window
 * @brief MainWindow::runSecondWindow
 */
void MainWindow::runSecondWindow()
{
    //Second Send to First...
    QObject::connect(
        &second,                                  //Extance to Second Window
        SIGNAL(sendTextSignalToFirst(QString)),   //Signal to emit in Second Window
        &first,                                   //Extance to First Window
        SLOT(firstReceiveDataFromAnyOne(QString)));//Slot to receive in First Window

    //Second Send to Main...
    QObject::connect(
        &second,                              //Extance to Second Window
        SIGNAL(sendTextSignalToMain(QString)),//Signal to emit in Second Window
        this,                                 //Extance to Main Window
        SLOT(receiveDataFromSecond(QString)));//Slot to receive in Main Window

    //Second Send Command to Main...
    QObject::connect(
        &second,                         //Extance to Second Window
        SIGNAL(askTextSignalToMain()),   //Signal to emit in Second Window
        this,                            //Extance to Main Window
        SLOT(receiveRequestFromSecond()));//Slot to Execute an Action in Main Window

    second.show();
}

/**
 * Action to send data to First Window
 * using the emit with the signal
 * sendToFirstText(data to send)
 * @brief MainWindow::runMainSendToFirst()
 */
void MainWindow::runMainSendToFirst()
{
//    qDebug() << "Main Send data to First...";
    QString str_text = ui->mainLineEdit->text();
    emit this->sendToFirstText(str_text);
}

/**
 * Action to send data to Second Window
 * using the emit with the signal
 * sendToSecondText(data to send)
 * @brief MainWindow::runMainSendToSecond()
 */
void MainWindow::runMainSendToSecond()
{
    qDebug() << "Main Send data to Second...";
    // Emitting a signal with the new text
    QString str_text = ui->mainLineEdit->text();
    emit this->sendToSecondText(str_text);
}

/**
 * Action to receive data from First Window.
 * @brief MainWindow::receiveDataFromFirst
 * @param text
 */
void MainWindow::receiveDataFromFirst(const QString &text)
{
    QString str_text = "\nReceived from First: " + text;
    ui->mainTextEdit->insertPlainText(str_text);
}

/**
 * Action to receive data from Second Window.
 * @brief MainWindow::receiveDataFromSecond
 * @param text
 */
void MainWindow::receiveDataFromSecond(const QString &text)
{
    QString str_text = "\nReceived from Second: " + text;
    ui->mainTextEdit->insertPlainText(str_text);
}

/**
 * Action to execute command to First Window Call.
 * @brief MainWindow::receiveRequestFromFirst()
 */
void MainWindow::receiveRequestFromFirst()
{
    runMainSendToFirst();
}

/**
 * Action to execute command to Second Window Call.
 * @brief MainWindow::receiveRequestFromSecond()
 */
void MainWindow::receiveRequestFromSecond()
{
    runMainSendToSecond();
}

