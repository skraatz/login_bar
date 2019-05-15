#pragma once
//#include <QWidget>
#include <QLCDNumber>

class ClockWidget : public QLCDNumber
{
public:
    ClockWidget(QWidget *parent = 0);

private slots:
    void showTime();
};
