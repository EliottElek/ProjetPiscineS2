#include "arete.h"

  arete::arete (int numero,std:: string color,int sommet1,int sommet2,int id, int poids)
  {
      m_numero = numero;
      m_color = color;
      m_sommet1 = sommet1;
      m_sommet2 = sommet2;
      m_poids = poids;
  }
arete::~arete()
{

}

    int arete :: getnum ()const
    {
        return m_numero;
    }
    int arete:: getsommet1 ()const
    {
        return m_sommet1;
    }
    int arete::getsommet2() const
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
