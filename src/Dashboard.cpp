#include "Dashboard.h"
#include "XmlValidator.h"
#include "XmlProcessor.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>

Dashboard::Dashboard(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *validateButton = new QPushButton("Validar XML");
    connect(validateButton, &QPushButton::clicked, []() {
        bool result = XmlValidator::validateWithDTD("resources/example.xml", "resources/example.dtd");
        qDebug() << "Validação com DTD:" << (result ? "Sucesso" : "Falha");
    });

    layout->addWidget(validateButton);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}
