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
    void copyFromOrigin(QString ogDest, QString ogFile);

private:


};

#endif // fileCopier_H
