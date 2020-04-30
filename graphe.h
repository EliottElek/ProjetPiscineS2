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
    std::string m_nomFichier;
    std::string m_nomFichier2;
    bool m_pondere= false;

public :
    Graphe();
    Graphe(std::string nomFichier, std::string nomFichier2, bool pondere);
    void dessiner();
    void supparete(int numero);
    std::vector <sommet*> gettabsommets() ;
    std::vector <arete*> gettabaretes();
    void setFichier1(std::string fichier);
    void setFichier2(std::string fichier);
    void setpondere(int valeur);
    int Dijkstra(int id_initial,int id_final);
    float nbdegre (int numsommet);
    float centraldegrenonnormal (int numsommet);
    float centraldegrenormal (int numsommet);
    std::vector <float>  centralvecteurpropre ();
    int getnbvoisin (int numsommet);
};


#endif // GRAPHE_H_INCLUDED
