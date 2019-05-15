#pragma once

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void scale();

private slots:
    void shutdown();
    void reboot();
private:
    QPushButton *m_button;
    QToolBar *toolBar;
    int height;
    int width;
};
