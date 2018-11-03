#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>

namespace Ui {
class mainWidget;
}

class mainWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private:
    Ui::mainWidget *ui;
};

#endif // MAINWIDGET_H
