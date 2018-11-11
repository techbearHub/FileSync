#include "fileCopier.h"
#include <QWidget>
#include <QDir>
#include <QFileInfoList>
#include <QFile>
#include "filereader.h"
#include <QTime>

#include <QDebug>


#define ORIGIN "C:/Documents/tests/FileSync/CP/FROM/"
#define DESTINATION "C:/Documents/tests/FileSync/CP/TO/"

void fileCopier::run()
{

    copyFromOrigin(ORIGIN, DESTINATION);
}

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
    if(!dest.exists()){
        dest.mkdir(dest.path());
    }


    if(orig.exists() && dest.exists()){
         QTime timer;
         timer.start();

        for(int i = 0; i < file.size(); i++){
            ogFile+=file.at(i).fileName();
            newFile+=file.at(i).fileName();

            if(QFile(newFile).exists()){
                if(!fileReader::areFilesEqual(ogFile,newFile)){
                    QFile::remove(newFile);
                    emit currentCopy(ogFile, false);
                    QFile::copy(ogFile, newFile);
                    emit currentCopy(ogFile, true);
                }

            }else{
                emit currentCopy(ogFile, false);
                QFile::copy(ogFile, newFile);
                emit currentCopy(ogFile, true);
            }
            ogFile = ogDest;
            newFile = newDest;

        }

        emit allDone();
        emit timeElapsed(timer.elapsed());

    }
}




