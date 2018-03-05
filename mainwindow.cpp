#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thread = new QThread();
    worker = new Worker();

    connect(worker, SIGNAL(countFilesRequest()), thread, SLOT(start()));
    connect(thread, SIGNAL(started()), worker, SLOT(countFiles()));
    connect(worker, SIGNAL(filescounted(QString)), this, SLOT(addCountToWidget(QString)));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()), Qt::DirectConnection);
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
        worker->startCounting(path);
    }
}
