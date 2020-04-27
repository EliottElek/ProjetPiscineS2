#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <string>

class arete
{
private :

    int m_numero;
    std:: string m_color;
    int m_sommet1, m_sommet2;
    int m_id;
    int m_poids;

public:

    arete (int numero,std:: string color,int sommet1,int sommet2,int id, int poids);
    ~arete();

    int getnum ()const;
    int getsommet1 ()const;
    int getsommet2() const;
    int getid()const;
    int getpoids()const;



};

#endif // ARETE_H_INCLUDED
