#include "affichage.h"


Affichage::Affichage(QWidget *parent)
{
    Slider *slider = new Slider;
    QGridLayout *qgl_instance = new QGridLayout;
    qgl_instance->addWidget(grille, 0, 0, 18, 1);
    qgl_instance->addWidget(slider, 0, 1, 1, 1);
    setLayout(qgl_instance);

    connect(slider, SIGNAL(ZoomXChanged(int)), grille, SLOT(ChangeZoom_X(int)));
    connect(slider, SIGNAL(ZoomYChanged(int)), grille, SLOT(ChangeZoom_Y(int)));
    connect(slider, SIGNAL(ScrollXChanged(int)), grille, SLOT(Scroll_X(int)));
    connect(slider, SIGNAL(TriggerChanged(int)), grille, SLOT(ChangeTrigger(int)));
    connect(slider, SIGNAL(CheckBox_trigger(bool)), grille, SLOT(CheckBox_trigger(bool)));
    connect(m_serial_c, &Serial_Control::sendList, this, &Affichage::addListToDraw);

}

Affichage::~Affichage()
{
    delete m_serial_c;
}

void Affichage::drawPoints(QList<QPointF> list)
{
    grille->AddPoint(list);
}

void Affichage::addListToDraw()
{
   drawPoints(m_serial_c->getListOfPoint());
}



