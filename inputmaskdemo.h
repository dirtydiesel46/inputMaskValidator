#ifndef INPUTMASKDEMO_H
#define INPUTMASKDEMO_H

#include <QWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>

#include "signalindicator.h"

class InputMaskDemo : public QWidget
{
    Q_OBJECT
public:
    explicit InputMaskDemo(QWidget *parent = nullptr);

private:
    QLineEdit *lineEdit, *txtMaxVal;
    QRadioButton *radioDate, *radioMac, *radioZip, *radioFixed, *radioNoMask;
    QLabel *lblMaxVal;
    SignalIndicator *sigindEditingFinished, *sigindReturnPressed;

private:
    void setupWidgets();
    void setupLayout();

private slots:
    void onDateSel(bool checked);
    void onMacSel(bool checked);
    void onZipSel(bool checked);
    void onFixedSel(bool checked);
    void onNoMaskSel(bool checked);
    void onMaxLenChange();
};

#endif // INPUTMASKDEMO_H
