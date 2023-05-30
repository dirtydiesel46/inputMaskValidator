#include "validatordemo.h"

ValidatorDemo::ValidatorDemo(QWidget *parent)
    : QWidget{parent}
{
    setupWidgets();
    setupValidators();

    connect(radIntValid, &QRadioButton::toggled, this, &ValidatorDemo::onIntValidSel);
    connect(radDoubleValidUs, &QRadioButton::toggled, this, &ValidatorDemo::onDoubleUsValidSel);
    connect(radDoubleValidDe, &QRadioButton::toggled, this, &ValidatorDemo::onDoubleDeValidSel);
    connect(radRegExValid, &QRadioButton::toggled, this, &ValidatorDemo::onRegExValidSel);
    connect(radNoValid, &QRadioButton::toggled, this, &ValidatorDemo::onNoValidSel);

    connect(txtMaxVal, &QLineEdit::editingFinished, this, &ValidatorDemo::onMaxLenChange);


    connect(lineEdit, &QLineEdit::editingFinished, sigindEditingFinished, &SignalIndicator::signalTriggered);
    connect(lineEdit, &QLineEdit::returnPressed, sigindReturnPressed, &SignalIndicator::signalTriggered);

    radIntValid->toggle();

    setupLayout();
}

void ValidatorDemo::setupWidgets()
{
    lineEdit = new QLineEdit();

    radIntValid = new QRadioButton("QIntValidator 100-200");
    radDoubleValidUs = new QRadioButton("QDoubleValidator en_US 100.0-200.0, 1dez");
    radDoubleValidDe = new QRadioButton("QDoubleValidator de_DE 100,0-200,0, 1dez");
    // QLabel is picky about text input. \173 = octal code for left bracket {
    radRegExValid = new QRadioButton("QRegExpValidator \\w\1733, 16\175");
    radNoValid = new QRadioButton("No Validator");

    // the max length line edit reads the default value on startup
    lblMaxVal = new QLabel("Maximum Length: ");
    txtMaxVal = new QLineEdit();

    sigindEditingFinished = new SignalIndicator();
    sigindReturnPressed = new SignalIndicator();

    sigindEditingFinished->setText("editingFinished()");
    sigindReturnPressed->setText("returnPressed()");

    sigindEditingFinished->setChecked(true);
    sigindReturnPressed->setChecked(true);

}

void ValidatorDemo::setupValidators()
{
    validInt = new QIntValidator(100, 200, this);
    validDoubleUs = new QDoubleValidator(100.0, 200.0, 1);
    validDoubleUs->setLocale(QLocale("en_US"));
    validDoubleDe = new QDoubleValidator(100.0, 200.0, 1);
    validDoubleUs->setLocale(QLocale("de_DE"));
    validRegEx = new QRegularExpressionValidator(QRegularExpression("\\w{3,16}"), this);
}

void ValidatorDemo::setupLayout()
{
    QGroupBox *groupValidators = new QGroupBox("Validators");
    QVBoxLayout *layoutValidators = new QVBoxLayout(groupValidators);
    layoutValidators->addWidget(radIntValid);
    layoutValidators->addWidget(radDoubleValidUs);
    layoutValidators->addWidget(radDoubleValidDe);
    layoutValidators->addWidget(radRegExValid);
    layoutValidators->addWidget(radNoValid);

    QGroupBox *groupMaxLen = new QGroupBox("Maximum Length");
    QHBoxLayout *layoutMaxLen = new QHBoxLayout(groupMaxLen);
    layoutMaxLen->addWidget(lblMaxVal);
    layoutMaxLen->addWidget(txtMaxVal);

    QGroupBox *groupIndicators = new QGroupBox("Signal Monitor");
    QVBoxLayout *layoutIndicators = new QVBoxLayout(groupIndicators);
    layoutIndicators->addWidget(sigindEditingFinished);
    layoutIndicators->addWidget(sigindReturnPressed);


    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(lineEdit);
    mainLayout->addWidget(groupValidators);
    mainLayout->addWidget(groupMaxLen);
    mainLayout->addWidget(groupIndicators);
}

void ValidatorDemo::onIntValidSel(bool checked)
{
    if(checked)
    {
        lineEdit->setValidator(validInt);
        txtMaxVal->setText(QString().setNum(lineEdit->maxLength()));
    }
}

void ValidatorDemo::onDoubleUsValidSel(bool checked)
{
    if(checked)
    {
        lineEdit->setValidator(validDoubleUs);
        txtMaxVal->setText(QString().setNum(lineEdit->maxLength()));
    }
}

void ValidatorDemo::onDoubleDeValidSel(bool checked)
{
    if(checked)
    {
        lineEdit->setValidator(validDoubleDe);
        txtMaxVal->setText(QString().setNum(lineEdit->maxLength()));
    }
}

void ValidatorDemo::onRegExValidSel(bool checked)
{
    if(checked)
    {
        lineEdit->setValidator(validRegEx);
        txtMaxVal->setText(QString().setNum(lineEdit->maxLength()));
    }
}

void ValidatorDemo::onNoValidSel(bool checked)
{
    if(checked)
    {
        lineEdit->setValidator(0);
        txtMaxVal->setText(QString().setNum(lineEdit->maxLength()));
    }
}

void ValidatorDemo::onMaxLenChange()
{
    QString maxValStr = txtMaxVal->text();
    bool ok;
    int maxVal = maxValStr.toInt(&ok);
    if (ok)
        lineEdit->setMaxLength(maxVal);
}
