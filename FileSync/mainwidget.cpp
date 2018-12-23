#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "Tools/fileCopier.h"
#include "Tools/logger.h"


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


