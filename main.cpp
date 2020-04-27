///Projet piscine de Capucine Plantecoste, Subeshan Koneswaran, Eliott Morcillo
///Projet de la semaine du 27/04/2020
#include "graphe.h"
#include "couleur.h"
#include"svgfile.h"
#include "sommet.h"



int main()
{
    std::vector <sommet*> sommet;
    Graphe g{"fichier1.txt", "fichier2.txt"};
    Svgfile svgout;
    g.draw(svgout, sommet);


    return 0;
}
