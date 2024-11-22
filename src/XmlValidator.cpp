#include "XmlValidator.h"
#include <libxml/parser.h>
#include <libxml/xmlschemas.h>
#include <libxml/valid.h>
#include <iostream>

bool XmlValidator::validateWithDTD(const QString &xmlFilePath, const QString &dtdFilePath) {
    xmlDocPtr doc = xmlParseFile(xmlFilePath.toStdString().c_str());
    if (!doc) {
        std::cerr << "Erro ao carregar o arquivo XML." << std::endl;
        return false;
    }

    xmlValidCtxtPtr validCtxt = xmlNewValidCtxt();
    if (!validCtxt) {
        xmlFreeDoc(doc);
        std::cerr << "Erro ao criar contexto de validação." << std::endl;
        return false;
    }

    bool isValid = false;
    if (xmlValidateDocument(validCtxt, doc)) {
        isValid = true;
        std::cout << "XML válido contra o DTD." << std::endl;
    } else {
        std::cerr << "XML inválido contra o DTD." << std::endl;
    }

    xmlFreeValidCtxt(validCtxt);
    xmlFreeDoc(doc);
    return isValid;
}

bool XmlValidator::validateWithXsd(const QString &xmlFilePath, const QString &xsdFilePath) {
    xmlDocPtr doc = xmlParseFile(xmlFilePath.toStdString().c_str());
    if (!doc) {
        std::cerr << "Erro ao carregar o arquivo XML." << std::endl;
        return false;
    }

    xmlSchemaParserCtxtPtr parserCtxt = xmlSchemaNewParserCtxt(xsdFilePath.toStdString().c_str());
    if (!parserCtxt) {
        xmlFreeDoc(doc);
        std::cerr << "Erro ao criar contexto de parser para o XSD." << std::endl;
        return false;
    }

    xmlSchemaPtr schema = xmlSchemaParse(parserCtxt);
    xmlSchemaFreeParserCtxt(parserCtxt);

    if (!schema) {
        xmlFreeDoc(doc);
        std::cerr << "Erro ao carregar o esquema XSD." << std::endl;
        return false;
    }

    xmlSchemaValidCtxtPtr validCtxt = xmlSchemaNewValidCtxt(schema);
    if (!validCtxt) {
        xmlSchemaFree(schema);
        xmlFreeDoc(doc);
        std::cerr << "Erro ao criar contexto de validação." << std::endl;
        return false;
    }

    bool isValid = false;
    if (xmlSchemaValidateDoc(validCtxt, doc) == 0) {
        isValid = true;
        std::cout << "XML válido contra o XSD." << std::endl;
    } else {
        std::cerr << "XML inválido contra o XSD." << std::endl;
    }

    xmlSchemaFreeValidCtxt(validCtxt);
    xmlSchemaFree(schema);
    xmlFreeDoc(doc);
    return isValid;
}
