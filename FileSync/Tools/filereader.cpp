#include "filereader.h"
#include <QCryptographicHash>
//Checks if two files are the same
//gets hash of files and compares it

fileReader::fileReader(QWidget *parent) : QWidget(parent)
{

}

bool fileReader::areFilesEqual(QString origin, QString newCopy)
{

    QByteArray origSig = getFileHash(origin);
    QByteArray newSig = getFileHash(newCopy);
    if(origSig==newSig){
        return true;
    }else{
        return false;
    }


}

QByteArray fileReader::getFileHash(QString filePath)
{
    QFile file(filePath);
    QCryptographicHash hash( QCryptographicHash::Sha1 );

    if (file.open( QIODevice::ReadOnly)){
        hash.addData( file.readAll() );
    } else{
        //TODO do we need to handle?
    }

    // Retrieve the SHA1 signature of the file
    QByteArray sig = hash.result();
    return sig;
}
