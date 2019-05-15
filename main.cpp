#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.scale();
    mainWindow.setParent(0); // Create TopLevel-Widget
    mainWindow.setAttribute(Qt::WA_NoSystemBackground, true);
    mainWindow.setAttribute(Qt::WA_TranslucentBackground, true);

    mainWindow.show();
    return app.exec();
}

