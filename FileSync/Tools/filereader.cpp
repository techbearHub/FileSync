#include "filereader.h"
#include <QWidget>
#include <QDir>
#include <QFileInfoList>
#include <QFile>

#include <QDebug>

#define ORIGIN "C:/Documents/tests/FileSync/CP/FROM"
#define DESTINATION "C:/Documents/tests/FileSync/CP/TO"

Filereader::Filereader()
{

}

QString Filereader::getOrigin()
{
    QDir orig(ORIGIN);

    QFileInfoList file = orig.entryInfoList();
    if(orig.exists()){
        for(int i = 0; i < file.size(); i++){
            qDebug() << "it works- " << file.at(i).filePath() + "//"+file.at(i).fileName();
        }

    }

    return ORIGIN;
}

QString Filereader::getDestination()
{
    QDir dest(DESTINATION);
    if(dest.exists()){
        qDebug() << "it works- " << dest.path();
    }

    return DESTINATION;
}

void Filereader::copyFromOrigin()
{
    QDir orig(ORIGIN);
    QDir dest(DESTINATION);
    QFile fileOper;

    QFileInfoList file = orig.entryInfoList();
    if(orig.exists()){
        for(int i = 0; i < file.size(); i++){
            QFile::copy(orig.path()+ "/" + file.at(i).fileName(), dest.path() + "/" + file.at(i).fileName());
        }

    }
}




