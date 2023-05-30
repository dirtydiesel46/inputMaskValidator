#ifndef SIGNALINDICATOR_H
#define SIGNALINDICATOR_H

#include <QCheckBox>
#include <QFont>
#include <QTimer>

class SignalIndicator : public QCheckBox
{
    Q_OBJECT
public:
    SignalIndicator(QWidget *parent = nullptr);
    void setPattern(QString pattern);

private:
    QTimer *timer;

protected:
    QString pattern;

public slots:
    virtual void signalTriggered();
    void resetLabel();

};

#endif // SIGNALINDICATOR_H
