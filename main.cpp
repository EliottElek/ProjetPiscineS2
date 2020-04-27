///Projet piscine de Capucine Plantecoste, Subeshan Koneswaran, Eliott Morcillo
///Projet de la semaine du 27/04/2020
#include "graphe.h"
#include "couleur.h"
#include"svgfile.h"



int main()
{
    Graphe g{"fichier1.txt", "fichier2.txt"};
    Svgfile svgout;
    g.draw(svgout);


    return 0;
}
