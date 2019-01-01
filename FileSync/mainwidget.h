#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include "Tools/fileCopier.h"
#include <QFileSystemWatcher>
#include <QTimer>
#include <QSystemTrayIcon>

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
    void showModified(QString mod);
    void startAutoSync();
public slots:

    void onShowHide(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::mainWidget *ui;
    fileCopier read;
    QFileSystemWatcher watcher;
    QTimer globalTimer;
    QSystemTrayIcon m_tray_icon ;

    void initWatcher();
    void copy();
    void createTrayIcon();


};



#endif // MAINWIDGET_H
