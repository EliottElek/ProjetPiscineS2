#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <fstream>
#include <sstream>
#include <iostream>
#include<stdio.h>
#include <vector>
#include "svgfile.h"
#include "sommet.h"
#include "arete.h"

class Graphe
{
private :
    int m_ordre, m_taille ;
    std::vector <sommet*> m_sommets ;
    std::vector <arete*> m_aretes;
    std::vector <int> m_voisins ;

public :
    Graphe (int ordre, int taille);
    Graphe(std::string nomFichier, std::string nomFichier2, std::vector<sommet*>&sommet, std::vector <arete*>& arete);
    void drawSommet(Svgfile& h, int x, int y, int r, std::string id);
    void drawArcs(Svgfile& h, int x1, int y1, int x2, int y2);

    float nbdegre (std::vector <arete*>& arete, int numsommet);
    void centraldegrenonnormal (std::vector <arete*>& arete, int numsommet);
    void centraldegrenormal (std::vector <arete*>& arete, int numsommet);
    void centralvecteurpropre (std::vector <arete*>& arete, int numsommet);
    std::vector <int> getvoisin(std::vector <arete*>& arete, int numsommet);
    void drawPoids(Svgfile& h, int x1, int y1, int x2, int y2, int poids);

};


#endif // GRAPHE_H_INCLUDED

