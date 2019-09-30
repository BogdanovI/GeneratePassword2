#include "mainwindow.h"
#include "passwordassembly.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *verticalMain = new QVBoxLayout;
    QHBoxLayout *horizontal = new QHBoxLayout;

    horizontal->addWidget(Icon());
    horizontal->addWidget(generatePasswordBox());
    horizontal->addWidget(settingsBox());
    verticalMain->addLayout(horizontal);
    verticalMain->addWidget(StatBar());
    setLayout(verticalMain);
    setWindowIcon(QIcon("C:/Users/79992/Desktop/key.png"));
    setWindowTitle("Generate random password");

    resize(490, 200);
}

QGroupBox *MainWindow::generatePasswordBox()
{
    GeneratePasswordGroupBox = new QGroupBox(tr("Generate password"));

    OutputsPassword = new QLineEdit();
    GeneratePassword = new QPushButton("Generate password");
    QSpacerItem *space = new QSpacerItem(0, 30);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addSpacerItem(space);
    vbox->addWidget(OutputsPassword);
    vbox->addWidget(GeneratePassword);
    vbox->addStretch(1);

    GeneratePasswordGroupBox->setLayout(vbox);
    connect(GeneratePassword, SIGNAL(clicked()), this, SLOT(onClicked_GeneratePassword()));

    return GeneratePasswordGroupBox;
}

QGroupBox *MainWindow::settingsBox()
{
    SettingsGroupBox = new QGroupBox("Settings");
    QuantityPassSymbol = new QSpinBox;
    QuantitySlider = new QSlider(Qt::Horizontal);

    QLabel *QuantityLable = new QLabel("Quantity");
    QHBoxLayout *hbox = new QHBoxLayout;

    QuantityPassSymbol->setFixedSize(131, 20);
    QuantityPassSymbol->setRange(3, 15);
    QuantityPassSymbol->setValue(3);
    QuantitySlider->setTickInterval(1);
    QuantitySlider->setRange(3, 15);
    QuantitySlider->setValue(3);

    hbox->addWidget(QuantityLable);
    hbox->addWidget(QuantityPassSymbol);

    hbox->addStretch(1);

    UpperCheck = new QCheckBox("Use uppercase letter");
    NumberCheck = new QCheckBox("Use numbers");

    QVBoxLayout *vbox = new QVBoxLayout;

    vbox->addLayout(hbox);
    vbox->addWidget(QuantitySlider);
    vbox->addWidget(UpperCheck);
    vbox->addWidget(NumberCheck);

    vbox->addStretch(1);
    SettingsGroupBox->setLayout(vbox);

    connect(QuantitySlider, SIGNAL(valueChanged(int)), QuantityPassSymbol, SLOT(setValue(int)));
    connect(QuantityPassSymbol, SIGNAL(valueChanged(int)), QuantitySlider, SLOT(setValue(int)));

    return SettingsGroupBox;
}

QLabel *MainWindow::Icon()
{
    IconLabel = new QLabel;
    QPixmap imageIcon;
    imageIcon.load("C:/Users/79992/Desktop/lock.png");
    IconLabel->setPixmap(imageIcon);
    return IconLabel;
}

QStatusBar *MainWindow::StatBar()
{
    StatusProgramm = new QStatusBar;
    status = new QLabel("Choose parameters and generate a new password");
    StatusProgramm->addWidget(status);
    return StatusProgramm;
}
MainWindow::~MainWindow()
{
}

void MainWindow::onClicked_GeneratePassword()
{
    PasswordAssembly newPassword(QuantityPassSymbol->value(), UpperCheck->checkState(), NumberCheck->checkState());
    OutputsPassword->setText(newPassword.AssemblyNewPassword());
    status->setText("New password generated");
}
