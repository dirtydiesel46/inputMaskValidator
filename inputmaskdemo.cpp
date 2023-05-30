#include "inputmaskdemo.h"

InputMaskDemo::InputMaskDemo(QWidget *parent)
    : QWidget{parent}
{
    setupWidgets();

    connect(radioDate, &QRadioButton::toggled, this, &InputMaskDemo::onDateSel);
    connect(radioMac, &QRadioButton::toggled, this, &InputMaskDemo::onMacSel);
    connect(radioZip, &QRadioButton::toggled, this, &InputMaskDemo::onZipSel);
    connect(radioFixed, &QRadioButton::toggled, this, &InputMaskDemo::onFixedSel);
    connect(radioNoMask, &QRadioButton::toggled, this, &InputMaskDemo::onNoMaskSel);

    connect(txtMaxVal, &QLineEdit::editingFinished, this, &InputMaskDemo::onMaxLenChange);


    connect(lineEdit, &QLineEdit::editingFinished, sigindEditingFinished, &SignalIndicator::signalTriggered);
    connect(lineEdit, &QLineEdit::returnPressed, sigindReturnPressed, &SignalIndicator::signalTriggered);

    radioDate->toggle();

    setupLayout();
}

void InputMaskDemo::setupWidgets()
{
    lineEdit = new QLineEdit();

    radioDate = new QRadioButton("Date: 9999-99-99");
    radioMac = new QRadioButton("MAC: HH:HH:HH:HH:HH:HH");
    radioZip = new QRadioButton("Postal Code: DDDDD");
    radioFixed = new QRadioButton("Fixed: moon is shining");
    radioNoMask = new QRadioButton("No Mask");

    // the max length line edit reads the default value on startup
    lblMaxVal = new QLabel("Maximum Length: ");
    txtMaxVal = new QLineEdit();
    txtMaxVal->setText(
        QString().setNum(lineEdit->maxLength()));

    sigindEditingFinished = new SignalIndicator();
    sigindReturnPressed = new SignalIndicator();

    sigindEditingFinished->setText("editingFinished()");
    sigindReturnPressed->setText("returnPressed()");

    sigindEditingFinished->setChecked(true);
    sigindReturnPressed->setChecked(true);
}

void InputMaskDemo::setupLayout()
{
    QGroupBox *groupMask = new QGroupBox("Input Masks");
    QVBoxLayout *groupMaskLayout = new QVBoxLayout(groupMask);

    groupMaskLayout->addWidget(radioDate);
    groupMaskLayout->addWidget(radioMac);
    groupMaskLayout->addWidget(radioZip);
    groupMaskLayout->addWidget(radioFixed);
    groupMaskLayout->addWidget(radioNoMask);


    QGroupBox *groupMax = new QGroupBox("Max Length");
    QHBoxLayout *groupMaxLayout = new QHBoxLayout(groupMax);

    groupMaxLayout->addWidget(lblMaxVal);
    groupMaxLayout->addWidget(txtMaxVal);

    QGroupBox *groupIndicator = new QGroupBox("Signal Monitor");
    QVBoxLayout *groupIndicatorLayout = new QVBoxLayout(groupIndicator);
    groupIndicatorLayout->addWidget(sigindEditingFinished);
    groupIndicatorLayout->addWidget(sigindReturnPressed);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(lineEdit);
    layout->addWidget(groupMask);
    layout->addWidget(groupMax);
    layout->addWidget(groupIndicator);

}

void InputMaskDemo::onDateSel(bool checked)
{
    if(checked)
        lineEdit->setInputMask("9999-99-99");
    txtMaxVal->setText(
        QString().setNum(lineEdit->maxLength()));
}

void InputMaskDemo::onMacSel(bool checked)
{
    if(checked)
        lineEdit->setInputMask("HH:HH:HH:HH:HH:HH");
    txtMaxVal->setText(
        QString().setNum(lineEdit->maxLength()));
}

void InputMaskDemo::onZipSel(bool checked)
{
    if(checked)
        lineEdit->setInputMask("DDDDD");
    txtMaxVal->setText(
        QString().setNum(lineEdit->maxLength()));
}

void InputMaskDemo::onFixedSel(bool checked)
{
    if(checked)
        lineEdit->setInputMask("moo\\n is s\\hi\\ni\\ng");
    txtMaxVal->setText(
        QString().setNum(lineEdit->maxLength()));
}

void InputMaskDemo::onNoMaskSel(bool checked)
{
    if(checked)
        lineEdit->setInputMask("");
    txtMaxVal->setText(
        QString().setNum(lineEdit->maxLength()));
}

void InputMaskDemo::onMaxLenChange()
{
    bool ok;
    QString val = txtMaxVal->text();
    int maxVal = val.toInt(&ok);
    if (ok)
        lineEdit->setMaxLength(maxVal);
}
