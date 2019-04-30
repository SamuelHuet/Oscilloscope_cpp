#ifndef GRILLE_H
#define GRILLE_H
#define LARGEUR 700
#define HAUTEUR 500
#define UNITE 25
#include <QWidget>
#include <QtGui>
#include <QPainter>
#include <QPen>
#include <QList>

class Grille : public QWidget
{
    Q_OBJECT

private:
    static const int m_largeur = LARGEUR, m_hauteur = HAUTEUR, m_unite = UNITE;
    //QPointF coo(int, int);
    QList<QPointF> m_newpoint;
    float m_zoom_y = 1, m_zoom_x = 1;
    int m_scroll_x = 0;
    int m_triggerlevel = 0;
    bool m_check_trigger = false;

public:
    explicit Grille(QWidget *parent = 0);
    ~Grille();
    void AddPoint(QList<QPointF>);
public slots:
    void ChangeZoom_Y(int zoom_y);
    void ChangeZoom_X(int zoom_x);
    void Scroll_X(int scroll_x);
    void ChangeTrigger(int y);
    void CheckBox_trigger(bool);

protected:
    void paintEvent(QPaintEvent *);
};

#endif // GRILLE_H
