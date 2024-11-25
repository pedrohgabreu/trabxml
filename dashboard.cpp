#include "dashboard.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QTableWidget>

Dashboard::Dashboard(QWidget *parent) :
    QWidget(parent) {
    // Layout principal
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Criação do TabWidget
    QTabWidget *tabWidget = new QTabWidget(this);

    // View Geral
    QWidget *geralWidget = new QWidget();
    QVBoxLayout *geralLayout = new QVBoxLayout(geralWidget);
    geralLayout->addWidget(new QLabel("Número total de NFs: X"));
    geralLayout->addWidget(new QLabel("Número total de produtos: Y"));
    geralLayout->addWidget(new QLabel("Valor total das NFs: Z"));
    geralLayout->addWidget(new QLabel("Valor total de impostos: W"));
    tabWidget->addTab(geralWidget, "Geral");

    // View por NF
    QWidget *nfWidget = new QWidget();
    QVBoxLayout *nfLayout = new QVBoxLayout(nfWidget);
    nfLayout->addWidget(new QLabel("Tabela de Notas Fiscais aqui"));  // Placeholder
    tabWidget->addTab(nfWidget, "Notas Fiscais");

    // View de Impostos
    QWidget *impostosWidget = new QWidget();
    QVBoxLayout *impostosLayout = new QVBoxLayout(impostosWidget);
    impostosLayout->addWidget(new QLabel("Tabela de Impostos aqui"));  // Placeholder
    tabWidget->addTab(impostosWidget, "Impostos");

    // View de Fornecedores
    QWidget *fornecedoresWidget = new QWidget();
    QVBoxLayout *fornecedoresLayout = new QVBoxLayout(fornecedoresWidget);
    fornecedoresLayout->addWidget(new QLabel("Tabela de Fornecedores aqui"));  // Placeholder
    tabWidget->addTab(fornecedoresWidget, "Fornecedores");

    // View de Transportadoras
    QWidget *transportadorasWidget = new QWidget();
    QVBoxLayout *transportadorasLayout = new QVBoxLayout(transportadorasWidget);
    transportadorasLayout->addWidget(new QLabel("Tabela de Transportadoras aqui"));  // Placeholder
    tabWidget->addTab(transportadorasWidget, "Transportadoras");

    // Adiciona o TabWidget ao layout principal
    mainLayout->addWidget(tabWidget);

    // Define o layout principal para o widget
    setLayout(mainLayout);
}

Dashboard::~Dashboard() {
    // Nada para deletar explicitamente, o Qt gerencia a destruição dos widgets filhos automaticamente
}
