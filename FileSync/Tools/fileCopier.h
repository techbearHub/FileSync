#ifndef fileCopier_H
#define fileCopier_H

#include <QWidget>
#include <QDir>

namespace Ui {
class fileCopier;
}

class fileCopier:public QWidget
{
    Q_OBJECT

public:
    fileCopier();
    QString getOrigin();
    QString getDestination();
    void copyFromOrigin();

private:


};

#endif // fileCopier_H
