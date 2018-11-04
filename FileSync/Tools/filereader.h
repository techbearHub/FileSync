#ifndef FILEREADER_H
#define FILEREADER_H

#include <QWidget>
#include <QDir>

namespace Ui {
class Filereader;
}

class Filereader:public QWidget
{
    Q_OBJECT

public:
    Filereader();
    QString getOrigin();
    QString getDestination();
    void copyFromOrigin();

private:


};

#endif // FILEREADER_H
