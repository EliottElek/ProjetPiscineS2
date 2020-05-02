#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <string>
#include "sommet.h"
#include "svgfile.h"
class arete
{
private :

    int m_x, m_y;
    int m_numero;
    std:: string m_color;
    sommet* m_sommet1;
    sommet* m_sommet2;
    int m_id;
    int m_poids;

public:

    arete (int numero,std:: string color,sommet* sommet1, sommet* sommet2,int id, int poids);
    ~arete();
    void dessiner(Svgfile&svgout);
    void dessinerFleche(Svgfile&svgout,bool plein);
    int getnum ()const;
    sommet* getsommet1();
    sommet* getsommet2();
    int getid()const;
    int getpoids()const;
    int getx()const;
    int gety()const;
    void setpoids(int poids);



};

#endif // ARETE_H_INCLUDED
