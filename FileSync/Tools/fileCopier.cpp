#include "fileCopier.h"
#include <QWidget>
#include <QDir>
#include <QFileInfoList>
#include <QFile>

#include <QDebug>

#define ORIGIN "C:/Documents/tests/FileSync/CP/FROM/"
#define DESTINATION "C:/Documents/tests/FileSync/CP/TO/"

fileCopier::fileCopier()
{

}

QString fileCopier::getOrigin()
{
    return ORIGIN;
}

QString fileCopier::getDestination()
{
    return DESTINATION;
}

void fileCopier::copyFromOrigin()
{
    QDir orig(ORIGIN);
    QDir dest(DESTINATION);
    QFile fileOper;

    QString ogFile = ORIGIN;
    QString newFile = DESTINATION;

    QFileInfoList file = orig.entryInfoList();
    if(orig.exists() && dest.exists()){

        for(int i = 0; i < file.size(); i++){
            //TODO check if file.size() gives what we need
            ogFile+=file.at(i).fileName();
            newFile+=file.at(i).fileName();
            qDebug() << ogFile;
            qDebug() << newFile;

            if(QFile(newFile).exists()){
                //TODO check hash and copy then

            }else{
                QFile::copy(ogFile, newFile);
            }
            ogFile = ORIGIN;
            newFile = DESTINATION;

        }

    }
}




