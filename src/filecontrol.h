#ifndef FILECONTROL_H
#define FILECONTROL_H

#include <QFile>
#include <QTextStream>
#include <QDebug>

class filecontrol
{
public:
    QString readFile(const QString &filePath);
    void writeFile(const QString &filePath, const QString &text);
    void eraseFile(const QString &filePath);
};

#endif // FILECONTROL_H
