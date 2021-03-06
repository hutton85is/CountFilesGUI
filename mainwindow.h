#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "worker.h"
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void addCountToWidget(QString);

private:
    Ui::MainWindow *ui;

    // Thread containing the working thread
    QThread* thread;

    // worker class does the file counting through FileCounter.h class
    Worker* worker;
};

#endif // MAINWINDOW_H
