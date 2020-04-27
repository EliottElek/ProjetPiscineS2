///Projet piscine de Capucine Plantecoste, Subeshan Koneswaran, Eliott Morcillo
///Projet de la semaine du 27/04/2020
#include "graphe.h"
#include "couleur.h"
#include"svgfile.h"
#include "sommet.h"



int main()
{
    std::vector<sommet*> tabsommet;
    Graphe g{"fichier1.txt", "fichier2.txt",tabsommet};
    Svgfile svgout;
    for(unsigned int i = 0; i < tabsommet.size(); i++)
    //std::cout<<"Sommet"<<i+1<<"x :"<<tabsommet[i]->getx()<<"y :"<<tabsommet[i]->gety()<<std::endl;
        g.draw(svgout, tabsommet[i]->getx()*175, tabsommet[i]->gety()*80, 2);

    return 0;
}
