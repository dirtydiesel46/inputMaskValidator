#ifndef VALIDATORDEMO_H
#define VALIDATORDEMO_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QLocale>

#include "signalindicator.h"

class ValidatorDemo : public QWidget
{
    Q_OBJECT
public:
    explicit ValidatorDemo(QWidget *parent = nullptr);

private:
    QLineEdit *lineEdit, *txtMaxVal;
    QRadioButton *radIntValid;
    QRadioButton *radDoubleValidUs;
    QRadioButton *radDoubleValidDe;
    QRadioButton *radRegExValid;
    QRadioButton *radNoValid;
    QLabel *lblMaxVal;
    SignalIndicator *sigindEditingFinished, *sigindReturnPressed;
    QIntValidator *validInt;
    QDoubleValidator *validDoubleUs;
    QDoubleValidator *validDoubleDe;
    QRegularExpressionValidator *validRegEx;

private:
    void setupWidgets();
    void setupValidators();
    void setupLayout();

private slots:
    void onIntValidSel(bool checked);
    void onDoubleUsValidSel(bool checked);
    void onDoubleDeValidSel(bool checked);
    void onRegExValidSel(bool checked);
    void onNoValidSel(bool checked);

    void onMaxLenChange();
};

#endif // VALIDATORDEMO_H
