#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent){

    setWindowTitle("RGBMixer");
    setFixedSize(500,300);

    QVBoxLayout * v_box         = new QVBoxLayout();
    QHBoxLayout * h_box_red     = new QHBoxLayout();
    QHBoxLayout * h_box_green   = new QHBoxLayout();
    QHBoxLayout * h_box_blue    = new QHBoxLayout();

    labelRed.setText("RED");
    labelRed.setAutoFillBackground(true);
    spinboxRed.setMaximum(255);
    spinboxRed.setValue(155);

    h_box_red->addWidget(&labelRed);
    h_box_red->addWidget(&spinboxRed);

    labelGreen.setText("GREEN");
    labelGreen.setAutoFillBackground(true);
    spinboxGreen.setMaximum(255);
    spinboxGreen.setValue(155);

    h_box_green->addWidget(&labelGreen);
    h_box_green->addWidget(&spinboxGreen);

    labelBlue.setText("BLUE");
    labelBlue.setAutoFillBackground(true);
    spinboxBlue.setMaximum(255);
    spinboxBlue.setValue(155);

    h_box_blue->addWidget(&labelBlue);
    h_box_blue->addWidget(&spinboxBlue);

    v_box->addLayout(h_box_red);
    v_box->addLayout(h_box_green);
    v_box->addLayout(h_box_blue);

    setLayout(v_box);

    changeBackgroundColor(spinboxRed.value(), spinboxGreen.value(), spinboxBlue.value());
    changeLabelColor(&labelRed, spinboxRed.value(), 0, 0);
    changeLabelColor(&labelGreen, 0, spinboxGreen.value(), 0);
    changeLabelColor(&labelBlue, 0, 0, spinboxBlue.value());

    connect(&spinboxRed,    SIGNAL(editingFinished()), this, SLOT(changeRed()));
    connect(&spinboxGreen,  SIGNAL(editingFinished()), this, SLOT(changeGreen()));
    connect(&spinboxBlue,   SIGNAL(editingFinished()), this, SLOT(changeBlue()));

    Q_UNUSED(parent);
}

void MainWindow::changeRed(){
    changeBackgroundColor(spinboxRed.value(), spinboxGreen.value(), spinboxBlue.value());
    changeLabelColor(&labelRed, spinboxRed.value(), 0, 0);
}

void MainWindow::changeGreen(){
    changeBackgroundColor(spinboxRed.value(), spinboxGreen.value(), spinboxBlue.value());
    changeLabelColor(&labelGreen, 0, spinboxGreen.value(), 0);
}

void MainWindow::changeBlue(){
    changeBackgroundColor(spinboxRed.value(), spinboxGreen.value(), spinboxBlue.value());
    changeLabelColor(&labelBlue, 0, 0, spinboxBlue.value());
}

void MainWindow::changeLabelColor(QLabel *label, int red, int green, int blue){
    int textColour = 255*(1-(red+green+blue)/155);
    label->setStyleSheet(QString("background-color: " + QColor(red, green, blue).name()
                                 + "; color: " + QColor(textColour,textColour,textColour).name()
                                 ));
}
void MainWindow::changeBackgroundColor(int red, int green, int blue){
    int textColour = 255*(1-((red+green+blue)/2)/155);
    this->setStyleSheet(QString("background-color: " + QColor(red, green, blue).name()
                                + "; color: " + QColor(textColour,textColour,textColour).name()
                                ));
}
