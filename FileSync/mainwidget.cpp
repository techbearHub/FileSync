#include "mainwidget.h"
#include "ui_mainwidget.h"

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
