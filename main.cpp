///Projet piscine de Capucine Plantecoste, Subeshan Koneswaran, Eliott Morcillo
///Projet de la semaine du 27/04/2020
#include "graphe.h"
#include "couleur.h"
#include"svgfile.h"
#include "sommet.h"



int main()
{
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    std::vector<sommet*> tabsommet;
    Graphe g{"fichier1.txt", "fichier2.txt",tabsommet};
    Svgfile svgout;
    for(unsigned int i = 0; i < tabsommet.size(); i++)
    //std::cout<<"Sommet"<<i+1<<"x :"<<tabsommet[i]->getx()<<"y :"<<tabsommet[i]->gety()<<std::endl;
        g.draw(svgout, tabsommet[i]->getx()*175, tabsommet[i]->gety()*80, 2);
=======
    std::vector <sommet*> sommet;

    Svgfile svgout;
    Graphe g{"fichier1.txt", "fichier2.txt", svgout};
    g.draw(svgout);

>>>>>>> 7125b530c4e16f36fe5bd6c9b401b135ec1d5a61
=======
    std::vector <sommet*> sommet;
    Graphe g{"fichier1.txt", "fichier2.txt"};
    Svgfile svgout;
    g.draw(svgout, sommet);

>>>>>>> parent of e92582c... update
=======
    std::vector <sommet*> sommet;
    Graphe g{"fichier1.txt", "fichier2.txt"};
    Svgfile svgout;
    g.draw(svgout, sommet);

>>>>>>> parent of e92582c... update
=======
    std::vector <sommet*> sommet;
    Graphe g{"fichier1.txt", "fichier2.txt"};
    Svgfile svgout;
    g.draw(svgout, sommet);

>>>>>>> parent of e92582c... update

    return 0;
}
