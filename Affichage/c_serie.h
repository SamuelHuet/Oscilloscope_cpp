#ifndef C_SERIE_H
#define C_SERIE_H
#include <QtSerialPort/QSerialPort>
#include <QWidget>
#include <QObject>
#include <QString>


class C_Serie : public QObject
{
Q_OBJECT
private:
    QSerialPort *m_serial;

public:
    explicit C_Serie(QObject *parent = nullptr);
    ~C_Serie();
    QByteArray getData;

signals:
    void sendData();

public slots:
    void handleError(QSerialPort::SerialPortError error);
    QString readData();

};

#endif // C_SERIE_H







