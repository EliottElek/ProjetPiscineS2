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
    bool m_orientation=false;
    bool m_connexite =true;
    bool m_flechePleine=true;

public :
    Graphe();
    Graphe(std::string nomFichier, std::string nomFichier2, bool pondere);
    void dessiner();
    void supparete(int numero);
    int getordre();
    void setconnexite(int valeur);
    std::vector <sommet*> gettabsommets() ;
    std::vector <arete*> gettabaretes();
    void setFichier1(std::string fichier);
    void setFichier2(std::string fichier);
    void setpondere(int valeur);
    bool getOrientation();
    std::vector<int>BFS(int id_initial);
    int Dijkstra(int id_initial,int id_final);
    std::vector <int> Dijkstra2(int id_initial,int id_final);
    float nbdegre (int numsommet);
    void setflechePleine(int valeur);
    void changerponderation(std::string fichier);
    float centraldegrenonnormal (int numsommet);
    float centraldegrenormal (int numsommet);
    std::vector <float>  centralvecteurpropre (int numsommet);
    int getnbvoisin (int numsommet);
    float centraldeproximitenonnormalise(int numsommet);
    float centraldeproximitenormalise(int numsommet);
    float centraliteintermediaritenonnormalise (int numsommet);
};


#endif // GRAPHE_H_INCLUDED
