///Projet piscine de Capucine Plantecoste, Subeshan Koneswaran, Eliott Morcillo
///Projet de la semaine du 27/04/2020
#include "graphe.h"
#include "couleur.h"
#include"svgfile.h"
#include "sommet.h"
#include "arete.h"



int main()
{
    std::vector<sommet*> tabsommet;
    std::vector <arete*> tabarete;
    Graphe g{"fichier1.txt", "fichier2.txt",tabsommet, tabarete};
    Svgfile svgout;
    for(unsigned int i = 0; i < tabsommet.size(); i++)
    {
        std::cout<<"Sommet"<<i<<" x: "<<tabsommet[i]->getx()<<" y: "<<tabsommet[i]->gety()<<std::endl;
        g.drawSommet(svgout, tabsommet[i]->getx()*175, tabsommet[i]->gety()*80, 2, tabsommet[i]->getid());
    }
    for(unsigned int j = 0; j < tabarete.size(); j++)
    {
        std::cout<<"il existe une arete entre le sommet "<<tabarete[j]->getsommet1()<<" et le sommet "<<tabarete[j]->getsommet2()<<std::endl;
        g.drawArcs(svgout, (tabsommet[tabarete[j]->getsommet1()])->getx()*175,(tabsommet[tabarete[j]->getsommet1()])->gety()*80,(tabsommet[tabarete[j]->getsommet2()])->getx()*175,(tabsommet[tabarete[j]->getsommet2()])->gety()*80);

    }
    return 0;
}
