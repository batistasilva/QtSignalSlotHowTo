#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "firstdialog.h"
#include "seconddialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void runFirstWindow();
    void runSecondWindow();
    void runMainSendToFirst();
    void runMainSendToSecond();
    void receiveDataFromFirst(const QString &text);
    void receiveDataFromSecond(const QString &text);
    void receiveRequestFromFirst();
    void receiveRequestFromSecond();

signals:
    void sendToFirstText(const QString &text);//only to be used with (emit)
    void sendToSecondText(const QString &text);

private:
    Ui::MainWindow *ui;
    FirstDialog first;
    SecondDialog second;
};
#endif // MAINWINDOW_H
