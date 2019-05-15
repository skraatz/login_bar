#include "clockwidget.h"
#include <QString>
#include <QTimer>
#include <QTime>

ClockWidget::ClockWidget(QWidget *parent) : QLCDNumber(parent)
{
    setSegmentStyle(Filled);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ClockWidget::showTime);
    timer->start(1000);

    showTime();
}

void ClockWidget::showTime() {
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    display(text);
}
