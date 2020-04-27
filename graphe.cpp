#include "graphe.h"
#include "sommet.h"
#include "arete.h"

Graphe :: Graphe(std::string nomFichier, std::string nomFichier2, std::vector<sommet*>&tabsommet)
{
    std::vector <std::string> id;
    int oriente, ordre, numsommet, x, y, taille, idarete, sommet1, sommet2, taille2, idarete2, poids ;
    std::string idsommet;
    std::istringstream iss;
    std::string strvalues ;
    std::ifstream ifs(nomFichier);  // on ouvre en lecture
    std::ifstream ifs2 (nomFichier2);
    if (!ifs)
    {
        throw std::runtime_error {"Impossible d'ouvrir le fichier"};
    }
    if (!ifs2)
    {
        throw std::runtime_error {"Impossible d'ouvrir le fichier"};
    }
    ifs >> oriente;
    ifs >> ordre;
    std::cout << "Ouverture des 2 fichiers:" << std::endl ;
    if (oriente ==0)
    {
        std::cout << "Orientation: non oriente"<< std::endl;
    }
    else
    {
        std::cout << "Orientation : oriente" << std::endl;
    }

    std::cout << "Il y'a " << ordre<<" sommets" << std::endl ;
    for (int i=2; i<ordre+2; i++)
    {
        ifs >> numsommet;
        std::cout << "Num sommet : " << numsommet;
        ifs >> idsommet;
        std::cout << " Idsommet : " << idsommet;
        ifs >> x;
        std::cout << " x : " << x;
        ifs >> y ;
        std::cout << " y : " << y << std::endl;
        tabsommet.push_back(new sommet(i,"blue",x,y,idsommet));
    }
    ifs >> taille;
    std::cout << " Taille :" << taille << std::endl;
    for (int j=ordre+4 ; j<ordre+4+taille; j++)
    {
        ifs >> idarete;
        std::cout << "Idarete : " << idarete;
        ifs >> sommet1;
        std::cout << " Sommet1 : " << sommet1;
        ifs >> sommet2;
        std::cout << " Sommet2 : " << sommet2 << std::endl;
    }

    ifs2 >> taille2;
    std::cout << std::endl;
    for (int i=1; i<taille+1; i++)
    {
        ifs2 >> idarete2 ;
        std :: cout << "Poids de l'arete " << idarete2 << " :" ;
        ifs2 >> poids;
        std::cout << poids << std::endl;

    }
}

//void Graphe:: draw(Svgfile& h, int x, int y, int r, std::string id, int sommet1, int sommet2)
void Graphe:: draw(Svgfile& h, int x, int y, int r, std::string id)
{
    h.addDisk(x, y,  r, "red");
    h.addText(x, y-10, id, "red");
//    h.addLine(sommet1.getx(), sommet1.gety(), sommet2.getx(), sommet2.gety(), "red");
}
