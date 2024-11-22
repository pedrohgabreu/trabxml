#ifndef XMLVALIDATOR_H
#define XMLVALIDATOR_H

#include <QString>

class XmlValidator {
public:
    static bool validateWithDTD(const QString &xmlFilePath, const QString &dtdFilePath);
    static bool validateWithXsd(const QString &xmlFilePath, const QString &xsdFilePath);
};

#endif // XMLVALIDATOR_H
