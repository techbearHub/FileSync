#ifndef LOGGER_H
#define LOGGER_H

#include <QWidget>
#include <QFile>

class Logger : public QWidget
{
public:
    Logger();
    void WriteLog(QString message);


private:
    QFile file;
    void OpenFile();
    void CloseFile();
};

#endif // LOGGER_H
