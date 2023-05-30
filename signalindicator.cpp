#include "signalindicator.h"

SignalIndicator::SignalIndicator(QWidget *parent)
    : QCheckBox{parent}
{
    timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(1500);

    connect(timer, &QTimer::timeout, this, &SignalIndicator::resetLabel);


}

void SignalIndicator::setPattern(QString pattern)
{
    this->pattern = pattern;
    setText(pattern);
}

void SignalIndicator::signalTriggered()
{
    if (isChecked())
    {
        QFont font = this->font();
        font.setBold(true);
        setFont(font);
        setStyleSheet("color:red");
        timer->start();
    }
}

void SignalIndicator::resetLabel()
{
    QFont font = this->font();
    font.setBold(false);
    setFont(font);
    setStyleSheet("color:");
}
