#include "mainwindow.h"
#include <QCoreApplication>
#include <QGuiApplication>
#include <QScreen>
#include <QRect>
#include <iostream>
#include <QIcon>
#include <QAction>
#include <QToolBar>
#include <QtGui>
#include "clockwidget.h"
#include <unistd.h>
#include <sys/reboot.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    
    // retrieve screensize
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    height = screenGeometry.height();
    width = screenGeometry.width();

    std::cout << QIcon::themeName().toUtf8().constData() << std::endl;
    QIcon::setThemeName("Paper");
    //QIcon::setFallbackThemeName("Adwaita");


    // reboot button
    const QIcon rebootIcon = QIcon::fromTheme("system-reboot");
    QAction *rebootAct = new QAction(rebootIcon, tr("&Reboot..."), this);
    rebootAct->setStatusTip(tr("reboot this computer"));
    connect(rebootAct, &QAction::triggered, this, &MainWindow::reboot);

    // shutdown button
    const QIcon shutdownIcon = QIcon::fromTheme("system-shutdown");
    QAction *shutdownAct = new QAction(shutdownIcon, tr("&Shutdown..."), this);
    shutdownAct->setStatusTip(tr("shutdown this computer"));
    connect(shutdownAct, &QAction::triggered, this, &MainWindow::shutdown);


    // toolbar
    toolBar = addToolBar(tr("System"));
    toolBar->setFloatable(false);
    toolBar->setMovable(false);
    
    // spacer
    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    
    toolBar->addWidget(new ClockWidget());
    toolBar->addWidget(spacer);
    toolBar->addSeparator();

    // add buttons
    toolBar->addAction(rebootAct);
    toolBar->addAction(shutdownAct);

}

void MainWindow::scale() {
    int padding = 10;
    int tbsize = toolBar->iconSize().height() + padding;
    this->resize(width, tbsize);
}

void MainWindow::shutdown() {
    // TODO erro handling 
    // TODO confirmation dialog? 
    int result = ::reboot(RB_HALT | RB_POWERDOWN);
}

void MainWindow::reboot() {
    // TODO erro handling 
    // TODO confirmation dialog? 
    int result = ::reboot(RB_AUTOBOOT);
}

