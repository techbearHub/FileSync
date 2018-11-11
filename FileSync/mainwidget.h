#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include "Tools/fileCopier.h"

namespace Ui {
class mainWidget;
}

class mainWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private slots:

    void on_btnSync_clicked();
    void onCurrentCopy(QString fileBeingCopied, bool done);
    void onAllDone();
    void onTimeElapsed(int time);

private:
    Ui::mainWidget *ui;
    fileCopier read;
};



#endif // MAINWIDGET_H
