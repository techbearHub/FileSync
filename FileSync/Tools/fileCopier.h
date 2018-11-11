#ifndef fileCopier_H
#define fileCopier_H

#include <QWidget>
#include <QDir>
#include <QThread>

namespace Ui {
class fileCopier;
}

class fileCopier : public QThread
{
    Q_OBJECT

public:
    void run() override;
    fileCopier();
    void SetDestinations(QString original, QString target);

signals:
    void currentCopy(QString current, bool done);
    void timeElapsed(int time);
    void allDone();

private:
    void copyFromOrigin();

    QString ogDest;
    QString newDest;


};

#endif // fileCopier_H
