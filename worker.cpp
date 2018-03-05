#include "worker.h"

#include <QThread>

Worker::Worker(QObject *parent) :
    QObject(parent)
{
}

void Worker::startCounting(const QString &dpath)
{
    path = dpath;
    emit countFilesRequest();
}

void Worker::countFiles()
{
    FileCounter *F = new FileCounter(path);

    F->CountingFiles();

    QString returnString = "Path: " + path + "\nhas " + QString::number(F->returnCounter()) + " files";


    emit filescounted(returnString);
    emit finished();
    delete F;
}
