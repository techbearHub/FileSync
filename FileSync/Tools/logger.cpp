#include "logger.h"
#include <QTextStream>
#include <QDateTime>

Logger::Logger()
{

}

void Logger::WriteLog(QString message)
{
    OpenFile();
    QTextStream out(&file);
    QDateTime date = QDateTime::currentDateTime();
    QString currentDate = date.toString();
    currentDate.append(": ");

    out << currentDate << message << "\n";
    CloseFile();
}

void Logger::OpenFile()
{
    file.setFileName(("log.txt"));
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
}

void Logger::CloseFile()
{
    file.close();
}
