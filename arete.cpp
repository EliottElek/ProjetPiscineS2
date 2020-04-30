#include "arete.h"
#include "sommet.h"
#include "svgfile.h"
arete::arete(int numero,std:: string color,sommet* sommet1,sommet* sommet2,int id, int poids):m_numero {numero},m_color {color},m_sommet1 {sommet1},m_sommet2 {sommet2},m_id {id},m_poids {poids}
{}
arete::~arete()
{}
void arete::dessiner(Svgfile&svgout)
{
    svgout.addLine((m_sommet1->getx())*175,(m_sommet1->gety())*80,(m_sommet2->getx())*175,(m_sommet2->gety())*80,"blue");
    int xpoids = (m_sommet1->getx()*175+m_sommet2->getx()*175)/2;
    int ypoids = (m_sommet1->gety()*80+m_sommet2->gety()*80)/2;
    svgout.addText(xpoids, ypoids, m_poids, "lightgreen");
    svgout.addText(xpoids, ypoids+20, m_id, "red");
}
int arete :: getnum ()const
{
    return m_numero;
}
sommet* arete:: getsommet1 ()
{
    return m_sommet1;
}
sommet* arete::getsommet2()
{
    return m_sommet2;
}
int arete::getid()const
{
    return m_id;
}
int arete::getpoids()const
{
    return m_poids;
}

int arete::getx ()const
{
    return m_x;
}
int arete::gety() const
{
    return m_y;
}
void arete::setpoids(int poids)
{
    m_poids = poids;
}
