#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "FileCounter.h"

class Worker : public QObject
{
    Q_OBJECT

public:
    explicit Worker(QObject *parent = 0);

    // Ask to start file counting in the directory in variable dpath
    void startCounting(const QString &dpath);

private:
    // directory to store path for searching files
    QString path;

signals:

    // Signla to start counting
    void countFilesRequest();

    // signal briefing that all files have been counted
    void filescounted(const QString &value);

    // signal notifying file counting is finsi
    void finished();

public slots:

    void countFiles();
};

#endif // WORKER_H
