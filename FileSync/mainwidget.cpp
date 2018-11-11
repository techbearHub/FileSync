#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "Tools/fileCopier.h"


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
}

mainWidget::~mainWidget()
{
    delete ui;
}


void mainWidget::on_btnSync_clicked()
{
    read.SetDestinations(ui->editSource->text(),ui->editDestination->text());
    read.start();
}

void mainWidget::onCurrentCopy(QString fileBeingCopied, bool done)
{
    if(done){
       ui->lblMessage->setText(fileBeingCopied+" copied");
    }else{
        ui->lblMessage->setText("Copying... " + fileBeingCopied);
    }

}

void mainWidget::onAllDone()
{
    ui->lblMessage->setText("Files sync'ed");
}

void mainWidget::onTimeElapsed(int time)
{
    ui->lblMessage->setText(ui->lblMessage->text() + ", time elapsed- " + QString::number(time/1000) + "s");
}
