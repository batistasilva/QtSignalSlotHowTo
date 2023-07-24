#ifndef FIRSTDIALOG_H
#define FIRSTDIALOG_H

#include <QDialog>
#include <QDebug>
#include "ui_firstdialog.h"

namespace Ui {
class FirstDialog;
}

class FirstDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FirstDialog(QWidget *parent = nullptr);
    ~FirstDialog();

private slots:
    void sendTextDataToSecond();
    void sendTextDataToMain();
    void sendCommanToMain();
    void firstReceiveDataFromAnyOne(const QString &text);

signals:
    void sendTextSignalToSecond(const QString &text);
    void sendTextSignalToMain(const QString &text);
    void askTextSignalToMain();

private:
    Ui::FirstDialog *ui;
};

#endif // FIRSTDIALOG_H
