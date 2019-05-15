#include "serial_control.h"

void Serial_Control::appendToList(QPointF point)  // fonction ajout des point dans la liste
{
    m_listOfPoint.append(point);
    if(m_listOfPoint.size()>=200)                    // selection de la la taille de la liste de point ici 20
    {
        emit sendList();                            // envoi du signal sendlist
    }
}

Serial_Control::Serial_Control() // constructeur
{
    m_serie = new C_Serie(this);    // création d'un nouvel objet C_Serie dans serial_control

    connect(m_serie ,&C_Serie::sendData ,this ,&Serial_Control::stockData); // connection entre le signal sendData de C_Serie et le slots stockdata
                                                                            // pour reception du signal envoyé depuis C_Serie
}

Serial_Control::~Serial_Control(){ // destructeur
    delete m_serie;
}

QList<QPointF> Serial_Control::getListOfPoint() // fonction geter
{
    QList<QPointF> tmpList;
    while(!m_listOfPoint.isEmpty())
    {
        tmpList.append(m_listOfPoint.takeAt(0));        // raz de listeofpoint et stockage dans tmplist
    }
    const_data_x = 0;                                   // raz de notre conteur en x
    return tmpList;     // renvoi de la liste de points
}

void Serial_Control::stockData()    // Fonction conversion/stockage
{
    qreal conv_strToFloat;
    conv_strToFloat = atof (m_serie->getData); // conversion char en float
    pointf.setY(conv_strToFloat);              // on fixe la valeur en y avec la donnée que l'on reçoi ici on partira
    pointf.setX(const_data_x + 1);               // du principe que l'envoie de la donnéé depuis la STM32 n'est que en y
    const_data_x ++;                             // incrémentation de x
    appendToList(pointf);
}

