#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCheckBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSlider>
#include <QSpacerItem>
#include <QSpinBox>
#include <QStatusBar>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onClicked_GeneratePassword();

private:
    QGroupBox *generatePasswordBox();
    QGroupBox *settingsBox();
    QLabel *Icon();
    QStatusBar *StatBar();

    QGroupBox *SettingsGroupBox;
    QLabel *QuantityLable;
    QSpinBox *QuantityPassSymbol;
    QSlider *QuantitySlider;

    QGroupBox *GeneratePasswordGroupBox;
    QLineEdit *OutputsPassword;
    QPushButton *GeneratePassword;

    QCheckBox *UpperCheck;
    QCheckBox *NumberCheck;

    QStatusBar *StatusProgramm;
    QLabel *status;
    QLabel *IconLabel;
};
#endif // MAINWINDOW_H
