#include "XmlProcessor.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

void XmlProcessor::queryXML(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Garantir modo de texto
        qDebug() << "Erro ao abrir o arquivo XML para consulta:" << filePath;
        return;
    }

    QXmlStreamReader reader(&file);
    int totalNotas = 0;
    double totalValor = 0.0;

    while (!reader.atEnd() && !reader.hasError()) {
        reader.readNext();
        if (reader.isStartElement()) {
            // Comparação corrigida
            if (reader.name() == QStringLiteral("notaFiscal")) {
                totalNotas++;
            } else if (reader.name() == QStringLiteral("valorTotal")) {
                bool ok = false;
                double valor = reader.readElementText().toDouble(&ok);
                if (ok) {
                    totalValor += valor;
                } else {
                    qDebug() << "Erro ao converter valorTotal em número.";
                }
            }
        }
    }

    if (reader.hasError()) {
        qDebug() << "Erro ao processar o XML:" << reader.errorString();
    } else {
        qDebug() << "Consulta concluída com sucesso!";
        qDebug() << "Total de Notas:" << totalNotas;
        qDebug() << "Valor Total:" << totalValor;
    }
}


void XmlProcessor::transformXmlToJson(const QString &xmlFilePath, const QString &jsonFilePath) {
    QFile xmlFile(xmlFilePath);
    if (!xmlFile.open(QIODevice::ReadOnly | QIODevice::Text)) { // Garantir modo de texto
        qDebug() << "Erro ao abrir o arquivo XML para transformação:" << xmlFilePath;
        return;
    }

    QXmlStreamReader reader(&xmlFile);
    QJsonArray notasArray;

    while (!reader.atEnd() && !reader.hasError()) {
        reader.readNext();
        if (reader.isStartElement() && reader.name() == QStringLiteral("notaFiscal")) {

            QJsonObject nota;

            while (!(reader.isEndElement() && reader.name() == QStringLiteral("notaFiscal"))) {
                reader.readNext();
                if (reader.isStartElement()) {
                    QString key = reader.name().toString();
                    QString value = reader.readElementText();

                    if (!reader.hasError()) {
                        nota[key] = value; // Adiciona ao JSON apenas se não houver erros
                    } else {
                        qDebug() << "Erro ao ler elemento:" << reader.errorString();
                        return;
                    }
                }
            }

            notasArray.append(nota);
        }
    }

    if (reader.hasError()) {
        qDebug() << "Erro ao transformar o XML para JSON:" << reader.errorString();
        return;
    }

    QJsonDocument jsonDoc(notasArray);
    QFile jsonFile(jsonFilePath);

    if (!jsonFile.open(QIODevice::WriteOnly | QIODevice::Text)) { // Garantir modo de texto
        qDebug() << "Erro ao criar o arquivo JSON:" << jsonFilePath;
        return;
    }

    jsonFile.write(jsonDoc.toJson(QJsonDocument::Indented)); // Formatação legível
    qDebug() << "Transformação para JSON concluída com sucesso!";
}
