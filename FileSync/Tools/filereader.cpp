#include "filereader.h"
#include <QWidget>

#define ORIGIN "C:\\Documents\\tests\\FileSync\\CP\\FROM"
#define DESTINATION "C:\\Documents\\tests\\FileSync\\CP\\TO"

Filereader::Filereader()
{

}

QString Filereader::getOrigin()
{
    return ORIGIN;
}

QString Filereader::getDestination()
{
    return DESTINATION;
}


