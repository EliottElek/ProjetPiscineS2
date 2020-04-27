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
    int m_ordre, m_taille;
    std::vector <sommet*> m_sommets ;
    std::vector <arete*> m_aretes;

public :
    Graphe(std::string nomFichier, std::string nomFichier2, std::vector<sommet*>&sommet, std::vector <arete*>& arete);
    void draw(Svgfile& h, int x, int y, int r, std::string id,int sommet1, int sommet2);
    //void draw(Svgfile& h, int x, int y, int r, std::string id);
};


#endif // GRAPHE_H_INCLUDED
