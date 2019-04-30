#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QWidget>
#include <QGridLayout>
#include <QApplication>
#include <QList>
#include <QPointF>
#include "grille.h"
#include "slider.h"

class Affichage : public QWidget
{
    Q_OBJECT
private:
    Grille *grille = new Grille;
public:
    Affichage(QWidget *parent = 0);
    ~Affichage();
    void drawPoints(QList<QPointF>);

};

#endif // AFFICHAGE_H
