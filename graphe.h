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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    Graphe(std::string nomFichier, std::string nomFichier2, std::vector<sommet*>&sommet);
    void draw(Svgfile& h, int x, int y, int r);
=======
    Graphe(std::string nomFichier, std::string nomFichier2, Svgfile& h);
    void draw(Svgfile& h);
>>>>>>> 7125b530c4e16f36fe5bd6c9b401b135ec1d5a61
=======
    Graphe(std::string nomFichier, std::string nomFichier2);
    void draw(Svgfile& h, std::vector <sommet*> sommet);
>>>>>>> parent of e92582c... update
=======
    Graphe(std::string nomFichier, std::string nomFichier2);
    void draw(Svgfile& h, std::vector <sommet*> sommet);
>>>>>>> parent of e92582c... update
};


#endif // GRAPHE_H_INCLUDED
