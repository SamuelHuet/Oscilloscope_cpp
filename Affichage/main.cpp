
#include "affichage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //-------------------------------- fake data
    QList<QPointF> list;
    //list.append(QFPointF(temps, volt));
    for(int i=0; i<700; i++){
        list.append(QPointF(i*10,100*sin(i)));
    }
    //--------------------------------

    Affichage w;
    w.show();

    w.drawPoints(list);

    return a.exec();
}
