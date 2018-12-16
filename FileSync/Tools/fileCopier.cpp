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
    copyFromOrigin(ogDest,newDest);
}

fileCopier::fileCopier()
{

}

void fileCopier::copyFromOrigin(QString source, QString destination)
{
    QDir orig(source);
    QDir dest(destination);
    QFile fileOper;


    QString ogFile = source;
    QString newFile = destination;
    qDebug() << source << ", " << destination;

    QFileInfoList file = orig.entryInfoList();

    if(!dest.exists()){
        dest.mkdir(dest.path());
    }


    if(orig.exists() && dest.exists()){
         QTime timer;
         timer.start();

        for(int i = 0; i < file.size(); i++){
            qDebug() << file.at(i).fileName();

            if(!file.at(i).fileName().contains(".")){
                copyFromOrigin(source+file.at(i).fileName() + "/",destination+file.at(i).fileName()+"/");
            }else{
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
                newFile = destination;

            }

            emit allDone();
            emit timeElapsed(timer.elapsed());
            }

    }
}

void fileCopier::SetDestinations(QString original, QString target)
{
    ogDest = original;
    newDest = target;
}




