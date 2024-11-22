#ifndef XMLPROCESSOR_H
#define XMLPROCESSOR_H

#include <QString>

class XmlProcessor {
public:
    static void queryXML(const QString &filePath);
    static void transformXmlToJson(const QString &xmlFilePath, const QString &jsonFilePath);
};

#endif // XMLPROCESSOR_H
