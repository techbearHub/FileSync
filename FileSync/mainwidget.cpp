#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "Tools/fileCopier.h"
#include "Tools/logger.h"
#include <QAction>


#include <QDebug>

#define ORIGIN "C:/Documents/tests/FileSync/CP/FROM/"
#define DESTINATION "C:/Documents/tests/FileSync/CP/TO/"

mainWidget::mainWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    connect(&read, SIGNAL(currentCopy(QString, bool)), this, SLOT(onCurrentCopy(QString, bool)));
    connect(&read, SIGNAL(allDone()), this, SLOT(onAllDone()));
    connect(&read, SIGNAL(timeElapsed(int)), this, SLOT(onTimeElapsed(int)));
    ui->editSource->setText(ORIGIN);
    ui->editDestination->setText(DESTINATION);
    initWatcher();
    createTrayIcon();


    globalTimer.start(3600000); //1 hour
    connect(&globalTimer,SIGNAL(timeout()),this,SLOT(startAutoSync()));


}

mainWidget::~mainWidget()
{
    delete ui;
}


void mainWidget::on_btnSync_clicked()
{
    Logger log;
    log.WriteLog("Sync started");
     ui->lblMessage->setText("Checking for changes...");
    copy();
}

void mainWidget::startAutoSync()
{
    qDebug() << "timer fires!";
    Logger log;
    log.WriteLog("Auto sync started");
    copy();
}

void mainWidget::onCurrentCopy(QString fileBeingCopied, bool done)
{
    if(done){
       ui->lblMessage->setText(fileBeingCopied+" copied");
       Logger log;
       log.WriteLog(fileBeingCopied+" copied");
    }else{
        ui->lblMessage->setText("Copying... " + fileBeingCopied);
    }

}

void mainWidget::onAllDone()
{
    ui->lblMessage->setText("Files sync'ed");
    Logger log;
    log.WriteLog("Files sync'ed");
}

void mainWidget::onTimeElapsed(int time)
{
    ui->lblMessage->setText(ui->lblMessage->text() + ", time elapsed- " + QString::number(time/1000) + "s");
}


void mainWidget::showModified(QString mod)
{
    Logger log;
    log.WriteLog("Changes to root- start sync");
    copy();
    //no subfolders yet :(
}

void mainWidget::initWatcher()
{
    watcher.addPath(ui->editSource->text());
    QObject::connect(&watcher, SIGNAL(directoryChanged(QString)), this, SLOT(showModified(QString)));
}

void mainWidget::copy()
{
    read.SetDestinations(ui->editSource->text(),ui->editDestination->text());
    read.start();
}

void mainWidget::createTrayIcon()
{
    //TODO icon being created, fix this :(
    m_tray_icon.setIcon(QIcon("Images/images.qrc/icon.png"));

//    connect(&m_tray_icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onShowHide(QSystemTrayIcon::ActivationReason)) );

//    QAction *quit_action = new QAction( "Exit", &m_tray_icon );
//    connect( quit_action, SIGNAL(triggered()), this, SLOT(on_exit()) );

//    QAction *hide_action = new QAction( "Show/Hide", &m_tray_icon );
//    connect( hide_action, SIGNAL(triggered()), this, SLOT(onShowHide(QSystemTrayIcon::ActivationReason)) );

    QMenu *tray_icon_menu = new QMenu;
//    tray_icon_menu->addAction( hide_action );
//    tray_icon_menu->addAction( quit_action );

    m_tray_icon.setContextMenu( tray_icon_menu );

    m_tray_icon.show();

}

void mainWidget::onShowHide( QSystemTrayIcon::ActivationReason reason )
{
    if( reason )
    {
        if( reason != QSystemTrayIcon::DoubleClick )
        return;
    }

    if( isVisible() )
    {
        hide();
    }
    else
    {
        show();
        raise();
        setFocus();
    }
}


