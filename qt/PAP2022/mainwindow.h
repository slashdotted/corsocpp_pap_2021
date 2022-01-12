#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "alpha.h"
#include "beta.h"

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
    void on_bottone_clicked();
    void valoreCambiato(int);

private:
    Ui::MainWindow *ui;
    Alpha *a;
    Beta *b;
};
#endif // MAINWINDOW_H
