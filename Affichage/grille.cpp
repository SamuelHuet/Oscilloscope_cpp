#include "grille.h"

/*QPointF Grille::coo(int x, int y)
{
    return QPointF(x*m_unite, y*m_unite);
}*/

Grille::Grille(QWidget *parent): QWidget(parent)
{
    setFixedSize(m_largeur+1, m_hauteur+1);

}

Grille::~Grille()
{

}

void Grille::AddPoint(QList<QPointF> points)
{
    m_newpoint = points;
    update();
}

void Grille::ChangeZoom_Y(int zoom_y)
{
    m_zoom_y = (float)zoom_y/10;
    update();
}

void Grille::ChangeZoom_X(int zoom_x)
{
    m_zoom_x = (float)zoom_x/10;
    update();
}

void Grille::Scroll_X(int x)
{
    m_scroll_x = x;
    update();
}

void Grille::ChangeTrigger(int y)
{
    m_triggerlevel = y ;
    update();
}

void Grille::CheckBox_trigger(bool value)
{
    m_check_trigger = value;
    int ecartement = m_newpoint[1].rx() - m_newpoint[0].rx();
    m_scroll_x=-(m_newpoint.size()/2)*ecartement;
    update();
}

void Grille::paintEvent(QPaintEvent *)
{
    QPainter grille(this);

    //-------------------------------------------------------------------- Draw grid
    QPen myPen(Qt::gray);
    grille.setPen(myPen);
    grille.translate(m_largeur/2, m_hauteur/2);

    for(int i=0; i<=m_largeur/2; i+=m_unite*m_zoom_x){
        grille.drawLine(QPointF(i, -m_hauteur), QPointF(i, m_hauteur));
    }
    for(int i=0; i>=-m_largeur/2; i-=m_unite*m_zoom_x){
        grille.drawLine(QPointF(i, -m_hauteur), QPointF(i, m_hauteur));
    }
    for(int i=0; i<=m_hauteur/2; i+=m_unite*m_zoom_y){
        grille.drawLine(QPointF(-m_largeur, i), QPointF(m_largeur, i));
    }
    for(int i=0; i>=-m_hauteur/2; i-=m_unite*m_zoom_y){
        grille.drawLine(QPointF(-m_largeur, i), QPointF(m_largeur, i));
    }

    //-------------------------------------------------------------------- Draw Trigger
    myPen.setColor(Qt::green);
    myPen.setWidth(2);
    grille.setPen(myPen);
    grille.drawLine(QPointF(-m_largeur/2, -m_triggerlevel* m_zoom_y), QPointF(m_largeur/2, -m_triggerlevel* m_zoom_y));

    //-------------------------------------------------------------------- Draw origin
    myPen.setColor(Qt::black);
    myPen.setWidth(2);
    grille.setPen(myPen);
    grille.drawLine(QPointF(0, -m_hauteur/2), QPointF(0, m_hauteur/2));
    grille.drawLine(QPointF(-m_largeur/2, 0), QPointF(m_largeur/2, 0));
    grille.drawRect(-m_largeur/2+1, -m_hauteur/2+1, m_largeur-1, m_hauteur-1);

    //-------------------------------------------------------------------- Convert Points
    QPointF points[m_newpoint.size()];

    for(int i=0; i<m_newpoint.size(); ++i){
        points[i].setY(m_zoom_y*m_newpoint[i].ry());
        points[i].setX(m_zoom_x*(m_newpoint[i].rx())+m_scroll_x);
    }

    //-------------------------------------------------------------------- Trigger
    QPointF prev = QPointF(0, 0);
    QPointF next = QPointF(0, 0);
    int index_origin;

    if(m_check_trigger){

        for(int i=0; i<m_newpoint.size(); i++){
            if(points[i].rx() >= 0){
                index_origin = i;
                break;
            }
        }

        bool encadrement1, encadrement2, borde;

        for(int i=0; i<1000; i++){
            encadrement1 = (points[index_origin].ry() < (-m_triggerlevel*m_zoom_y) && points[index_origin+1].ry() > (-m_triggerlevel*m_zoom_y));
            encadrement2 = (points[index_origin].ry() > (-m_triggerlevel*m_zoom_y) && points[index_origin+1].ry() < (-m_triggerlevel*m_zoom_y));
            borde = points[index_origin].ry() == (-m_triggerlevel*m_zoom_y) || points[index_origin+1].ry() == (-m_triggerlevel*m_zoom_y);
            if(!(encadrement1 || encadrement2 || borde)){
                index_origin++;
            }else{
                break;
            }
        }

        prev = points[index_origin];
        next = points[index_origin+1];

        m_scroll_x -= prev.rx();

        for(int i=0; i<m_newpoint.size(); ++i){
            points[i].setX(m_zoom_x*(m_newpoint[i].rx())+m_scroll_x);
        }

    }

    //-------------------------------------------------------------------- Draw points
    myPen.setColor(Qt::red);
    myPen.setWidth(2);
    grille.setPen(myPen);

    grille.drawPolyline(points, m_newpoint.size());

    if(m_check_trigger){

        myPen.setColor(Qt::green);
        myPen.setWidth(10);
        grille.setPen(myPen);

        grille.drawPoint(points[index_origin]);
        grille.drawPoint(points[index_origin+1]);
    }

}
