#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QThread* newthread = new QThread();
    Worker* newworker = new Worker();

    workerVec.push_back(newworker);
    threadVec.push_back(newthread);
    newworker->moveToThread(newthread);

    for (unsigned int i = 0; i < workerVec.size(); i++)
    {
        connect(workerVec[i], SIGNAL(countFilesRequest()), threadVec[i], SLOT(start()));
        connect(threadVec[i], SIGNAL(started()), workerVec[i], SLOT(countFiles()));
        connect(workerVec[i], SIGNAL(filescounted(QString)), this, SLOT(addCountToWidget(QString)));
        connect(workerVec[i], SIGNAL(finished()), threadVec[i], SLOT(quit()), Qt::DirectConnection);

        if (threadVec[i]->isFinished())
        {
            delete threadVec[i];
            delete workerVec[i];
            workerVec.erase(workerVec.begin() + i);
            threadVec.erase(threadVec.begin() + i);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCountToWidget(QString count)
{
    ui->listWidget->addItem(count);
}

void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    path += "/";

    // If user cancels choosing directory worker does not request counting files
    if (path != "/")
    {
        workerVec[workerVec.size()-1]->startCounting(path);
    }
}
