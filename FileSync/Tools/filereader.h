#ifndef FILEREADER_H
#define FILEREADER_H
#include <QWidget>
#include <QFile>


class fileReader : public QWidget
{
    Q_OBJECT
public:
    explicit fileReader(QWidget *parent = nullptr);

signals:

public slots:


public:
    static bool areFilesEqual(QString origin, QString newCopy);

private:
    static QByteArray getFileHash(QString filePath);

};

#endif // FILEREADER_H
