#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QWidget>
#include <QGridLayout>
#include <QApplication>
#include <QList>
#include <QPointF>
#include "grille.h"
#include "slider.h"
#include "serial_control.h"

class Affichage : public QWidget
{
    Q_OBJECT
private:
    Grille *grille = new Grille;
    Serial_Control *m_serial_c = new Serial_Control;
public:
    Affichage(QWidget *parent = 0);
    ~Affichage();
    void drawPoints(QList<QPointF>);

public slots:
    void addListToDraw();

};

#endif // AFFICHAGE_H
