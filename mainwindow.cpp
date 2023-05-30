#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("QLineEdit - Input Masks and Validators");
    setMinimumSize(400, 600);

    inputMaskWidget = new InputMaskDemo();
    validatorWidget = new ValidatorDemo();

    radioInputMask = new QRadioButton("Input Mask");
    radioValidator = new QRadioButton("Validator");

    QGroupBox *selectorGroup = new QGroupBox("Select Widget");
    selectorGroup->setStyleSheet("background:#80c342");
    QHBoxLayout *selectorLayout = new QHBoxLayout(selectorGroup);
    selectorLayout->addWidget(radioInputMask);
    selectorLayout->addWidget(radioValidator);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(selectorGroup);
    layout->addWidget(inputMaskWidget);
    layout->addWidget(validatorWidget);

//     Used to expand horizontally - added apart from the instructions
    inputMaskWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    validatorWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    Uncomment the below to ensure the space below is always static and filled - ensure to comment out above sizePolicies for both widgets then
//    layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));

    connect(radioInputMask, &QRadioButton::toggled,
            this, &MainWindow::onInputMaskSel);
    connect(radioValidator, &QRadioButton::toggled,
            this, &MainWindow::onValidatorSel);

    radioInputMask->setChecked(true);
}

MainWindow::~MainWindow()
{

}

void MainWindow::onInputMaskSel(bool checked)
{
    if(checked)
    {
        validatorWidget->hide();
        inputMaskWidget->show();
    }

}

void MainWindow::onValidatorSel(bool checked)
{
    if(checked)
    {
        inputMaskWidget->hide();
        validatorWidget->show();
    }

}
