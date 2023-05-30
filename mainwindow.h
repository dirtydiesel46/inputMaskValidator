#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSpacerItem>

#include <QDebug>

#include "inputmaskdemo.h"
#include "validatordemo.h"


class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    InputMaskDemo *inputMaskWidget;
    ValidatorDemo *validatorWidget;
    QRadioButton *radioInputMask, *radioValidator;

private slots:
    void onInputMaskSel(bool checked);
    void onValidatorSel(bool checked);

};

#endif // MAINWINDOW_H
