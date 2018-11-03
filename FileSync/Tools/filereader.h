#ifndef FILEREADER_H
#define FILEREADER_H

#include <QWidget>

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

private:

};

#endif // FILEREADER_H
