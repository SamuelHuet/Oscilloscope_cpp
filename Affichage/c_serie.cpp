#include "c_serie.h"
#include <QDebug>

C_Serie::C_Serie(QObject *parent)
    : QObject(parent) {

    m_serial=new QSerialPort(this);
    m_serial->setPortName("/dev/ttyUSB0");
    m_serial->setBaudRate(QSerialPort::Baud115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    if(!m_serial->open(QIODevice::ReadOnly)) {
        qDebug() <<QObject::tr("Je ne peux pas ouvrir le port série %1...").arg(m_serial->portName());
    }
    connect(m_serial,static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),this,&C_Serie::handleError);
    connect(m_serial,&QSerialPort::readyRead,this,&C_Serie::readData);
}

C_Serie::~C_Serie(){
    m_serial->close();
    delete m_serial;
}

void C_Serie::handleError(QSerialPort::SerialPortError error) {
    if(error==QSerialPort::ResourceError) {
        qDebug() << QObject::tr("Erreur critique : %1").arg(m_serial->errorString());
    }
}

QString C_Serie::readData() {
    getData.clear();
    QByteArray buf = m_serial->readAll();       // Lecture du port
    QString data = buf;                         // stockage et converstion d'un QByteArrray vers un QString
    for(int i=0; i<data.size(); i++) {          // on parcour tout le buffer data
        if(data.at(i)!='\n'){                   // si ce n'est pas le caractère '\n'
            getData.append(buf.at(i));          // on rajoute le caractère en question à getData
        }
        if(data.at(i)=='\n')                    // si l'on a le caractère '/n'
        {
           emit sendData();                     // envoi du signal senData pour receptionner la donné dans l'objet suivant
        }

    }
return getData;                     // renvoi de getData
}






