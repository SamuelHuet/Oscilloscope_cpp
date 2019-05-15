#ifndef SERIAL_CONTROL_H
#define SERIAL_CONTROL_H
#include "c_serie.h"
#include <QThread>
#include <QObject>
#include <QDebug>
#include <QList>
#include <QPointF>
#include <stdlib.h>

class Serial_Control : public QObject
{
    Q_OBJECT
private:
    C_Serie *m_serie;
    QList<QPointF> m_listOfPoint;


    void appendToList(QPointF point);

public:
    Serial_Control();
    ~Serial_Control();
    QPointF pointf;
    qreal const_data_x = 0;
    QList<QPointF> getListOfPoint();

signals:
    void sendList();

public slots:
    void stockData();

};

#endif // SERIAL_CONTROL_H







