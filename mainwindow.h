#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QObject>
#include <QSpinBox>
#include <QtWidgets>


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void changeRed();
    void changeGreen();
    void changeBlue();

private:
    void changeLabelColor(QLabel *label, int red, int green, int blue);
    void changeBackgroundColor(int red, int green, int blue);

    QSpinBox spinboxRed;
    QSpinBox spinboxGreen;
    QSpinBox spinboxBlue;
    QLabel  labelRed;
    QLabel  labelGreen;
    QLabel  labelBlue;
};
#endif // MAINWINDOW_H
