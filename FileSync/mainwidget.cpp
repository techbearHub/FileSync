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
}

mainWidget::~mainWidget()
{
    delete ui;
}


void mainWidget::on_btnSync_clicked()
{
    fileCopier read;
//    qDebug() << read.getOrigin() + " " + read.getDestination();
    read.copyFromOrigin(ORIGIN, DESTINATION);
}
