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

    // vector for all working threads
    std::vector<QThread*> threadVec;

    // vector for all workers in progress
    std::vector<Worker*> workerVec;
};

#endif // MAINWINDOW_H
