#include "fileCopier.h"
#include <QWidget>
#include <QDir>
#include <QFileInfoList>
#include <QFile>
#include "filereader.h"

#include <QDebug>

#define ORIGIN "C:/Documents/tests/FileSync/CP/FROM/"
#define DESTINATION "C:/Documents/tests/FileSync/CP/TO/"

fileCopier::fileCopier()
{

}

void fileCopier::copyFromOrigin(QString ogDest, QString newDest)
{
    QDir orig(ogDest);
    QDir dest(newDest);
    QFile fileOper;

    QString ogFile = ogDest;
    QString newFile = newDest;

    QFileInfoList file = orig.entryInfoList();
    fileReader reader;
    if(!dest.exists()){
        dest.mkdir(dest.path());
    }

    if(orig.exists() && dest.exists()){

        for(int i = 0; i < file.size(); i++){
            ogFile+=file.at(i).fileName();
            newFile+=file.at(i).fileName();

//            if()

            qDebug() << ogFile;
            qDebug() << newFile;

            if(QFile(newFile).exists()){
                if(!reader.areFilesEqual(ogFile,newFile)){
                    QFile::remove(newFile);
                    QFile::copy(ogFile, newFile);
                }

            }else{
                QFile::copy(ogFile, newFile);
            }
            ogFile = ORIGIN;
            newFile = DESTINATION;

        }

    }
}




