#ifndef SLIDER_H
#define SLIDER_H
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QGridLayout>
#include <QApplication>
#include <qlcdnumber.h>
#include <QCheckBox>

class Slider : public QWidget
{
    Q_OBJECT
public:
    Slider(QWidget *parent = 0);
    ~Slider();
signals:
    void valueChanged(int);
    void ZoomXChanged(int);
    void ZoomYChanged(int);
    void ScrollXChanged(int);
    void TriggerChanged(int);
    void CheckBox_trigger(bool);
};

#endif // SLIDER_H
