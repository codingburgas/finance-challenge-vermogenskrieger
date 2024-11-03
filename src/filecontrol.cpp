#include "filecontrol.h"

QString filecontrol::readFile(const QString &filePath) {
    QFile file(filePath);
    QString fileContent;  // String to hold the content

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        return QString();  // Return an empty QString on error
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        fileContent.append(line);  // Append each line to fileContent
    }

    file.close();
    return fileContent;  // Return the accumulated content
}


void filecontrol::writeFile(const QString &filePath, const QString &text) {
    QFile file(filePath);

    qDebug() << "Attempting to write to file:" << filePath;
    qDebug() << "Content to write:" << text;  // Debug output

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for writing:" << file.errorString();
        return;
    }

    QTextStream out(&file);
    out << text;  // Write the text to the file

    file.close();
    qDebug() << "File written successfully.";
}

void filecontrol::eraseFile(const QString &filePath) {
    QFile file(filePath);

    // Open the file in WriteOnly mode to truncate it
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "Cannot open file to erase:" << file.errorString();
        return;
    }

    // File is now empty, close it
    file.close();
}


