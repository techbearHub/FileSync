#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "Tools/filereader.h"

#include <QDebug>

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
    Filereader read;
    qDebug() << read.getOrigin() + " " + read.getDestination();
}
