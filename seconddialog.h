#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>
#include <QDebug>
#include "ui_seconddialog.h"

namespace Ui {
class SecondDialog;
}

class SecondDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecondDialog(QWidget *parent = nullptr);
    ~SecondDialog();

public slots:
    void sendTextDataToFirst();
    void sendTextDataToMain();
    void sendCommanToMain();
    void secondReceiveDataFromAnyOne(const QString &text);

signals:
    void sendTextSignalToFirst(const QString &text);
    void sendTextSignalToMain(const QString &text);
    void askTextSignalToMain();

private:
    Ui::SecondDialog *ui;
};

#endif // SECONDDIALOG_H
