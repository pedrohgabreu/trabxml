#include "mainwindow.h"
#include <QApplication>
#include "dashboard.h"  // Certifique-se de incluir o header do Dashboard

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Inicializa a janela principal
    MainWindow w;
    w.show();

    // Inicializa o Dashboard, se necessário
    Dashboard dashboard; // Se o Dashboard for uma janela separada
    dashboard.show();    // Mostra o Dashboard

    return a.exec();
}
