#ifndef FILECOUNTER_H
#define FILECOUNTER_H

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <QString>

class FileCounter
{
    public:

        FileCounter(QString dpath);

        ~FileCounter();

        /*
            A public caller function that makes a call to search and count files in a specific path
            Variable directorypath is the path to the folder which files are counted in
            return count of all files in variable directorypath and all its subfolders
         */
        void CountingFiles();

        int returnCounter();

    private:

        QString path;

        /* counter for all files in a file path */
        unsigned int filecounter;

        /* structure variable entry contains all the information of folder and file */
        struct dirent *entry;

        /*
            Count all files in a single folder
            variable directorypath is the path to the folder which files are counted in
            return a count of all files in the folder from variable directorypath
         */
        void countFilesInFolder(const char *directorypath);

        /* find subfolders to search for files in */
        void findSubFolders(const char *directorypath);

        /*
            Create a new path from the folder path variable directorypath, appending the new folder found from the private pointer variable entry
            return new path to search for files and folders
        */
        char *createNewPath(const char *directorypath);
};

#endif // FILECOUNTER_H
