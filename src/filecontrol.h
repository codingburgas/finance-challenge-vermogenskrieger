#pragma once

#include <QFile>         // Provides an interface for file handling
#include <QTextStream>   // Provides an interface for reading and writing text data
#include <QDebug>        // Provides access to debugging facilities

// filecontrol class handles file operations such as reading, writing, and erasing files
class filecontrol {
public:
    // Reads the contents of a file specified by filePath and returns it as a QString
    QString readFile(const QString &filePath);

    // Writes the specified text to a file at the given filePath
    void writeFile(const QString &filePath, const QString &text);

    // Erases the contents of the file at the specified filePath by truncating it
    void eraseFile(const QString &filePath);
};
