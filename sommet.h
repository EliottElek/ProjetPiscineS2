#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <string>
#include "svgfile.h"
#include <vector>

class sommet
{
private :

    int m_numero;
    std:: string m_color;
    int m_x,m_y;
    std::string m_id;
    std::vector <std::pair<sommet*,int>> m_adjacents;

public:

    sommet (int numero,std:: string color,int x,int y,std::string id);
    ~sommet();
    sommet ();
    void Ajouter_adj(sommet* adj,int poids);
    void afficher();
    std::vector <std::pair<sommet*,int>> getAdj() const;
    void ajouterPoidsadjacents(int i, int poids);
    void Supprimer_adj(sommet*adj);
    void dessiner(Svgfile&svgout);
    int getnum ()const;
    int getx ()const;
    int gety() const;
    std::string getid()const;
    void setx (int x);
    void sety(int y);
    void init(unsigned int sommet);





};


#endif // SOMMET_H_INCLUDED
