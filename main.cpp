#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.scale();
    mainWindow.setParent(0); // Create TopLevel-Widget

	//mainWindow.setStyleSheet("background:transparent;");
    //mainWindow.setAttribute(Qt::WA_TranslucentBackground);

    mainWindow.show();
    return app.exec();
}

