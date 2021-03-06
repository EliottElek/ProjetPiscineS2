#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <string>
#include "sommet.h"
#include "svgfile.h"
class arete
{
private :
    int m_numero;
    std:: string m_color;
    sommet* m_sommet1;
    sommet* m_sommet2;
    int m_id;
    float m_poids;

public:

    arete (int numero,std:: string color,sommet* sommet1, sommet* sommet2,int id, float poids);
    ~arete();
    void dessiner(Svgfile&svgout);
    void dessinerFleche(Svgfile&svgout,bool plein);
    int getnum ()const;
    sommet* getsommet1();
    sommet* getsommet2();
    int getid()const;
    float getpoids()const;
    void setpoids(float poids);
};

#endif // ARETE_H_INCLUDED
